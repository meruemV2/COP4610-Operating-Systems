# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jerry/CLionProjects/COP4610_UnixShell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/COP4610_UnixShell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COP4610_UnixShell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COP4610_UnixShell.dir/flags.make

CMakeFiles/COP4610_UnixShell.dir/shell.c.o: CMakeFiles/COP4610_UnixShell.dir/flags.make
CMakeFiles/COP4610_UnixShell.dir/shell.c.o: ../shell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/COP4610_UnixShell.dir/shell.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/COP4610_UnixShell.dir/shell.c.o   -c /Users/jerry/CLionProjects/COP4610_UnixShell/shell.c

CMakeFiles/COP4610_UnixShell.dir/shell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/COP4610_UnixShell.dir/shell.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jerry/CLionProjects/COP4610_UnixShell/shell.c > CMakeFiles/COP4610_UnixShell.dir/shell.c.i

CMakeFiles/COP4610_UnixShell.dir/shell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/COP4610_UnixShell.dir/shell.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jerry/CLionProjects/COP4610_UnixShell/shell.c -o CMakeFiles/COP4610_UnixShell.dir/shell.c.s

# Object files for target COP4610_UnixShell
COP4610_UnixShell_OBJECTS = \
"CMakeFiles/COP4610_UnixShell.dir/shell.c.o"

# External object files for target COP4610_UnixShell
COP4610_UnixShell_EXTERNAL_OBJECTS =

COP4610_UnixShell: CMakeFiles/COP4610_UnixShell.dir/shell.c.o
COP4610_UnixShell: CMakeFiles/COP4610_UnixShell.dir/build.make
COP4610_UnixShell: CMakeFiles/COP4610_UnixShell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable COP4610_UnixShell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COP4610_UnixShell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COP4610_UnixShell.dir/build: COP4610_UnixShell

.PHONY : CMakeFiles/COP4610_UnixShell.dir/build

CMakeFiles/COP4610_UnixShell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/COP4610_UnixShell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/COP4610_UnixShell.dir/clean

CMakeFiles/COP4610_UnixShell.dir/depend:
	cd /Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jerry/CLionProjects/COP4610_UnixShell /Users/jerry/CLionProjects/COP4610_UnixShell /Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug /Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug /Users/jerry/CLionProjects/COP4610_UnixShell/cmake-build-debug/CMakeFiles/COP4610_UnixShell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/COP4610_UnixShell.dir/depend

