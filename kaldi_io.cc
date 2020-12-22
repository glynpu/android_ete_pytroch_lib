// Copyright 2020 Mobvoi Inc. All Rights Reserved.
// Author: lyguo@mobvoi.com (Liyong Guo)

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <kaldi_io.h>

void KaldiMatrix::Read(std::istream& is) {
  std::string s;
  while (getline(is, s)) {
    if (s.empty()) {
      continue;
    }
    data_.resize(data_.size() + 1);

    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    // remove leading white space
    while (s[0] == delimiter[0]) {
      s.erase(0, delimiter.length());
    }
    while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      // std::cout << token << std::endl;
      s.erase(0, pos + delimiter.length());
      data_[data_.size() - 1].push_back(std::stof(token));
    }
  }
  std::cout << "data_[0].size(): " << data_[0].size() << std::endl;
}

void KaldiMatrix::Write(std::ofstream& out) {
  for (const auto row : data_) {
    out << " ";
    for (const auto e : row) {
      /* std::ostringstream oss; */
      /* oss << e; //std::to_string(); */
      /* out << " " << oss.str(); */
      /* out << " " << std::to_string(e); */
      std::string str = std::to_string(e);
      out << " " << str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    }
    out << std::endl;
  }
}
