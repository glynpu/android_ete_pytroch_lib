// Copyright 2020 Mobvoi Inc. All Rights Reserved.
// Author: lyguo@mobvoi.com (Liyong Guo)

#ifndef RECOGNIZER_IMPL_H_
#define RECOGNIZER_IMPL_H_

#include <fbank.h>
#include <torch/script.h>
#include <memory>

class RecognizerImpl {
 public:
  RecognizerImpl(const std::string& dict_file, const std::string& model_file);
  std::string recognize(const std::vector<float> waves);

 private:
  void LoadDict(const std::string& dict_file);
  std::vector<std::string> dict_;
  std::shared_ptr<Fbank> fbank_extractor_;
  // std::shared_ptr<torch::jit::script::Module> model_;
  torch::jit::script::Module model_;
  int eos_;
};

#endif  // RECOGNIZER_IMPL_H_
