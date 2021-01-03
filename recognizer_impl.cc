// Copyright 2020 Mobvoi Inc. All Rights Reserved.
// Author: lyguo@mobvoi.com (Liyong Guo)

#include "recognizer_impl.h"
#include <fstream>
#include <iostream>

RecognizerImpl::RecognizerImpl(const std::string& dict_file,
                               const std::string& model_file) {
  LoadDict(dict_file);
  model_ = torch::jit::load(model_file);
  model_.eval();
  int num_bins = 80, sample_rate = 16000, frame_length = 400, frame_shift = 160;
  fbank_extractor_.reset(
      new Fbank(num_bins, sample_rate, frame_length, frame_shift));
}

void RecognizerImpl::LoadDict(const std::string& dict_file) {
  std::ifstream is;
  is.open(dict_file, std::ios::in);
  std::string s;
  while (getline(is, s)) {
    std::string delimiter = " ";
    size_t pos = s.find(delimiter);
    std::string key = s.substr(0, pos);
    dict_.push_back(key);
  }
  eos_ = dict_.size() - 1;
  return;
}

std::string RecognizerImpl::recognize(const std::vector<float> waves) {
  std::vector<float> tmp_fbank;
  int tmp = 0;
  int num_frames = fbank_extractor_->Compute(waves, &tmp_fbank);
  std::cout << "tmp_fbank.size(): " << tmp_fbank.size() << std::endl;
  int beam_size = 1;
  int batch_size = 1;
  int num_rows = tmp_fbank.size() / 80;
  int max_length = num_rows;
  int feat_dim = 80;
  std::vector<int> lengths;
  lengths.push_back(max_length);
  torch::Tensor batch_feats =
      torch::zeros({batch_size, max_length, feat_dim}, torch::kFloat);
  for (int i = 0; i < batch_size; i++) {
    for (int j = 0; j < num_rows; j++) {
      for (int col_index = 0; col_index < feat_dim; ++col_index) {
        batch_feats[i][j][col_index] = tmp_fbank[j * feat_dim + col_index];
      }
    }
  }
  torch::Tensor batch_lengths =
      torch::from_blob(lengths.data(), {lengths.size()}, torch::kInt);
  torch::jit::IValue output =
      model_.run_method("recognize", batch_feats, batch_lengths, beam_size);
  torch::Tensor ot = output.toTensor();
  std::string text;
  for (int j = 0; j < ot[0].size(0); j++) {
    int token_id = ot[0][j].item<int>();
    if (token_id == eos_) break;
    text += dict_[token_id];
  }
  std::cout << "text: " << text << std::endl;
  return text;
}
