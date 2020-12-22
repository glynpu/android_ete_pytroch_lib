// Copyright 2020 Mobvoi Inc. All Rights Reserved.
// Author: lyguo@mobvoi.com (Liyong Guo)

#include <iostream>
#include <vector>

class KaldiMatrix {
 public:
  KaldiMatrix() {}
  ~KaldiMatrix() = default;
  void Read(std::istream& is);
  void Write(std::ofstream& out);
  const std::vector< std::vector<float>>& Data() const {return data_; }
 private:
  std::vector<std::vector<float>> data_;
};

