# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataStructureLab02_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructureLab02_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructureLab02_2.dir/flags.make

CMakeFiles/DataStructureLab02_2.dir/main.c.o: CMakeFiles/DataStructureLab02_2.dir/flags.make
CMakeFiles/DataStructureLab02_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DataStructureLab02_2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DataStructureLab02_2.dir/main.c.o   -c /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/main.c

CMakeFiles/DataStructureLab02_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DataStructureLab02_2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/main.c > CMakeFiles/DataStructureLab02_2.dir/main.c.i

CMakeFiles/DataStructureLab02_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DataStructureLab02_2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/main.c -o CMakeFiles/DataStructureLab02_2.dir/main.c.s

# Object files for target DataStructureLab02_2
DataStructureLab02_2_OBJECTS = \
"CMakeFiles/DataStructureLab02_2.dir/main.c.o"

# External object files for target DataStructureLab02_2
DataStructureLab02_2_EXTERNAL_OBJECTS =

DataStructureLab02_2: CMakeFiles/DataStructureLab02_2.dir/main.c.o
DataStructureLab02_2: CMakeFiles/DataStructureLab02_2.dir/build.make
DataStructureLab02_2: CMakeFiles/DataStructureLab02_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DataStructureLab02_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructureLab02_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructureLab02_2.dir/build: DataStructureLab02_2

.PHONY : CMakeFiles/DataStructureLab02_2.dir/build

CMakeFiles/DataStructureLab02_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructureLab02_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructureLab02_2.dir/clean

CMakeFiles/DataStructureLab02_2.dir/depend:
	cd /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2 /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2 /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug /Users/gong/Desktop/MyC:C++Code/MyC-C-Code/DataStructureLab02_2/cmake-build-debug/CMakeFiles/DataStructureLab02_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructureLab02_2.dir/depend

