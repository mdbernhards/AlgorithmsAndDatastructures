# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build

# Include any dependencies generated for this target.
include merge_sort/CMakeFiles/merge_sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include merge_sort/CMakeFiles/merge_sort.dir/compiler_depend.make

# Include the progress variables for this target.
include merge_sort/CMakeFiles/merge_sort.dir/progress.make

# Include the compile flags for this target's objects.
include merge_sort/CMakeFiles/merge_sort.dir/flags.make

merge_sort/CMakeFiles/merge_sort.dir/main.c.o: merge_sort/CMakeFiles/merge_sort.dir/flags.make
merge_sort/CMakeFiles/merge_sort.dir/main.c.o: /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/main.c
merge_sort/CMakeFiles/merge_sort.dir/main.c.o: merge_sort/CMakeFiles/merge_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object merge_sort/CMakeFiles/merge_sort.dir/main.c.o"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT merge_sort/CMakeFiles/merge_sort.dir/main.c.o -MF CMakeFiles/merge_sort.dir/main.c.o.d -o CMakeFiles/merge_sort.dir/main.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/main.c

merge_sort/CMakeFiles/merge_sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/merge_sort.dir/main.c.i"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/main.c > CMakeFiles/merge_sort.dir/main.c.i

merge_sort/CMakeFiles/merge_sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/merge_sort.dir/main.c.s"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/main.c -o CMakeFiles/merge_sort.dir/main.c.s

merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.o: merge_sort/CMakeFiles/merge_sort.dir/flags.make
merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.o: /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/merge_sort.c
merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.o: merge_sort/CMakeFiles/merge_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.o"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.o -MF CMakeFiles/merge_sort.dir/merge_sort.c.o.d -o CMakeFiles/merge_sort.dir/merge_sort.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/merge_sort.c

merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/merge_sort.dir/merge_sort.c.i"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/merge_sort.c > CMakeFiles/merge_sort.dir/merge_sort.c.i

merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/merge_sort.dir/merge_sort.c.s"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/merge_sort.c -o CMakeFiles/merge_sort.dir/merge_sort.c.s

merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.o: merge_sort/CMakeFiles/merge_sort.dir/flags.make
merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.o: /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/test_merge_sort.c
merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.o: merge_sort/CMakeFiles/merge_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.o"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.o -MF CMakeFiles/merge_sort.dir/test_merge_sort.c.o.d -o CMakeFiles/merge_sort.dir/test_merge_sort.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/test_merge_sort.c

merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/merge_sort.dir/test_merge_sort.c.i"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/test_merge_sort.c > CMakeFiles/merge_sort.dir/test_merge_sort.c.i

merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/merge_sort.dir/test_merge_sort.c.s"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort/test_merge_sort.c -o CMakeFiles/merge_sort.dir/test_merge_sort.c.s

# Object files for target merge_sort
merge_sort_OBJECTS = \
"CMakeFiles/merge_sort.dir/main.c.o" \
"CMakeFiles/merge_sort.dir/merge_sort.c.o" \
"CMakeFiles/merge_sort.dir/test_merge_sort.c.o"

# External object files for target merge_sort
merge_sort_EXTERNAL_OBJECTS =

merge_sort/merge_sort: merge_sort/CMakeFiles/merge_sort.dir/main.c.o
merge_sort/merge_sort: merge_sort/CMakeFiles/merge_sort.dir/merge_sort.c.o
merge_sort/merge_sort: merge_sort/CMakeFiles/merge_sort.dir/test_merge_sort.c.o
merge_sort/merge_sort: merge_sort/CMakeFiles/merge_sort.dir/build.make
merge_sort/merge_sort: sortinglib/libsortinglib.a
merge_sort/merge_sort: merge_sort/CMakeFiles/merge_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable merge_sort"
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/merge_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
merge_sort/CMakeFiles/merge_sort.dir/build: merge_sort/merge_sort
.PHONY : merge_sort/CMakeFiles/merge_sort.dir/build

merge_sort/CMakeFiles/merge_sort.dir/clean:
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort && $(CMAKE_COMMAND) -P CMakeFiles/merge_sort.dir/cmake_clean.cmake
.PHONY : merge_sort/CMakeFiles/merge_sort.dir/clean

merge_sort/CMakeFiles/merge_sort.dir/depend:
	cd /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/merge_sort /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort /mnt/c/AlgorithmsAndDatastructures/Week5/sorting-code/build/merge_sort/CMakeFiles/merge_sort.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : merge_sort/CMakeFiles/merge_sort.dir/depend

