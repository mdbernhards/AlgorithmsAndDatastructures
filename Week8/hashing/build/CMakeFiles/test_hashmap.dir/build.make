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
CMAKE_SOURCE_DIR = /mnt/c/AlgorithmsAndDatastructures/Week8/hashing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build

# Include any dependencies generated for this target.
include CMakeFiles/test_hashmap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_hashmap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_hashmap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_hashmap.dir/flags.make

CMakeFiles/test_hashmap.dir/test_hashmap.c.o: CMakeFiles/test_hashmap.dir/flags.make
CMakeFiles/test_hashmap.dir/test_hashmap.c.o: /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_hashmap.c
CMakeFiles/test_hashmap.dir/test_hashmap.c.o: CMakeFiles/test_hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_hashmap.dir/test_hashmap.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hashmap.dir/test_hashmap.c.o -MF CMakeFiles/test_hashmap.dir/test_hashmap.c.o.d -o CMakeFiles/test_hashmap.dir/test_hashmap.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_hashmap.c

CMakeFiles/test_hashmap.dir/test_hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_hashmap.dir/test_hashmap.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_hashmap.c > CMakeFiles/test_hashmap.dir/test_hashmap.c.i

CMakeFiles/test_hashmap.dir/test_hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_hashmap.dir/test_hashmap.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_hashmap.c -o CMakeFiles/test_hashmap.dir/test_hashmap.c.s

CMakeFiles/test_hashmap.dir/hashmap.c.o: CMakeFiles/test_hashmap.dir/flags.make
CMakeFiles/test_hashmap.dir/hashmap.c.o: /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmap.c
CMakeFiles/test_hashmap.dir/hashmap.c.o: CMakeFiles/test_hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_hashmap.dir/hashmap.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hashmap.dir/hashmap.c.o -MF CMakeFiles/test_hashmap.dir/hashmap.c.o.d -o CMakeFiles/test_hashmap.dir/hashmap.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmap.c

CMakeFiles/test_hashmap.dir/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_hashmap.dir/hashmap.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmap.c > CMakeFiles/test_hashmap.dir/hashmap.c.i

CMakeFiles/test_hashmap.dir/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_hashmap.dir/hashmap.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmap.c -o CMakeFiles/test_hashmap.dir/hashmap.c.s

CMakeFiles/test_hashmap.dir/list.c.o: CMakeFiles/test_hashmap.dir/flags.make
CMakeFiles/test_hashmap.dir/list.c.o: /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/list.c
CMakeFiles/test_hashmap.dir/list.c.o: CMakeFiles/test_hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_hashmap.dir/list.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hashmap.dir/list.c.o -MF CMakeFiles/test_hashmap.dir/list.c.o.d -o CMakeFiles/test_hashmap.dir/list.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/list.c

CMakeFiles/test_hashmap.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_hashmap.dir/list.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/list.c > CMakeFiles/test_hashmap.dir/list.c.i

CMakeFiles/test_hashmap.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_hashmap.dir/list.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/list.c -o CMakeFiles/test_hashmap.dir/list.c.s

CMakeFiles/test_hashmap.dir/test_main.c.o: CMakeFiles/test_hashmap.dir/flags.make
CMakeFiles/test_hashmap.dir/test_main.c.o: /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_main.c
CMakeFiles/test_hashmap.dir/test_main.c.o: CMakeFiles/test_hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test_hashmap.dir/test_main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hashmap.dir/test_main.c.o -MF CMakeFiles/test_hashmap.dir/test_main.c.o.d -o CMakeFiles/test_hashmap.dir/test_main.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_main.c

CMakeFiles/test_hashmap.dir/test_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_hashmap.dir/test_main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_main.c > CMakeFiles/test_hashmap.dir/test_main.c.i

CMakeFiles/test_hashmap.dir/test_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_hashmap.dir/test_main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/test_main.c -o CMakeFiles/test_hashmap.dir/test_main.c.s

CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o: CMakeFiles/test_hashmap.dir/flags.make
CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o: /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmapfunctions.c
CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o: CMakeFiles/test_hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o -MF CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o.d -o CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmapfunctions.c

CMakeFiles/test_hashmap.dir/hashmapfunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_hashmap.dir/hashmapfunctions.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmapfunctions.c > CMakeFiles/test_hashmap.dir/hashmapfunctions.c.i

CMakeFiles/test_hashmap.dir/hashmapfunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_hashmap.dir/hashmapfunctions.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/hashmapfunctions.c -o CMakeFiles/test_hashmap.dir/hashmapfunctions.c.s

CMakeFiles/test_hashmap.dir/pair.c.o: CMakeFiles/test_hashmap.dir/flags.make
CMakeFiles/test_hashmap.dir/pair.c.o: /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/pair.c
CMakeFiles/test_hashmap.dir/pair.c.o: CMakeFiles/test_hashmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/test_hashmap.dir/pair.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hashmap.dir/pair.c.o -MF CMakeFiles/test_hashmap.dir/pair.c.o.d -o CMakeFiles/test_hashmap.dir/pair.c.o -c /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/pair.c

CMakeFiles/test_hashmap.dir/pair.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_hashmap.dir/pair.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/pair.c > CMakeFiles/test_hashmap.dir/pair.c.i

CMakeFiles/test_hashmap.dir/pair.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_hashmap.dir/pair.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/pair.c -o CMakeFiles/test_hashmap.dir/pair.c.s

# Object files for target test_hashmap
test_hashmap_OBJECTS = \
"CMakeFiles/test_hashmap.dir/test_hashmap.c.o" \
"CMakeFiles/test_hashmap.dir/hashmap.c.o" \
"CMakeFiles/test_hashmap.dir/list.c.o" \
"CMakeFiles/test_hashmap.dir/test_main.c.o" \
"CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o" \
"CMakeFiles/test_hashmap.dir/pair.c.o"

# External object files for target test_hashmap
test_hashmap_EXTERNAL_OBJECTS =

test_hashmap: CMakeFiles/test_hashmap.dir/test_hashmap.c.o
test_hashmap: CMakeFiles/test_hashmap.dir/hashmap.c.o
test_hashmap: CMakeFiles/test_hashmap.dir/list.c.o
test_hashmap: CMakeFiles/test_hashmap.dir/test_main.c.o
test_hashmap: CMakeFiles/test_hashmap.dir/hashmapfunctions.c.o
test_hashmap: CMakeFiles/test_hashmap.dir/pair.c.o
test_hashmap: CMakeFiles/test_hashmap.dir/build.make
test_hashmap: CMakeFiles/test_hashmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable test_hashmap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_hashmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_hashmap.dir/build: test_hashmap
.PHONY : CMakeFiles/test_hashmap.dir/build

CMakeFiles/test_hashmap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_hashmap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_hashmap.dir/clean

CMakeFiles/test_hashmap.dir/depend:
	cd /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/AlgorithmsAndDatastructures/Week8/hashing /mnt/c/AlgorithmsAndDatastructures/Week8/hashing /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build /mnt/c/AlgorithmsAndDatastructures/Week8/hashing/build/CMakeFiles/test_hashmap.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_hashmap.dir/depend

