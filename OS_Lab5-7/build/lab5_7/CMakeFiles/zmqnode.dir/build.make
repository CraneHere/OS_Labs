# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Shy/Documents/OS_Labs/OS_Lab5-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build

# Include any dependencies generated for this target.
include lab5_7/CMakeFiles/zmqnode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lab5_7/CMakeFiles/zmqnode.dir/compiler_depend.make

# Include the progress variables for this target.
include lab5_7/CMakeFiles/zmqnode.dir/progress.make

# Include the compile flags for this target's objects.
include lab5_7/CMakeFiles/zmqnode.dir/flags.make

lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.o: lab5_7/CMakeFiles/zmqnode.dir/flags.make
lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.o: /Users/Shy/Documents/OS_Labs/OS_Lab5-7/lab5_7/src/node.cpp
lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.o: lab5_7/CMakeFiles/zmqnode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.o"
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.o -MF CMakeFiles/zmqnode.dir/src/node.cpp.o.d -o CMakeFiles/zmqnode.dir/src/node.cpp.o -c /Users/Shy/Documents/OS_Labs/OS_Lab5-7/lab5_7/src/node.cpp

lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/zmqnode.dir/src/node.cpp.i"
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Shy/Documents/OS_Labs/OS_Lab5-7/lab5_7/src/node.cpp > CMakeFiles/zmqnode.dir/src/node.cpp.i

lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/zmqnode.dir/src/node.cpp.s"
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Shy/Documents/OS_Labs/OS_Lab5-7/lab5_7/src/node.cpp -o CMakeFiles/zmqnode.dir/src/node.cpp.s

# Object files for target zmqnode
zmqnode_OBJECTS = \
"CMakeFiles/zmqnode.dir/src/node.cpp.o"

# External object files for target zmqnode
zmqnode_EXTERNAL_OBJECTS =

lab5_7/libzmqnode.a: lab5_7/CMakeFiles/zmqnode.dir/src/node.cpp.o
lab5_7/libzmqnode.a: lab5_7/CMakeFiles/zmqnode.dir/build.make
lab5_7/libzmqnode.a: lab5_7/CMakeFiles/zmqnode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libzmqnode.a"
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 && $(CMAKE_COMMAND) -P CMakeFiles/zmqnode.dir/cmake_clean_target.cmake
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmqnode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lab5_7/CMakeFiles/zmqnode.dir/build: lab5_7/libzmqnode.a
.PHONY : lab5_7/CMakeFiles/zmqnode.dir/build

lab5_7/CMakeFiles/zmqnode.dir/clean:
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 && $(CMAKE_COMMAND) -P CMakeFiles/zmqnode.dir/cmake_clean.cmake
.PHONY : lab5_7/CMakeFiles/zmqnode.dir/clean

lab5_7/CMakeFiles/zmqnode.dir/depend:
	cd /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Shy/Documents/OS_Labs/OS_Lab5-7 /Users/Shy/Documents/OS_Labs/OS_Lab5-7/lab5_7 /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7 /Users/Shy/Documents/OS_Labs/OS_Lab5-7/build/lab5_7/CMakeFiles/zmqnode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lab5_7/CMakeFiles/zmqnode.dir/depend
