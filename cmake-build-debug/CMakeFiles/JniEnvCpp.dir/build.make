# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/z/CLionProjects/JniEnvCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/z/CLionProjects/JniEnvCpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/JniEnvCpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JniEnvCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JniEnvCpp.dir/flags.make

CMakeFiles/JniEnvCpp.dir/main.cpp.o: CMakeFiles/JniEnvCpp.dir/flags.make
CMakeFiles/JniEnvCpp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/z/CLionProjects/JniEnvCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JniEnvCpp.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/JniEnvCpp.dir/main.cpp.o -c /Users/z/CLionProjects/JniEnvCpp/main.cpp

CMakeFiles/JniEnvCpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JniEnvCpp.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/z/CLionProjects/JniEnvCpp/main.cpp > CMakeFiles/JniEnvCpp.dir/main.cpp.i

CMakeFiles/JniEnvCpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JniEnvCpp.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/z/CLionProjects/JniEnvCpp/main.cpp -o CMakeFiles/JniEnvCpp.dir/main.cpp.s

# Object files for target JniEnvCpp
JniEnvCpp_OBJECTS = \
"CMakeFiles/JniEnvCpp.dir/main.cpp.o"

# External object files for target JniEnvCpp
JniEnvCpp_EXTERNAL_OBJECTS =

JniEnvCpp: CMakeFiles/JniEnvCpp.dir/main.cpp.o
JniEnvCpp: CMakeFiles/JniEnvCpp.dir/build.make
JniEnvCpp: CMakeFiles/JniEnvCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/z/CLionProjects/JniEnvCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JniEnvCpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/JniEnvCpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JniEnvCpp.dir/build: JniEnvCpp

.PHONY : CMakeFiles/JniEnvCpp.dir/build

CMakeFiles/JniEnvCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/JniEnvCpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/JniEnvCpp.dir/clean

CMakeFiles/JniEnvCpp.dir/depend:
	cd /Users/z/CLionProjects/JniEnvCpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/z/CLionProjects/JniEnvCpp /Users/z/CLionProjects/JniEnvCpp /Users/z/CLionProjects/JniEnvCpp/cmake-build-debug /Users/z/CLionProjects/JniEnvCpp/cmake-build-debug /Users/z/CLionProjects/JniEnvCpp/cmake-build-debug/CMakeFiles/JniEnvCpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/JniEnvCpp.dir/depend

