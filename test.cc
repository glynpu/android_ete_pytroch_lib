#include "fstream"
// #include "recognizer_impl.h"
#include "wave_reader.h"
#include "wrapper_recognizer.h"

int main(int argc, char* argv[]) {
  // std::string ark = "single_feat.ark";
  // std::string ark = "./feats_cmvn.ark";

  std::string wav_file = argv[1];
  std::ifstream wav_stream(wav_file);
  mobvoi::voiceprint::WaveData wave_data;
  wave_data.Read(wav_stream);
  std::vector<float> waves = wave_data.Data()[0];
  std::string dict_file = "./lang_char.txt";
  std::string model_file = "./final.zip";
  // RecognizerImpl recogimpl(dict_file, model_file);
  // std::string result = recogimpl.recognize(waves);
  WrapperRecognizer wrapper_recognizer(dict_file, model_file);
  std::string result = wrapper_recognizer.recognize(waves);
  std::cout << "result: " << result << std::endl;

  return 0;
}
