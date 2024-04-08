# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/hyperwin/d/Projects/HyperCPU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hyperwin/d/Projects/HyperCPU/build

# Include any dependencies generated for this target.
include src/CMakeFiles/emulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/emulator.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/emulator.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/emulator.dir/flags.make

src/CMakeFiles/emulator.dir/cpu.cpp.o: src/CMakeFiles/emulator.dir/flags.make
src/CMakeFiles/emulator.dir/cpu.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp
src/CMakeFiles/emulator.dir/cpu.cpp.o: src/CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/emulator.dir/cpu.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/emulator.dir/cpu.cpp.o -MF CMakeFiles/emulator.dir/cpu.cpp.o.d -o CMakeFiles/emulator.dir/cpu.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp

src/CMakeFiles/emulator.dir/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/cpu.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp > CMakeFiles/emulator.dir/cpu.cpp.i

src/CMakeFiles/emulator.dir/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/cpu.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp -o CMakeFiles/emulator.dir/cpu.cpp.s

src/CMakeFiles/emulator.dir/opcode_handler.cpp.o: src/CMakeFiles/emulator.dir/flags.make
src/CMakeFiles/emulator.dir/opcode_handler.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp
src/CMakeFiles/emulator.dir/opcode_handler.cpp.o: src/CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/emulator.dir/opcode_handler.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/emulator.dir/opcode_handler.cpp.o -MF CMakeFiles/emulator.dir/opcode_handler.cpp.o.d -o CMakeFiles/emulator.dir/opcode_handler.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp

src/CMakeFiles/emulator.dir/opcode_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/opcode_handler.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp > CMakeFiles/emulator.dir/opcode_handler.cpp.i

src/CMakeFiles/emulator.dir/opcode_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/opcode_handler.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp -o CMakeFiles/emulator.dir/opcode_handler.cpp.s

src/CMakeFiles/emulator.dir/instructions.cpp.o: src/CMakeFiles/emulator.dir/flags.make
src/CMakeFiles/emulator.dir/instructions.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/instructions.cpp
src/CMakeFiles/emulator.dir/instructions.cpp.o: src/CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/emulator.dir/instructions.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/emulator.dir/instructions.cpp.o -MF CMakeFiles/emulator.dir/instructions.cpp.o.d -o CMakeFiles/emulator.dir/instructions.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/instructions.cpp

src/CMakeFiles/emulator.dir/instructions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/instructions.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/instructions.cpp > CMakeFiles/emulator.dir/instructions.cpp.i

src/CMakeFiles/emulator.dir/instructions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/instructions.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/instructions.cpp -o CMakeFiles/emulator.dir/instructions.cpp.s

src/CMakeFiles/emulator.dir/stack.cpp.o: src/CMakeFiles/emulator.dir/flags.make
src/CMakeFiles/emulator.dir/stack.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/stack.cpp
src/CMakeFiles/emulator.dir/stack.cpp.o: src/CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/emulator.dir/stack.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/emulator.dir/stack.cpp.o -MF CMakeFiles/emulator.dir/stack.cpp.o.d -o CMakeFiles/emulator.dir/stack.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/stack.cpp

src/CMakeFiles/emulator.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/stack.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/stack.cpp > CMakeFiles/emulator.dir/stack.cpp.i

src/CMakeFiles/emulator.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/stack.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/stack.cpp -o CMakeFiles/emulator.dir/stack.cpp.s

src/CMakeFiles/emulator.dir/main.cpp.o: src/CMakeFiles/emulator.dir/flags.make
src/CMakeFiles/emulator.dir/main.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/main.cpp
src/CMakeFiles/emulator.dir/main.cpp.o: src/CMakeFiles/emulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/emulator.dir/main.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/emulator.dir/main.cpp.o -MF CMakeFiles/emulator.dir/main.cpp.o.d -o CMakeFiles/emulator.dir/main.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/main.cpp

src/CMakeFiles/emulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/emulator.dir/main.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/main.cpp > CMakeFiles/emulator.dir/main.cpp.i

src/CMakeFiles/emulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/emulator.dir/main.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/main.cpp -o CMakeFiles/emulator.dir/main.cpp.s

# Object files for target emulator
emulator_OBJECTS = \
"CMakeFiles/emulator.dir/cpu.cpp.o" \
"CMakeFiles/emulator.dir/opcode_handler.cpp.o" \
"CMakeFiles/emulator.dir/instructions.cpp.o" \
"CMakeFiles/emulator.dir/stack.cpp.o" \
"CMakeFiles/emulator.dir/main.cpp.o"

# External object files for target emulator
emulator_EXTERNAL_OBJECTS =

emulator: src/CMakeFiles/emulator.dir/cpu.cpp.o
emulator: src/CMakeFiles/emulator.dir/opcode_handler.cpp.o
emulator: src/CMakeFiles/emulator.dir/instructions.cpp.o
emulator: src/CMakeFiles/emulator.dir/stack.cpp.o
emulator: src/CMakeFiles/emulator.dir/main.cpp.o
emulator: src/CMakeFiles/emulator.dir/build.make
emulator: src/CMakeFiles/emulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../emulator"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/emulator.dir/build: emulator
.PHONY : src/CMakeFiles/emulator.dir/build

src/CMakeFiles/emulator.dir/clean:
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && $(CMAKE_COMMAND) -P CMakeFiles/emulator.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/emulator.dir/clean

src/CMakeFiles/emulator.dir/depend:
	cd /home/hyperwin/d/Projects/HyperCPU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyperwin/d/Projects/HyperCPU /home/hyperwin/d/Projects/HyperCPU/src /home/hyperwin/d/Projects/HyperCPU/build /home/hyperwin/d/Projects/HyperCPU/build/src /home/hyperwin/d/Projects/HyperCPU/build/src/CMakeFiles/emulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/emulator.dir/depend

