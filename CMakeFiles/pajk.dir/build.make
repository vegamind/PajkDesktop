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
CMAKE_SOURCE_DIR = /home/jakob/Documents/PajkDesktop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakob/Documents/PajkDesktop

# Include any dependencies generated for this target.
include CMakeFiles/pajk.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pajk.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pajk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pajk.dir/flags.make

CMakeFiles/pajk.dir/src/bmpCreator.cpp.o: CMakeFiles/pajk.dir/flags.make
CMakeFiles/pajk.dir/src/bmpCreator.cpp.o: src/bmpCreator.cpp
CMakeFiles/pajk.dir/src/bmpCreator.cpp.o: CMakeFiles/pajk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jakob/Documents/PajkDesktop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pajk.dir/src/bmpCreator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pajk.dir/src/bmpCreator.cpp.o -MF CMakeFiles/pajk.dir/src/bmpCreator.cpp.o.d -o CMakeFiles/pajk.dir/src/bmpCreator.cpp.o -c /home/jakob/Documents/PajkDesktop/src/bmpCreator.cpp

CMakeFiles/pajk.dir/src/bmpCreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pajk.dir/src/bmpCreator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakob/Documents/PajkDesktop/src/bmpCreator.cpp > CMakeFiles/pajk.dir/src/bmpCreator.cpp.i

CMakeFiles/pajk.dir/src/bmpCreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pajk.dir/src/bmpCreator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakob/Documents/PajkDesktop/src/bmpCreator.cpp -o CMakeFiles/pajk.dir/src/bmpCreator.cpp.s

CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o: CMakeFiles/pajk.dir/flags.make
CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o: src/gcodeInterpreter.cpp
CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o: CMakeFiles/pajk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jakob/Documents/PajkDesktop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o -MF CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o.d -o CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o -c /home/jakob/Documents/PajkDesktop/src/gcodeInterpreter.cpp

CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakob/Documents/PajkDesktop/src/gcodeInterpreter.cpp > CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.i

CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakob/Documents/PajkDesktop/src/gcodeInterpreter.cpp -o CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.s

CMakeFiles/pajk.dir/src/glRasterizer.cpp.o: CMakeFiles/pajk.dir/flags.make
CMakeFiles/pajk.dir/src/glRasterizer.cpp.o: src/glRasterizer.cpp
CMakeFiles/pajk.dir/src/glRasterizer.cpp.o: CMakeFiles/pajk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jakob/Documents/PajkDesktop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pajk.dir/src/glRasterizer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pajk.dir/src/glRasterizer.cpp.o -MF CMakeFiles/pajk.dir/src/glRasterizer.cpp.o.d -o CMakeFiles/pajk.dir/src/glRasterizer.cpp.o -c /home/jakob/Documents/PajkDesktop/src/glRasterizer.cpp

CMakeFiles/pajk.dir/src/glRasterizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pajk.dir/src/glRasterizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakob/Documents/PajkDesktop/src/glRasterizer.cpp > CMakeFiles/pajk.dir/src/glRasterizer.cpp.i

CMakeFiles/pajk.dir/src/glRasterizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pajk.dir/src/glRasterizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakob/Documents/PajkDesktop/src/glRasterizer.cpp -o CMakeFiles/pajk.dir/src/glRasterizer.cpp.s

CMakeFiles/pajk.dir/src/main.cpp.o: CMakeFiles/pajk.dir/flags.make
CMakeFiles/pajk.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/pajk.dir/src/main.cpp.o: CMakeFiles/pajk.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jakob/Documents/PajkDesktop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pajk.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pajk.dir/src/main.cpp.o -MF CMakeFiles/pajk.dir/src/main.cpp.o.d -o CMakeFiles/pajk.dir/src/main.cpp.o -c /home/jakob/Documents/PajkDesktop/src/main.cpp

CMakeFiles/pajk.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pajk.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakob/Documents/PajkDesktop/src/main.cpp > CMakeFiles/pajk.dir/src/main.cpp.i

CMakeFiles/pajk.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pajk.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakob/Documents/PajkDesktop/src/main.cpp -o CMakeFiles/pajk.dir/src/main.cpp.s

# Object files for target pajk
pajk_OBJECTS = \
"CMakeFiles/pajk.dir/src/bmpCreator.cpp.o" \
"CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o" \
"CMakeFiles/pajk.dir/src/glRasterizer.cpp.o" \
"CMakeFiles/pajk.dir/src/main.cpp.o"

# External object files for target pajk
pajk_EXTERNAL_OBJECTS =

pajk: CMakeFiles/pajk.dir/src/bmpCreator.cpp.o
pajk: CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o
pajk: CMakeFiles/pajk.dir/src/glRasterizer.cpp.o
pajk: CMakeFiles/pajk.dir/src/main.cpp.o
pajk: CMakeFiles/pajk.dir/build.make
pajk: CMakeFiles/pajk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jakob/Documents/PajkDesktop/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable pajk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pajk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pajk.dir/build: pajk
.PHONY : CMakeFiles/pajk.dir/build

CMakeFiles/pajk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pajk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pajk.dir/clean

CMakeFiles/pajk.dir/depend:
	cd /home/jakob/Documents/PajkDesktop && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakob/Documents/PajkDesktop /home/jakob/Documents/PajkDesktop /home/jakob/Documents/PajkDesktop /home/jakob/Documents/PajkDesktop /home/jakob/Documents/PajkDesktop/CMakeFiles/pajk.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pajk.dir/depend

