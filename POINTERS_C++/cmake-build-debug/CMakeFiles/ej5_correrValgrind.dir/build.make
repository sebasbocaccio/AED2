# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/121/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/121/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4/cmake-build-debug"

# Utility rule file for ej5_correrValgrind.

# Include the progress variables for this target.
include CMakeFiles/ej5_correrValgrind.dir/progress.make

CMakeFiles/ej5_correrValgrind: ej4
	valgrind --leak-check=full -v ./ej4 2>&1

ej5_correrValgrind: CMakeFiles/ej5_correrValgrind
ej5_correrValgrind: CMakeFiles/ej5_correrValgrind.dir/build.make

.PHONY : ej5_correrValgrind

# Rule to build all files generated by this target.
CMakeFiles/ej5_correrValgrind.dir/build: ej5_correrValgrind

.PHONY : CMakeFiles/ej5_correrValgrind.dir/build

CMakeFiles/ej5_correrValgrind.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej5_correrValgrind.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej5_correrValgrind.dir/clean

CMakeFiles/ej5_correrValgrind.dir/depend:
	cd "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4" "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4" "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4/cmake-build-debug" "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4/cmake-build-debug" "/home/sebasbocaccio/Desktop/Algo 2 Solo/Labo/Clase4/cmake-build-debug/CMakeFiles/ej5_correrValgrind.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej5_correrValgrind.dir/depend

