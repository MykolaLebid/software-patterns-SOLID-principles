# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build

# Include any dependencies generated for this target.
include CMakeFiles/cache_adapter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cache_adapter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cache_adapter.dir/flags.make

CMakeFiles/cache_adapter.dir/main.cpp.o: CMakeFiles/cache_adapter.dir/flags.make
CMakeFiles/cache_adapter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cache_adapter.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cache_adapter.dir/main.cpp.o -c /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/main.cpp

CMakeFiles/cache_adapter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cache_adapter.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/main.cpp > CMakeFiles/cache_adapter.dir/main.cpp.i

CMakeFiles/cache_adapter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cache_adapter.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/main.cpp -o CMakeFiles/cache_adapter.dir/main.cpp.s

# Object files for target cache_adapter
cache_adapter_OBJECTS = \
"CMakeFiles/cache_adapter.dir/main.cpp.o"

# External object files for target cache_adapter
cache_adapter_EXTERNAL_OBJECTS =

cache_adapter: CMakeFiles/cache_adapter.dir/main.cpp.o
cache_adapter: CMakeFiles/cache_adapter.dir/build.make
cache_adapter: CMakeFiles/cache_adapter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cache_adapter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cache_adapter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cache_adapter.dir/build: cache_adapter

.PHONY : CMakeFiles/cache_adapter.dir/build

CMakeFiles/cache_adapter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cache_adapter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cache_adapter.dir/clean

CMakeFiles/cache_adapter.dir/depend:
	cd /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build /home/mykola/Repos/design_patterns_in_modern_cpp/structural_patterns/adapter/adapter_with_filter/build/CMakeFiles/cache_adapter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cache_adapter.dir/depend
