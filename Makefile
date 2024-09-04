# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/jakob/Documents/pajkDesktop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakob/Documents/pajkDesktop

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jakob/Documents/pajkDesktop/CMakeFiles /home/jakob/Documents/pajkDesktop//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jakob/Documents/pajkDesktop/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named pajk

# Build rule for target.
pajk: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 pajk
.PHONY : pajk

# fast build rule for target.
pajk/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/build
.PHONY : pajk/fast

glad/glad.o: glad/glad.c.o
.PHONY : glad/glad.o

# target to build an object file
glad/glad.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/glad/glad.c.o
.PHONY : glad/glad.c.o

glad/glad.i: glad/glad.c.i
.PHONY : glad/glad.i

# target to preprocess a source file
glad/glad.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/glad/glad.c.i
.PHONY : glad/glad.c.i

glad/glad.s: glad/glad.c.s
.PHONY : glad/glad.s

# target to generate assembly for a file
glad/glad.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/glad/glad.c.s
.PHONY : glad/glad.c.s

src/bmpCreator.o: src/bmpCreator.cpp.o
.PHONY : src/bmpCreator.o

# target to build an object file
src/bmpCreator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/bmpCreator.cpp.o
.PHONY : src/bmpCreator.cpp.o

src/bmpCreator.i: src/bmpCreator.cpp.i
.PHONY : src/bmpCreator.i

# target to preprocess a source file
src/bmpCreator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/bmpCreator.cpp.i
.PHONY : src/bmpCreator.cpp.i

src/bmpCreator.s: src/bmpCreator.cpp.s
.PHONY : src/bmpCreator.s

# target to generate assembly for a file
src/bmpCreator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/bmpCreator.cpp.s
.PHONY : src/bmpCreator.cpp.s

src/gcodeInterpreter.o: src/gcodeInterpreter.cpp.o
.PHONY : src/gcodeInterpreter.o

# target to build an object file
src/gcodeInterpreter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.o
.PHONY : src/gcodeInterpreter.cpp.o

src/gcodeInterpreter.i: src/gcodeInterpreter.cpp.i
.PHONY : src/gcodeInterpreter.i

# target to preprocess a source file
src/gcodeInterpreter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.i
.PHONY : src/gcodeInterpreter.cpp.i

src/gcodeInterpreter.s: src/gcodeInterpreter.cpp.s
.PHONY : src/gcodeInterpreter.s

# target to generate assembly for a file
src/gcodeInterpreter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/gcodeInterpreter.cpp.s
.PHONY : src/gcodeInterpreter.cpp.s

src/glRasterizer.o: src/glRasterizer.cpp.o
.PHONY : src/glRasterizer.o

# target to build an object file
src/glRasterizer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/glRasterizer.cpp.o
.PHONY : src/glRasterizer.cpp.o

src/glRasterizer.i: src/glRasterizer.cpp.i
.PHONY : src/glRasterizer.i

# target to preprocess a source file
src/glRasterizer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/glRasterizer.cpp.i
.PHONY : src/glRasterizer.cpp.i

src/glRasterizer.s: src/glRasterizer.cpp.s
.PHONY : src/glRasterizer.s

# target to generate assembly for a file
src/glRasterizer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/glRasterizer.cpp.s
.PHONY : src/glRasterizer.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pajk.dir/build.make CMakeFiles/pajk.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... pajk"
	@echo "... glad/glad.o"
	@echo "... glad/glad.i"
	@echo "... glad/glad.s"
	@echo "... src/bmpCreator.o"
	@echo "... src/bmpCreator.i"
	@echo "... src/bmpCreator.s"
	@echo "... src/gcodeInterpreter.o"
	@echo "... src/gcodeInterpreter.i"
	@echo "... src/gcodeInterpreter.s"
	@echo "... src/glRasterizer.o"
	@echo "... src/glRasterizer.i"
	@echo "... src/glRasterizer.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

