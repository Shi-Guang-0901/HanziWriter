# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
SHELL = /data/data/com.termux/files/usr/bin/sh

# The CMake executable.
CMAKE_COMMAND = /data/data/com.termux/files/usr/bin/cmake

# The command to remove a file.
RM = /data/data/com.termux/files/usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/data/com.termux/files/home/clang/HanziWriter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/data/com.termux/files/home/clang/HanziWriter

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/data/data/com.termux/files/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/data/data/com.termux/files/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /data/data/com.termux/files/home/clang/HanziWriter/CMakeFiles /data/data/com.termux/files/home/clang/HanziWriter//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /data/data/com.termux/files/home/clang/HanziWriter/CMakeFiles 0
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
# Target rules for targets named HanziWriter

# Build rule for target.
HanziWriter: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 HanziWriter
.PHONY : HanziWriter

# fast build rule for target.
HanziWriter/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/build
.PHONY : HanziWriter/fast

file.o: file.cpp.o
.PHONY : file.o

# target to build an object file
file.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/file.cpp.o
.PHONY : file.cpp.o

file.i: file.cpp.i
.PHONY : file.i

# target to preprocess a source file
file.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/file.cpp.i
.PHONY : file.cpp.i

file.s: file.cpp.s
.PHONY : file.s

# target to generate assembly for a file
file.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/file.cpp.s
.PHONY : file.cpp.s

info.o: info.cpp.o
.PHONY : info.o

# target to build an object file
info.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/info.cpp.o
.PHONY : info.cpp.o

info.i: info.cpp.i
.PHONY : info.i

# target to preprocess a source file
info.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/info.cpp.i
.PHONY : info.cpp.i

info.s: info.cpp.s
.PHONY : info.s

# target to generate assembly for a file
info.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/info.cpp.s
.PHONY : info.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/main.cpp.s
.PHONY : main.cpp.s

sstring.o: sstring.cpp.o
.PHONY : sstring.o

# target to build an object file
sstring.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/sstring.cpp.o
.PHONY : sstring.cpp.o

sstring.i: sstring.cpp.i
.PHONY : sstring.i

# target to preprocess a source file
sstring.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/sstring.cpp.i
.PHONY : sstring.cpp.i

sstring.s: sstring.cpp.s
.PHONY : sstring.s

# target to generate assembly for a file
sstring.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/sstring.cpp.s
.PHONY : sstring.cpp.s

tools.o: tools.cpp.o
.PHONY : tools.o

# target to build an object file
tools.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/tools.cpp.o
.PHONY : tools.cpp.o

tools.i: tools.cpp.i
.PHONY : tools.i

# target to preprocess a source file
tools.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/tools.cpp.i
.PHONY : tools.cpp.i

tools.s: tools.cpp.s
.PHONY : tools.s

# target to generate assembly for a file
tools.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/tools.cpp.s
.PHONY : tools.cpp.s

utf8.o: utf8.cpp.o
.PHONY : utf8.o

# target to build an object file
utf8.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/utf8.cpp.o
.PHONY : utf8.cpp.o

utf8.i: utf8.cpp.i
.PHONY : utf8.i

# target to preprocess a source file
utf8.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/utf8.cpp.i
.PHONY : utf8.cpp.i

utf8.s: utf8.cpp.s
.PHONY : utf8.s

# target to generate assembly for a file
utf8.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HanziWriter.dir/build.make CMakeFiles/HanziWriter.dir/utf8.cpp.s
.PHONY : utf8.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... HanziWriter"
	@echo "... file.o"
	@echo "... file.i"
	@echo "... file.s"
	@echo "... info.o"
	@echo "... info.i"
	@echo "... info.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... sstring.o"
	@echo "... sstring.i"
	@echo "... sstring.s"
	@echo "... tools.o"
	@echo "... tools.i"
	@echo "... tools.s"
	@echo "... utf8.o"
	@echo "... utf8.i"
	@echo "... utf8.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
