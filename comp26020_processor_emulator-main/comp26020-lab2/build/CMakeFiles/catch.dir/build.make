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
CMAKE_SOURCE_DIR = /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build

# Include any dependencies generated for this target.
include CMakeFiles/catch.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/catch.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/catch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/catch.dir/flags.make

CMakeFiles/catch.dir/catch.cpp.o: CMakeFiles/catch.dir/flags.make
CMakeFiles/catch.dir/catch.cpp.o: ../catch.cpp
CMakeFiles/catch.dir/catch.cpp.o: CMakeFiles/catch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/catch.dir/catch.cpp.o"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/catch.dir/catch.cpp.o -MF CMakeFiles/catch.dir/catch.cpp.o.d -o CMakeFiles/catch.dir/catch.cpp.o -c /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/catch.cpp

CMakeFiles/catch.dir/catch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch.dir/catch.cpp.i"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/catch.cpp > CMakeFiles/catch.dir/catch.cpp.i

CMakeFiles/catch.dir/catch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch.dir/catch.cpp.s"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/catch.cpp -o CMakeFiles/catch.dir/catch.cpp.s

# Object files for target catch
catch_OBJECTS = \
"CMakeFiles/catch.dir/catch.cpp.o"

# External object files for target catch
catch_EXTERNAL_OBJECTS =

libcatch.a: CMakeFiles/catch.dir/catch.cpp.o
libcatch.a: CMakeFiles/catch.dir/build.make
libcatch.a: CMakeFiles/catch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcatch.a"
	$(CMAKE_COMMAND) -P CMakeFiles/catch.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/catch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/catch.dir/build: libcatch.a
.PHONY : CMakeFiles/catch.dir/build

CMakeFiles/catch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/catch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/catch.dir/clean

CMakeFiles/catch.dir/depend:
	cd /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2 /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2 /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build /workspaces/comp26020_processor_emulator-main/comp26020_processor_emulator-main/comp26020-lab2/build/CMakeFiles/catch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/catch.dir/depend

