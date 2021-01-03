#include <jni.h>
#include <string>
#include <vector>
#include "com_example_audiorecordertest_e2e.h"
#include "wrapper_recognizer.h"

WrapperRecognizer *jni_wrapper_recognizer_;
JNIEXPORT void JNICALL Java_com_example_audiorecordertest_E2E_init(
    JNIEnv *env, jobject obj, jstring dictfile, jstring modelfile) {
  const char *dict_file = env->GetStringUTFChars(dictfile, NULL);
  const char *model_file = env->GetStringUTFChars(modelfile, NULL);
  std::string str_dict_file = dict_file;
  std::string str_model_file = model_file;

  jni_wrapper_recognizer_ =
      new WrapperRecognizer(str_dict_file, str_model_file);
}

JNIEXPORT jstring JNICALL Java_com_example_audiorecordertest_E2E_recognize(
    JNIEnv *env, jobject obj, jshortArray jarr) {
  jshort *array = env->GetShortArrayElements(jarr, NULL);
  jsize size = env->GetArrayLength(jarr);
  std::vector<float> waves(size, 0);
  for (int i = 0; i < size; i++) waves[i] = array[i];

  std::string result = "no result: " + std::to_string(size);

  result = jni_wrapper_recognizer_->recognize(waves);
  return env->NewStringUTF(result.c_str());
}
