# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sahilraj/Downloads/client/image

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sahilraj/Downloads/client/image

# Include any dependencies generated for this target.
include CMakeFiles/img.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/img.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/img.dir/flags.make

CMakeFiles/img.dir/cli2.o: CMakeFiles/img.dir/flags.make
CMakeFiles/img.dir/cli2.o: cli2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sahilraj/Downloads/client/image/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/img.dir/cli2.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/img.dir/cli2.o -c /home/sahilraj/Downloads/client/image/cli2.cpp

CMakeFiles/img.dir/cli2.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/img.dir/cli2.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sahilraj/Downloads/client/image/cli2.cpp > CMakeFiles/img.dir/cli2.i

CMakeFiles/img.dir/cli2.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/img.dir/cli2.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sahilraj/Downloads/client/image/cli2.cpp -o CMakeFiles/img.dir/cli2.s

CMakeFiles/img.dir/cli2.o.requires:

.PHONY : CMakeFiles/img.dir/cli2.o.requires

CMakeFiles/img.dir/cli2.o.provides: CMakeFiles/img.dir/cli2.o.requires
	$(MAKE) -f CMakeFiles/img.dir/build.make CMakeFiles/img.dir/cli2.o.provides.build
.PHONY : CMakeFiles/img.dir/cli2.o.provides

CMakeFiles/img.dir/cli2.o.provides.build: CMakeFiles/img.dir/cli2.o


# Object files for target img
img_OBJECTS = \
"CMakeFiles/img.dir/cli2.o"

# External object files for target img
img_EXTERNAL_OBJECTS =

img: CMakeFiles/img.dir/cli2.o
img: CMakeFiles/img.dir/build.make
img: /usr/local/lib/libopencv_videostab.so.2.4.9
img: /usr/local/lib/libopencv_ts.a
img: /usr/local/lib/libopencv_superres.so.2.4.9
img: /usr/local/lib/libopencv_stitching.so.2.4.9
img: /usr/local/lib/libopencv_contrib.so.2.4.9
img: /usr/local/lib/libopencv_nonfree.so.2.4.9
img: /usr/local/lib/libopencv_ocl.so.2.4.9
img: /usr/local/lib/libopencv_gpu.so.2.4.9
img: /usr/local/lib/libopencv_photo.so.2.4.9
img: /usr/local/lib/libopencv_objdetect.so.2.4.9
img: /usr/local/lib/libopencv_legacy.so.2.4.9
img: /usr/local/lib/libopencv_video.so.2.4.9
img: /usr/local/lib/libopencv_ml.so.2.4.9
img: /usr/local/lib/libopencv_calib3d.so.2.4.9
img: /usr/local/lib/libopencv_features2d.so.2.4.9
img: /usr/local/lib/libopencv_highgui.so.2.4.9
img: /usr/local/lib/libopencv_imgproc.so.2.4.9
img: /usr/local/lib/libopencv_flann.so.2.4.9
img: /usr/local/lib/libopencv_core.so.2.4.9
img: CMakeFiles/img.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sahilraj/Downloads/client/image/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable img"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/img.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/img.dir/build: img

.PHONY : CMakeFiles/img.dir/build

CMakeFiles/img.dir/requires: CMakeFiles/img.dir/cli2.o.requires

.PHONY : CMakeFiles/img.dir/requires

CMakeFiles/img.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/img.dir/cmake_clean.cmake
.PHONY : CMakeFiles/img.dir/clean

CMakeFiles/img.dir/depend:
	cd /home/sahilraj/Downloads/client/image && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sahilraj/Downloads/client/image /home/sahilraj/Downloads/client/image /home/sahilraj/Downloads/client/image /home/sahilraj/Downloads/client/image /home/sahilraj/Downloads/client/image/CMakeFiles/img.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/img.dir/depend

