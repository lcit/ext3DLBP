# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leo/Desktop/ext3DLBP/python_wrapper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/Desktop/ext3DLBP/python_wrapper/build

# Include any dependencies generated for this target.
include CMakeFiles/ext3DLBPpy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ext3DLBPpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ext3DLBPpy.dir/flags.make

CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o: CMakeFiles/ext3DLBPpy.dir/flags.make
CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o: ../ext3DLBPpy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/Desktop/ext3DLBP/python_wrapper/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o -c /home/leo/Desktop/ext3DLBP/python_wrapper/ext3DLBPpy.cpp

CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/leo/Desktop/ext3DLBP/python_wrapper/ext3DLBPpy.cpp > CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.i

CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/leo/Desktop/ext3DLBP/python_wrapper/ext3DLBPpy.cpp -o CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.s

CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.requires:
.PHONY : CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.requires

CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.provides: CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.requires
	$(MAKE) -f CMakeFiles/ext3DLBPpy.dir/build.make CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.provides.build
.PHONY : CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.provides

CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.provides.build: CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o

# Object files for target ext3DLBPpy
ext3DLBPpy_OBJECTS = \
"CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o"

# External object files for target ext3DLBPpy
ext3DLBPpy_EXTERNAL_OBJECTS =

ext3DLBPpy.so: CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o
ext3DLBPpy.so: CMakeFiles/ext3DLBPpy.dir/build.make
ext3DLBPpy.so: /usr/lib/x86_64-linux-gnu/libpython2.7.so
ext3DLBPpy.so: CMakeFiles/ext3DLBPpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ext3DLBPpy.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ext3DLBPpy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ext3DLBPpy.dir/build: ext3DLBPpy.so
.PHONY : CMakeFiles/ext3DLBPpy.dir/build

CMakeFiles/ext3DLBPpy.dir/requires: CMakeFiles/ext3DLBPpy.dir/ext3DLBPpy.cpp.o.requires
.PHONY : CMakeFiles/ext3DLBPpy.dir/requires

CMakeFiles/ext3DLBPpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ext3DLBPpy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ext3DLBPpy.dir/clean

CMakeFiles/ext3DLBPpy.dir/depend:
	cd /home/leo/Desktop/ext3DLBP/python_wrapper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/Desktop/ext3DLBP/python_wrapper /home/leo/Desktop/ext3DLBP/python_wrapper /home/leo/Desktop/ext3DLBP/python_wrapper/build /home/leo/Desktop/ext3DLBP/python_wrapper/build /home/leo/Desktop/ext3DLBP/python_wrapper/build/CMakeFiles/ext3DLBPpy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ext3DLBPpy.dir/depend
