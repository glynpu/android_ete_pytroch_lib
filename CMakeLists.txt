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
add_executable(Predictor test.cc kaldi_io.cc fft.cc wave_reader.cc)
target_include_directories(Predictor PUBLIC ${TORCH_INCLUDE_DIRS})

# include_directories("./")
# add_executable(Test test.cc kaldi_io.cc)
# target_include_directories(Test PUBLIC ${TORCH_INCLUDE_DIRS})

find_package(Threads REQUIRED)

if(ANDROID_ABI)
  find_library(Log log)
endif()

# The linker flags will be moved to TorchConfig.cmake
if(APPLE)
  target_link_libraries(Predictor
    -Wl,-s
    -Wl,-dead_strip
    -Wl,-all_load
    ${TORCH_LIBRARIES}
    -Wl,-noall_load
    Threads::Threads
    ${Log}
		-std=c++11
  )
else()
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
endif()
