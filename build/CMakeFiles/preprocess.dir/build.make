# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Roast/wsl/Map-Matching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Roast/wsl/Map-Matching/build

# Include any dependencies generated for this target.
include CMakeFiles/preprocess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/preprocess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/preprocess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/preprocess.dir/flags.make

CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o: CMakeFiles/preprocess.dir/flags.make
CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o: ../preprocessing/scale_projection.cpp
CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o: CMakeFiles/preprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Roast/wsl/Map-Matching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o -MF CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o.d -o CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o -c /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/scale_projection.cpp

CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/scale_projection.cpp > CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.i

CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/scale_projection.cpp -o CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.s

CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o: CMakeFiles/preprocess.dir/flags.make
CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o: ../preprocessing/graph.cpp
CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o: CMakeFiles/preprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Roast/wsl/Map-Matching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o -MF CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o.d -o CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o -c /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/graph.cpp

CMakeFiles/preprocess.dir/preprocessing/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preprocess.dir/preprocessing/graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/graph.cpp > CMakeFiles/preprocess.dir/preprocessing/graph.cpp.i

CMakeFiles/preprocess.dir/preprocessing/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preprocess.dir/preprocessing/graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/graph.cpp -o CMakeFiles/preprocess.dir/preprocessing/graph.cpp.s

CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o: CMakeFiles/preprocess.dir/flags.make
CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o: ../preprocessing/graph_subsampling.cpp
CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o: CMakeFiles/preprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Roast/wsl/Map-Matching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o -MF CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o.d -o CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o -c /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/graph_subsampling.cpp

CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/graph_subsampling.cpp > CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.i

CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Roast/wsl/Map-Matching/preprocessing/graph_subsampling.cpp -o CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.s

CMakeFiles/preprocess.dir/main_preprocessing.cpp.o: CMakeFiles/preprocess.dir/flags.make
CMakeFiles/preprocess.dir/main_preprocessing.cpp.o: ../main_preprocessing.cpp
CMakeFiles/preprocess.dir/main_preprocessing.cpp.o: CMakeFiles/preprocess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Roast/wsl/Map-Matching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/preprocess.dir/main_preprocessing.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/preprocess.dir/main_preprocessing.cpp.o -MF CMakeFiles/preprocess.dir/main_preprocessing.cpp.o.d -o CMakeFiles/preprocess.dir/main_preprocessing.cpp.o -c /mnt/c/Users/Roast/wsl/Map-Matching/main_preprocessing.cpp

CMakeFiles/preprocess.dir/main_preprocessing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preprocess.dir/main_preprocessing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Roast/wsl/Map-Matching/main_preprocessing.cpp > CMakeFiles/preprocess.dir/main_preprocessing.cpp.i

CMakeFiles/preprocess.dir/main_preprocessing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preprocess.dir/main_preprocessing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Roast/wsl/Map-Matching/main_preprocessing.cpp -o CMakeFiles/preprocess.dir/main_preprocessing.cpp.s

# Object files for target preprocess
preprocess_OBJECTS = \
"CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o" \
"CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o" \
"CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o" \
"CMakeFiles/preprocess.dir/main_preprocessing.cpp.o"

# External object files for target preprocess
preprocess_EXTERNAL_OBJECTS =

preprocess: CMakeFiles/preprocess.dir/preprocessing/scale_projection.cpp.o
preprocess: CMakeFiles/preprocess.dir/preprocessing/graph.cpp.o
preprocess: CMakeFiles/preprocess.dir/preprocessing/graph_subsampling.cpp.o
preprocess: CMakeFiles/preprocess.dir/main_preprocessing.cpp.o
preprocess: CMakeFiles/preprocess.dir/build.make
preprocess: CMakeFiles/preprocess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Roast/wsl/Map-Matching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable preprocess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/preprocess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/preprocess.dir/build: preprocess
.PHONY : CMakeFiles/preprocess.dir/build

CMakeFiles/preprocess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/preprocess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/preprocess.dir/clean

CMakeFiles/preprocess.dir/depend:
	cd /mnt/c/Users/Roast/wsl/Map-Matching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Roast/wsl/Map-Matching /mnt/c/Users/Roast/wsl/Map-Matching /mnt/c/Users/Roast/wsl/Map-Matching/build /mnt/c/Users/Roast/wsl/Map-Matching/build /mnt/c/Users/Roast/wsl/Map-Matching/build/CMakeFiles/preprocess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/preprocess.dir/depend

