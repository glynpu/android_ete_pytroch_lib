# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lyguo/tools/cmake-3.18.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/lyguo/tools/cmake-3.18.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lyguo/github/pytorch-android-cpp-demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyguo/github/pytorch-android-cpp-demo/build_android

# Include any dependencies generated for this target.
include CMakeFiles/static_e2e.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/static_e2e.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/static_e2e.dir/flags.make

CMakeFiles/static_e2e.dir/kaldi_io.cc.o: CMakeFiles/static_e2e.dir/flags.make
CMakeFiles/static_e2e.dir/kaldi_io.cc.o: ../kaldi_io.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/static_e2e.dir/kaldi_io.cc.o"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_e2e.dir/kaldi_io.cc.o -c /home/lyguo/github/pytorch-android-cpp-demo/kaldi_io.cc

CMakeFiles/static_e2e.dir/kaldi_io.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_e2e.dir/kaldi_io.cc.i"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyguo/github/pytorch-android-cpp-demo/kaldi_io.cc > CMakeFiles/static_e2e.dir/kaldi_io.cc.i

CMakeFiles/static_e2e.dir/kaldi_io.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_e2e.dir/kaldi_io.cc.s"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyguo/github/pytorch-android-cpp-demo/kaldi_io.cc -o CMakeFiles/static_e2e.dir/kaldi_io.cc.s

CMakeFiles/static_e2e.dir/fft.cc.o: CMakeFiles/static_e2e.dir/flags.make
CMakeFiles/static_e2e.dir/fft.cc.o: ../fft.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/static_e2e.dir/fft.cc.o"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_e2e.dir/fft.cc.o -c /home/lyguo/github/pytorch-android-cpp-demo/fft.cc

CMakeFiles/static_e2e.dir/fft.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_e2e.dir/fft.cc.i"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyguo/github/pytorch-android-cpp-demo/fft.cc > CMakeFiles/static_e2e.dir/fft.cc.i

CMakeFiles/static_e2e.dir/fft.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_e2e.dir/fft.cc.s"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyguo/github/pytorch-android-cpp-demo/fft.cc -o CMakeFiles/static_e2e.dir/fft.cc.s

CMakeFiles/static_e2e.dir/wave_reader.cc.o: CMakeFiles/static_e2e.dir/flags.make
CMakeFiles/static_e2e.dir/wave_reader.cc.o: ../wave_reader.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/static_e2e.dir/wave_reader.cc.o"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_e2e.dir/wave_reader.cc.o -c /home/lyguo/github/pytorch-android-cpp-demo/wave_reader.cc

CMakeFiles/static_e2e.dir/wave_reader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_e2e.dir/wave_reader.cc.i"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyguo/github/pytorch-android-cpp-demo/wave_reader.cc > CMakeFiles/static_e2e.dir/wave_reader.cc.i

CMakeFiles/static_e2e.dir/wave_reader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_e2e.dir/wave_reader.cc.s"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyguo/github/pytorch-android-cpp-demo/wave_reader.cc -o CMakeFiles/static_e2e.dir/wave_reader.cc.s

CMakeFiles/static_e2e.dir/recognizer_impl.cc.o: CMakeFiles/static_e2e.dir/flags.make
CMakeFiles/static_e2e.dir/recognizer_impl.cc.o: ../recognizer_impl.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/static_e2e.dir/recognizer_impl.cc.o"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_e2e.dir/recognizer_impl.cc.o -c /home/lyguo/github/pytorch-android-cpp-demo/recognizer_impl.cc

CMakeFiles/static_e2e.dir/recognizer_impl.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_e2e.dir/recognizer_impl.cc.i"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyguo/github/pytorch-android-cpp-demo/recognizer_impl.cc > CMakeFiles/static_e2e.dir/recognizer_impl.cc.i

CMakeFiles/static_e2e.dir/recognizer_impl.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_e2e.dir/recognizer_impl.cc.s"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyguo/github/pytorch-android-cpp-demo/recognizer_impl.cc -o CMakeFiles/static_e2e.dir/recognizer_impl.cc.s

CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.o: CMakeFiles/static_e2e.dir/flags.make
CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.o: ../wrapper_recognizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.o"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.o -c /home/lyguo/github/pytorch-android-cpp-demo/wrapper_recognizer.cc

CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.i"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyguo/github/pytorch-android-cpp-demo/wrapper_recognizer.cc > CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.i

CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.s"
	/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=armv7-none-linux-androideabi21 --gcc-toolchain=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/lyguo/tools/android-ndk-r20b/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyguo/github/pytorch-android-cpp-demo/wrapper_recognizer.cc -o CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.s

# Object files for target static_e2e
static_e2e_OBJECTS = \
"CMakeFiles/static_e2e.dir/kaldi_io.cc.o" \
"CMakeFiles/static_e2e.dir/fft.cc.o" \
"CMakeFiles/static_e2e.dir/wave_reader.cc.o" \
"CMakeFiles/static_e2e.dir/recognizer_impl.cc.o" \
"CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.o"

# External object files for target static_e2e
static_e2e_EXTERNAL_OBJECTS =

libstatic_e2e.a: CMakeFiles/static_e2e.dir/kaldi_io.cc.o
libstatic_e2e.a: CMakeFiles/static_e2e.dir/fft.cc.o
libstatic_e2e.a: CMakeFiles/static_e2e.dir/wave_reader.cc.o
libstatic_e2e.a: CMakeFiles/static_e2e.dir/recognizer_impl.cc.o
libstatic_e2e.a: CMakeFiles/static_e2e.dir/wrapper_recognizer.cc.o
libstatic_e2e.a: CMakeFiles/static_e2e.dir/build.make
libstatic_e2e.a: CMakeFiles/static_e2e.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libstatic_e2e.a"
	$(CMAKE_COMMAND) -P CMakeFiles/static_e2e.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/static_e2e.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/static_e2e.dir/build: libstatic_e2e.a

.PHONY : CMakeFiles/static_e2e.dir/build

CMakeFiles/static_e2e.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/static_e2e.dir/cmake_clean.cmake
.PHONY : CMakeFiles/static_e2e.dir/clean

CMakeFiles/static_e2e.dir/depend:
	cd /home/lyguo/github/pytorch-android-cpp-demo/build_android && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyguo/github/pytorch-android-cpp-demo /home/lyguo/github/pytorch-android-cpp-demo /home/lyguo/github/pytorch-android-cpp-demo/build_android /home/lyguo/github/pytorch-android-cpp-demo/build_android /home/lyguo/github/pytorch-android-cpp-demo/build_android/CMakeFiles/static_e2e.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/static_e2e.dir/depend
