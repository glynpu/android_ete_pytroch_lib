// Copyright 2020 Mobvoi Inc. All Rights Reserved.
// Author: lyguo@mobvoi.com (Liyong Guo)

#include "wrapper_recognizer.h"
#include "recognizer_impl.h"

WrapperRecognizer::WrapperRecognizer(const std::string& dict_file,
                                     const std::string& model_file) {
  recognizer_imp_.reset(new RecognizerImpl(dict_file, model_file));
}

std::string WrapperRecognizer::recognize(const std::vector<float> waves) {
  return recognizer_imp_->recognize(waves);
}
