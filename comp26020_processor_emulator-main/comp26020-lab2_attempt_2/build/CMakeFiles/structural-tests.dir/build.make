# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build

# Include any dependencies generated for this target.
include CMakeFiles/structural-tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/structural-tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/structural-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/structural-tests.dir/flags.make

CMakeFiles/structural-tests.dir/structural-tests.cpp.o: CMakeFiles/structural-tests.dir/flags.make
CMakeFiles/structural-tests.dir/structural-tests.cpp.o: ../structural-tests.cpp
CMakeFiles/structural-tests.dir/structural-tests.cpp.o: CMakeFiles/structural-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/structural-tests.dir/structural-tests.cpp.o"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/structural-tests.dir/structural-tests.cpp.o -MF CMakeFiles/structural-tests.dir/structural-tests.cpp.o.d -o CMakeFiles/structural-tests.dir/structural-tests.cpp.o -c /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/structural-tests.cpp

CMakeFiles/structural-tests.dir/structural-tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/structural-tests.dir/structural-tests.cpp.i"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/structural-tests.cpp > CMakeFiles/structural-tests.dir/structural-tests.cpp.i

CMakeFiles/structural-tests.dir/structural-tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/structural-tests.dir/structural-tests.cpp.s"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/structural-tests.cpp -o CMakeFiles/structural-tests.dir/structural-tests.cpp.s

# Object files for target structural-tests
structural__tests_OBJECTS = \
"CMakeFiles/structural-tests.dir/structural-tests.cpp.o"

# External object files for target structural-tests
structural__tests_EXTERNAL_OBJECTS =

structural-tests: CMakeFiles/structural-tests.dir/structural-tests.cpp.o
structural-tests: CMakeFiles/structural-tests.dir/build.make
structural-tests: libemulator.a
structural-tests: libcatch.a
structural-tests: CMakeFiles/structural-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable structural-tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/structural-tests.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=structural-tests -D TEST_EXECUTABLE=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build/structural-tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2 -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=structural-tests_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D TEST_DL_PATHS= -D TEST_DL_FRAMEWORK_PATHS= -D CTEST_FILE=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build/structural-tests-b12d07c_tests.cmake -P /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/CatchAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/structural-tests.dir/build: structural-tests
.PHONY : CMakeFiles/structural-tests.dir/build

CMakeFiles/structural-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/structural-tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/structural-tests.dir/clean

CMakeFiles/structural-tests.dir/depend:
	cd /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2 /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2 /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2_attempt_2/build/CMakeFiles/structural-tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/structural-tests.dir/depend

