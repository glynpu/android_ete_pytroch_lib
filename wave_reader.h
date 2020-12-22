// Copyright 2019 Mobvoi Inc. All Rights Reserved.
// Author: haowei.li@mobvoi.com (Haowei Li)

// TODO(haowei li):put wave_reader in a common place so that both hotword and
// voiceprint can use it
#ifndef E2E_DEVICE_WAVE_READER_H_
#define E2E_DEVICE_WAVE_READER_H_
#include <cstdint>
#include <iostream>
#include <vector>
#define KALDI_SWAP4(a)                                                   \
  {                                                                      \
    int t = (reinterpret_cast<char*>(&a))[0];                            \
    (reinterpret_cast<char*>(&a))[0] = (reinterpret_cast<char*>(&a))[3]; \
    (reinterpret_cast<char*>(&a))[3] = t;                                \
    t = (reinterpret_cast<char*>(&a))[1];                                \
    (reinterpret_cast<char*>(&a))[1] = (reinterpret_cast<char*>(&a))[2]; \
    (reinterpret_cast<char*>(&a))[2] = t;                                \
  }
#define KALDI_SWAP2(a)                                                   \
  {                                                                      \
    int t = (reinterpret_cast<char*>(&a))[0];                            \
    (reinterpret_cast<char*>(&a))[0] = (reinterpret_cast<char*>(&a))[1]; \
    (reinterpret_cast<char*>(&a))[1] = t;                                \
  }
namespace mobvoi {
namespace voiceprint {
class WaveInfo {
 public:
  WaveInfo()
      : sample_freq_(0),
        sample_count_(0),
        num_channels_(0),
        reverse_bytes_(0) {}
  ~WaveInfo() = default;
  // Is stream size unknown? Duration and SampleCount not valid if true.
  bool IsStreamed() const { return sample_count_ < 0; }
  // Sample frequency, Hz.
  float SampFreq() const { return sample_freq_; }
  // Number of samples in stream. Invalid if IsStreamed() is true.
  uint8_t SampleCount() const { return sample_count_; }
  // Approximate duration, seconds. Invalid if IsStreamed() is true.
  uint32_t Duration() const { return sample_count_ / sample_freq_; }
  // Number of channels, 1 to 16.
  uint32_t NumChannels() const { return num_channels_; }
  // Bytes per sample.
  size_t BlockAlign() const { return 2 * num_channels_; }
  // Wave data bytes. Invalid if IsStreamed() is true.
  size_t DataBytes() const { return sample_count_ * BlockAlign(); }
  // Is data file byte order different from machine byte order?
  bool ReverseBytes() const { return reverse_bytes_; }
  // 'is' should be opened in binary mode. Read() will throw on error.
  // On success 'is' will be positioned at the beginning of wave data.
  void Read(std::istream& is);

 private:
  float sample_freq_;
  uint32_t sample_count_;  // 0 if empty, -1 if undefined length.
  uint8_t num_channels_;
  bool reverse_bytes_;
};
class WaveData {
 public:
  WaveData() : sample_freq_(0.0) {}
  // Read() will throw on error.  It's valid to call Read() more than once--
  // in this case it will destroy what was there before.
  // "is" should be opened in binary mode.
  void Read(std::istream& is);
  // This function returns the wave data-- it's in a matrix
  // becase there may be multiple channels.  In the normal case
  // there's just one channel so Data() will have one row.
  const std::vector<std::vector<float>>& Data() const { return data_; }

 private:
  static const uint32_t kBlockSize = 1024 * 1024;  // Use 1M bytes.
  std::vector<std::vector<float>> data_;
  float sample_freq_;
};
}  // namespace voiceprint
}  // namespace mobvoi
#endif  // E2E_DEVICE_WAVE_READER_H_
