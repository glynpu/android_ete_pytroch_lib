// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: haowei.li@mobvoi.com (Haowei Li)

#include "wave_reader.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
// #include "base/log.h"
namespace mobvoi {
namespace voiceprint {
struct WaveHeaderReadGofer {
  std::istream& is;
  bool swap;
  char tag[5];
  WaveHeaderReadGofer(std::istream& is) : is(is), swap(false) {
    std::memset(tag, '\0', sizeof tag);
  }
  void Expect4ByteTag(const char* expected) {
    is.read(tag, 4);
    if (is.fail())
      std::cout << "WaveData: expected " << expected
                << ", failed to read anything";
    if (std::strcmp(tag, expected))
      std::cout << "WaveData: expected " << expected << ", got " << tag;
  }
  void Read4ByteTag() {
    is.read(tag, 4);
    if (is.fail())
      std::cout << "WaveData: expected 4-byte chunk-name, got read error";
  }
  uint32_t Readuint32_t() {
    union {
      char result[4];
      uint32_t ans;
    } u;
    is.read(u.result, 4);
    if (swap) KALDI_SWAP4(u.result);
    if (is.fail())
      std::cout << "WaveData: unexpected end of file or read error";
    return u.ans;
  }
  uint16_t ReadUint16() {
    union {
      char result[2];
      int16_t ans;
    } u;
    is.read(u.result, 2);
    if (swap) KALDI_SWAP2(u.result);
    if (is.fail())
      std::cout << "WaveData: unexpected end of file or read error";
    return u.ans;
  }
};
void WaveInfo::Read(std::istream& is) {
  WaveHeaderReadGofer reader(is);
  reader.Read4ByteTag();
  if (std::strcmp(reader.tag, "RIFF") == 0)
    reverse_bytes_ = false;
  else if (std::strcmp(reader.tag, "RIFX") == 0)
    reverse_bytes_ = true;
  else
    std::cout << "WaveData: expected RIFF or RIFX, got " << reader.tag;
#ifdef __BIG_ENDIAN__
  reverse_bytes_ = !reverse_bytes_;
#endif
  reader.swap = reverse_bytes_;
  uint32_t riff_chunk_size = reader.Readuint32_t();
  reader.Expect4ByteTag("WAVE");
  uint32_t riff_chunk_read = 0;
  riff_chunk_read += 4;  // WAVE included in riff_chunk_size.
  // Possibly skip any RIFF tags between 'WAVE' and 'fmt '.
  // Apple devices produce a filler tag 'JUNK' for memory alignment.
  reader.Read4ByteTag();
  riff_chunk_read += 4;
  while (std::strcmp(reader.tag, "fmt ") != 0) {
    uint32_t filler_size = reader.Readuint32_t();
    riff_chunk_read += 4;
    for (uint32_t i = 0; i < filler_size; i++) {
      is.get();  // read 1 byte,
    }
    riff_chunk_read += filler_size;
    // get next RIFF tag,
    reader.Read4ByteTag();
    riff_chunk_read += 4;
  }
  assert(std::strcmp(reader.tag, "fmt ") == 0);
  uint32_t subchunk1_size = reader.Readuint32_t();
  uint16_t audio_format = reader.ReadUint16();
  num_channels_ = reader.ReadUint16();
  uint32_t sample_rate = reader.Readuint32_t(),
           byte_rate = reader.Readuint32_t(), block_align = reader.ReadUint16(),
           bits_per_sample = reader.ReadUint16();
  sample_freq_ = static_cast<float>(sample_rate);
  uint32_t fmt_chunk_read = 16;
  if (audio_format == 1) {
    if (subchunk1_size < 16) {
      std::cout << "WaveData: expect PCM format data to have fmt chunk "
                << "of at least size 16.";
    }
  } else if (audio_format == 0xFFFE) {  // WAVE_FORMAT_EXTENSIBLE
    uint16_t extra_size = reader.ReadUint16();
    if (subchunk1_size < 40 || extra_size < 22) {
      std::cout << "WaveData: malformed WAVE_FORMAT_EXTENSIBLE format data.";
    }
    reader.ReadUint16();    // Unused for PCM.
    reader.Readuint32_t();  // Channel map: we do not care.
    uint32_t guid1 = reader.Readuint32_t(), guid2 = reader.Readuint32_t(),
             guid3 = reader.Readuint32_t(), guid4 = reader.Readuint32_t();
    fmt_chunk_read = 40;
    // Support only KSDATAFORMAT_SUBTYPE_PCM for now. Interesting formats:
    // ("00000001-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_PCM)
    // ("00000003-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
    // ("00000006-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_ALAW)
    // ("00000007-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_MULAW)
    if (guid1 != 0x00000001 || guid2 != 0x00100000 || guid3 != 0xAA000080 ||
        guid4 != 0x719B3800) {
      std::cout << "WaveData: unsupported WAVE_FORMAT_EXTENSIBLE format.";
    }
  } else {
    std::cout << "WaveData: can read only PCM data, format id in file is: "
              << audio_format;
  }
  for (uint32_t i = fmt_chunk_read; i < subchunk1_size; ++i)
    is.get();  // use up extra data.
  if (num_channels_ == 0) std::cout << "WaveData: no channels present";
  if (bits_per_sample != 16)
    std::cout << "WaveData: unsupported bits_per_sample = " << bits_per_sample;
  if (byte_rate != sample_rate * bits_per_sample / 8 * num_channels_)
    std::cout << "Unexpected byte rate " << byte_rate << " vs. " << sample_rate
              << " * " << (bits_per_sample / 8) << " * " << num_channels_;
  if (block_align != num_channels_ * bits_per_sample / 8)
    std::cout << "Unexpected block_align: " << block_align << " vs. "
              << num_channels_ << " * " << (bits_per_sample / 8);
  riff_chunk_read += 4 + subchunk1_size;
  // size of what we just read, 4 for subchunk1_size + subchunk1_size itself.
  // We support an optional "fact" chunk (which is useless but which
  // we encountered), and then a single "data" chunk.
  reader.Read4ByteTag();
  riff_chunk_read += 4;
  // Skip any subchunks between "fmt" and "data".  Usually there will
  // be a single "fact" subchunk, but on Windows there can also be a
  // "list" subchunk.
  while (std::strcmp(reader.tag, "data") != 0) {
    // We will just ignore the data in these chunks.
    uint32_t chunk_sz = reader.Readuint32_t();
    if (chunk_sz != 4 && std::strcmp(reader.tag, "fact") == 0)
      std::cout << "Expected fact chunk to be 4 bytes long.";
    for (uint32_t i = 0; i < chunk_sz; i++) is.get();
    riff_chunk_read +=
        4 + chunk_sz;  // for chunk_sz (4) + chunk contents (chunk-sz)
    // Now read the next chunk name.
    reader.Read4ByteTag();
    riff_chunk_read += 4;
  }
  assert(std::strcmp(reader.tag, "data") == 0);
  uint32_t data_chunk_size = reader.Readuint32_t();
  riff_chunk_read += 4;
  // Figure out if the file is going to be read to the end. Values as
  // observed in the wild:
  bool is_stream_mode =
      riff_chunk_size == 0 || riff_chunk_size == 0xFFFFFFFF ||
      data_chunk_size == 0 || data_chunk_size == 0xFFFFFFFF ||
      data_chunk_size == 0x7FFFF000;  // This value is used by SoX.
  if (is_stream_mode)
    std::cout << "Read in RIFF chunk size: " << riff_chunk_size
              << ", data chunk size: " << data_chunk_size
              << ". Assume 'stream mode' (reading data to EOF).";
  if (!is_stream_mode && std::abs(static_cast<int64_t>(riff_chunk_read) +
                                  static_cast<int64_t>(data_chunk_size) -
                                  static_cast<int64_t>(riff_chunk_size)) > 1) {
    // We allow the size to be off by one without warning, because there is a
    // weirdness in the format of RIFF files that means that the input may
    // sometimes be padded with 1 unused byte to make the total size even.
    std::cout << "Expected " << riff_chunk_size << " bytes in RIFF chunk, but "
              << "after first data block there will be " << riff_chunk_read
              << " + " << data_chunk_size << " bytes "
              << "(we do not support reading multiple data chunks).";
  }
  if (is_stream_mode)
    sample_count_ = -1;
  else
    sample_count_ = data_chunk_size / block_align;
}
void WaveData::Read(std::istream& is) {
  const uint32_t kBlockSize = 1024 * 1024;
  WaveInfo header;
  header.Read(is);
  data_.clear();
  sample_freq_ = header.SampFreq();
  std::vector<char> buffer;
  uint32_t bytes_to_go = header.IsStreamed() ? kBlockSize : header.DataBytes();
  // Once in a while header.DataBytes() will report an insane value;
  // read the file to the end
  while (is && bytes_to_go > 0) {
    uint32_t block_bytes = std::min(bytes_to_go, kBlockSize);
    uint32_t offset = buffer.size();
    buffer.resize(offset + block_bytes);
    is.read(&buffer[offset], block_bytes);
    uint32_t bytes_read = is.gcount();
    buffer.resize(offset + bytes_read);
    if (!header.IsStreamed()) bytes_to_go -= bytes_read;
  }
  if (is.bad()) std::cout << "WaveData: file read error";
  if (buffer.size() == 0) std::cout << "WaveData: empty file (no data)";
  if (!header.IsStreamed() && buffer.size() < header.DataBytes()) {
    std::cout << "Expected " << header.DataBytes() << " bytes of wave data, "
              << "but read only " << buffer.size() << " bytes. "
              << "Truncated file?";
  }
  uint16_t* data_ptr = reinterpret_cast<uint16_t*>(&buffer[0]);
  // The matrix is arranged row per channel, column per sample.
  data_.resize(header.NumChannels());
  for (size_t i = 0; i < data_.size(); ++i) {
    data_[i].resize(buffer.size() / header.BlockAlign());
  }
  for (size_t i = 0; i < data_.size(); ++i) {
    for (size_t j = 0; j < data_[i].size(); ++j) {
      int16_t k = *data_ptr++;
      if (header.ReverseBytes()) KALDI_SWAP2(k);
      data_[i][j] = k;
    }
  }
}
}  // namespace voiceprint
}  // namespace mobvoi
