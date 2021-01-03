cmake_minimum_required(VERSION 3.1)

project(pytorch_android_cpp_demo)
set(CMAKE_CXX_STANDARD 14)

if(ANDROID_ABI)
  list(APPEND CMAKE_FIND_ROOT_PATH ${PYTORCH_ANDROID_PATH})
  message(STATUS "Using PyTorch Android library:" ${PYTORCH_ANDROID_PATH})
endif()

# Find torch library
find_package(Torch REQUIRED)

# Main executable
include_directories("./")
#add_executable(Predictor predictor.cpp)
add_executable(Predictor test.cc kaldi_io.cc fft.cc wave_reader.cc recognizer_impl.cc wrapper_recognizer.cc)
target_include_directories(Predictor PUBLIC ${TORCH_INCLUDE_DIRS})

# include_directories("./")
# add_executable(Test test.cc kaldi_io.cc)
# target_include_directories(Test PUBLIC ${TORCH_INCLUDE_DIRS})

find_package(Threads REQUIRED)

if(ANDROID_ABI)
  find_library(Log log)
endif()

target_link_libraries(Predictor
  -Wl,-s
  -Wl,--gc-sections
  -Wl,--whole-archive
  ${TORCH_LIBRARIES}
  -Wl,--no-whole-archive
  Threads::Threads
  ${Log}
	-std=c++11
)

add_library(e2e SHARED kaldi_io.cc fft.cc wave_reader.cc recognizer_impl.cc wrapper_recognizer.cc)
target_include_directories(e2e PUBLIC ${TORCH_INCLUDE_DIRS})
target_link_libraries( e2e
	-Wl,-s
	-Wl,--gc-sections
	-Wl,--whole-archive
  ${TORCH_LIBRARIES}
	-Wl,--no-whole-archive
  Threads::Threads
  ${Log}
	-std=c++11
)

# this will generate a libe2d_jni.so
# copy this to jnilibs folder
add_library(e2e_jni SHARED e2e.cpp fft.cc recognizer_impl.cc wrapper_recognizer.cc)
target_include_directories(e2e_jni PUBLIC ${TORCH_INCLUDE_DIRS})
target_link_libraries( e2e_jni
	-Wl,-s
	-Wl,--gc-sections
	-Wl,--whole-archive
  ${TORCH_LIBRARIES}
	-Wl,--no-whole-archive
  Threads::Threads
  ${Log}
	-std=c++11
)


add_library(static_e2e STATIC kaldi_io.cc fft.cc wave_reader.cc recognizer_impl.cc wrapper_recognizer.cc)
target_include_directories(static_e2e PUBLIC ${TORCH_INCLUDE_DIRS})
target_link_libraries( static_e2e
	-Wl,-s
	-Wl,--gc-sections
	-Wl,--whole-archive
  ${TORCH_LIBRARIES}
	-Wl,--no-whole-archive
  Threads::Threads
  ${Log}
	-std=c++11
)

#link_directories("/home/lyguo/github/pytorch-android-cpp-demo/build/libe2e.so")
#link_libraries("/home/lyguo/github/pytorch-android-cpp-demo/${BUILD_ROOT}build_android/libe2e.so")
message("build_root: "${BUILD_ROOT})
link_libraries(${BUILD_ROOT}/libe2e.so)
add_executable(dynamic_Predictor test.cc wave_reader.cc)
#target_include_directories(dynamic_Predictor PUBLIC ${TORCH_INCLUDE_DIRS})
target_link_libraries(dynamic_Predictor
	e2e
	#-Wl,--whole-archive
	${TORCH_LIBRARIES}
	#-Wl,--no-whole-archive
	#Threads::Threads
	#pthread
  ${Log}
	-std=c++11
)
# target_link_libraries(dynamic_Predictor
# 	e2e
#   -Wl,-s
#   -Wl,--gc-sections
#   -Wl,--whole-archive
#   ${TORCH_LIBRARIES}
#   -Wl,--no-whole-archive
#   Threads::Threads
#   ${Log}
# 	-std=c++11
# )
# # The linker flags will be moved to TorchConfig.cmake
# if(APPLE)
#   target_link_libraries(Predictor
#     -Wl,-s
#     -Wl,-dead_strip
#     -Wl,-all_load
#     ${TORCH_LIBRARIES}
#     -Wl,-noall_load
#     Threads::Threads
#     ${Log}
# 		-std=c++11
#   )
# else()
#   target_link_libraries(Predictor
#     -Wl,-s
#     -Wl,--gc-sections
#     -Wl,--whole-archive
#     ${TORCH_LIBRARIES}
#     -Wl,--no-whole-archive
#     Threads::Threads
#     ${Log}
# 		-std=c++11
#   )
# endif()
