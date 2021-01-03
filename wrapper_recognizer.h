// Copyright 2020 Mobvoi Inc. All Rights Reserved.
// Author: lyguo@mobvoi.com (Liyong Guo)

#ifndef WRAPPER_RECOGNIZER_H_
#define WRAPPER_RECOGNIZER_H_

#include <memory>
#include <vector>

class RecognizerImpl;
class WrapperRecognizer {
 public:
  WrapperRecognizer(const std::string& dict_file,
                    const std::string& model_file);
  std::string recognize(const std::vector<float> waves);

 private:
  std::shared_ptr<RecognizerImpl> recognizer_imp_ = nullptr;
};

#endif  // WRAPPER_RECOGNIZER_H_
