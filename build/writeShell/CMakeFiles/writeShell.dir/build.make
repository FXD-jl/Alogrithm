# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jl/Documents/Alogrithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jl/Documents/Alogrithm/build

# Include any dependencies generated for this target.
include writeShell/CMakeFiles/writeShell.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include writeShell/CMakeFiles/writeShell.dir/compiler_depend.make

# Include the progress variables for this target.
include writeShell/CMakeFiles/writeShell.dir/progress.make

# Include the compile flags for this target's objects.
include writeShell/CMakeFiles/writeShell.dir/flags.make

writeShell/CMakeFiles/writeShell.dir/src/main.c.o: writeShell/CMakeFiles/writeShell.dir/flags.make
writeShell/CMakeFiles/writeShell.dir/src/main.c.o: /Users/jl/Documents/Alogrithm/writeShell/src/main.c
writeShell/CMakeFiles/writeShell.dir/src/main.c.o: writeShell/CMakeFiles/writeShell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jl/Documents/Alogrithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object writeShell/CMakeFiles/writeShell.dir/src/main.c.o"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT writeShell/CMakeFiles/writeShell.dir/src/main.c.o -MF CMakeFiles/writeShell.dir/src/main.c.o.d -o CMakeFiles/writeShell.dir/src/main.c.o -c /Users/jl/Documents/Alogrithm/writeShell/src/main.c

writeShell/CMakeFiles/writeShell.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/writeShell.dir/src/main.c.i"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jl/Documents/Alogrithm/writeShell/src/main.c > CMakeFiles/writeShell.dir/src/main.c.i

writeShell/CMakeFiles/writeShell.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/writeShell.dir/src/main.c.s"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jl/Documents/Alogrithm/writeShell/src/main.c -o CMakeFiles/writeShell.dir/src/main.c.s

writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.o: writeShell/CMakeFiles/writeShell.dir/flags.make
writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.o: /Users/jl/Documents/Alogrithm/writeShell/src/writeShell.c
writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.o: writeShell/CMakeFiles/writeShell.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jl/Documents/Alogrithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.o"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.o -MF CMakeFiles/writeShell.dir/src/writeShell.c.o.d -o CMakeFiles/writeShell.dir/src/writeShell.c.o -c /Users/jl/Documents/Alogrithm/writeShell/src/writeShell.c

writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/writeShell.dir/src/writeShell.c.i"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jl/Documents/Alogrithm/writeShell/src/writeShell.c > CMakeFiles/writeShell.dir/src/writeShell.c.i

writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/writeShell.dir/src/writeShell.c.s"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jl/Documents/Alogrithm/writeShell/src/writeShell.c -o CMakeFiles/writeShell.dir/src/writeShell.c.s

# Object files for target writeShell
writeShell_OBJECTS = \
"CMakeFiles/writeShell.dir/src/main.c.o" \
"CMakeFiles/writeShell.dir/src/writeShell.c.o"

# External object files for target writeShell
writeShell_EXTERNAL_OBJECTS =

writeShell/writeShell: writeShell/CMakeFiles/writeShell.dir/src/main.c.o
writeShell/writeShell: writeShell/CMakeFiles/writeShell.dir/src/writeShell.c.o
writeShell/writeShell: writeShell/CMakeFiles/writeShell.dir/build.make
writeShell/writeShell: writeShell/CMakeFiles/writeShell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jl/Documents/Alogrithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable writeShell"
	cd /Users/jl/Documents/Alogrithm/build/writeShell && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/writeShell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
writeShell/CMakeFiles/writeShell.dir/build: writeShell/writeShell
.PHONY : writeShell/CMakeFiles/writeShell.dir/build

writeShell/CMakeFiles/writeShell.dir/clean:
	cd /Users/jl/Documents/Alogrithm/build/writeShell && $(CMAKE_COMMAND) -P CMakeFiles/writeShell.dir/cmake_clean.cmake
.PHONY : writeShell/CMakeFiles/writeShell.dir/clean

writeShell/CMakeFiles/writeShell.dir/depend:
	cd /Users/jl/Documents/Alogrithm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jl/Documents/Alogrithm /Users/jl/Documents/Alogrithm/writeShell /Users/jl/Documents/Alogrithm/build /Users/jl/Documents/Alogrithm/build/writeShell /Users/jl/Documents/Alogrithm/build/writeShell/CMakeFiles/writeShell.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : writeShell/CMakeFiles/writeShell.dir/depend

