#include <fbank.h>
#include <kaldi_io.h>
// #include <stdint.h>
// #include <sys/types.h>
#include <torch/script.h>
#include <wave_reader.h>
#include <fstream>
#include <iostream>
#include <string>

std::vector<std::string> LoadDict(const std::string& dict_file) {
  // string str;
  // mobvoi::File::ReadFileToString(dict_file, &str);
  // std::vector<std::string> lines;
  // mobvoi::SplitStringToVector(str, "\n", true, &lines);
  // std::vector<std::string> dict(lines.size());
  // for (const auto& line : lines) {
  //   std::vector<std::string> fields;
  //   mobvoi::SplitStringToVector(line, " \t", true, &fields);
  //   CHECK(fields.size() == 2);
  //   int index = StringToInt(fields[1]);
  //   dict[index] = fields[0];
  // }
  // Compiler will do return value optimization automaticly, just return
  // local object, avoid using std::move
  std::ifstream is;
  is.open(dict_file, std::ios::in);
  std::vector<std::string> dict;
  std::string s;
  while (getline(is, s)) {
    // std::cout << s << std::endl;
    std::string delimiter = " ";
    size_t pos = s.find(delimiter);
    std::string key = s.substr(0, pos);
    // std::string index = s.substr(pos + 1, s.size());
    dict.push_back(key);
  }
  return dict;
}

int main(int argc, char* argv[]) {
  // std::string ark = "single_feat.ark";
  // std::string ark = "./feats_cmvn.ark";
  std::string dict_file = "./lang_char.txt";
  std::vector<std::string> dict = LoadDict(dict_file);
  const int eos = dict.size() - 1;
  // for (size_t i = 0; i < dict.size(); ++i) {
  //   std::cout << dict[i] << std::endl;
  // }
  int num_bins = 80, sample_rate = 16000, frame_length = 400, frame_shift = 160;
  Fbank fbank_(num_bins, sample_rate, frame_length, frame_shift);

  // std::ifstream is;
  // is.open(ark, std::ios::in);
  // KaldiMatrix feat;
  // feat.Read(is);
  // std::cout << feat.Data().size() << std::endl;
  // std::cout << feat.Data()[0].size() << std::endl;
  // std::ofstream file("rewrite_single_feat.ark");
  // feat.Write(file);
  //

  // std::string wav_file = "BAC009S0764W0121.wav";
  std::string wav_file = argv[1];
  std::ifstream wav_stream(wav_file);
  mobvoi::voiceprint::WaveData wave_data;
  wave_data.Read(wav_stream);
  // std::vector<int8> waveform(wave_data.Data()[0].size() * 2);
  // for (size_t i = 0; i < wave_data.Data()[0].size(); ++i) {
  //   waveform[i * 2] = static_cast<int16>(wave_data.Data()[0][i]) & 0xff;
  //   waveform[i * 2 + 1] = static_cast<int16>(wave_data.Data()[0][i]) >> 8;
  // }
  // std::vector<float> waves(wave_data.Data()[0].size());
  std::vector<float> waves = wave_data.Data()[0];

  std::vector<float> tmp_fbank;
  int tmp = 0;
  int num_frames = fbank_.Compute(waves, &tmp_fbank);

  std::cout << "tmp_fbank.size(): " << tmp_fbank.size() << std::endl;
  // return 0;

  int beam_size = 1;
  int batch_size = 1;
  int num_rows = tmp_fbank.size() / 80;
  int max_length = num_rows;
  int feat_dim = 80;
  // int max_length = feat.Data().size();
  // int feat_dim = feat.Data()[0].size();
  // std::cout << "feat_dim: " << feat_dim << std::endl;
  std::vector<int> lengths;
  lengths.push_back(max_length);
  torch::Tensor batch_feats =
      torch::zeros({batch_size, max_length, feat_dim}, torch::kFloat);

  // int num_rows = lengths[i];
  for (int i = 0; i < batch_size; i++) {
    for (int j = 0; j < num_rows; j++) {
      for (int col_index = 0; col_index < feat_dim; ++col_index) {
        // batch_feats[i][j][col_index] = feat.Data()[j][col_index];
        batch_feats[i][j][col_index] = tmp_fbank[j * feat_dim + col_index];
      }
      // torch::Tensor row =
      //    torch::from_blob(feat.Data()[j].data(), {feat_dim}, torch::kFloat);
    }
  }
  // std::cout << batch_feats[0] << std::endl;
  std::string model_file = "./final.zip";
  torch::jit::script::Module model = torch::jit::load(model_file);
  model.eval();

  torch::Tensor batch_lengths =
      torch::from_blob(lengths.data(), {lengths.size()}, torch::kInt);
  std::cout << "batch_feats.sizes(): " << batch_feats.sizes() << std::endl;
  std::cout << "batch_lengths.size(): " << batch_lengths.sizes()
            << " batch_lengths: " << batch_lengths << std::endl;
  std::cout << "FLAGS_beam_size: " << beam_size << std::endl;

  torch::jit::IValue output =
      model.run_method("recognize", batch_feats, batch_lengths, beam_size);

  // std::cout << "output: " << output << std::endl;
  torch::Tensor ot = output.toTensor();
  std::cout << "ot.sizes(): " << ot.sizes() << std::endl;
  std::string text;
  for (int j = 0; j < ot[0].size(0); j++) {
    int token_id = ot[0][j].item<int>();
    if (token_id == eos) break;
    text += dict[token_id];
  }
  std::cout << "text: " << text << std::endl;

  return 0;
}
