# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\HW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\HW\build

# Include any dependencies generated for this target.
include test/CMakeFiles/Tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/Tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Tests.dir/flags.make

test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj: test/CMakeFiles/Tests.dir/flags.make
test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj: test/CMakeFiles/Tests.dir/includes_CXX.rsp
test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj: D:/HW/src/atp/ATPElement.cpp
test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj: test/CMakeFiles/Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\HW\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj -MF CMakeFiles\Tests.dir\__\src\atp\ATPElement.cpp.obj.d -o CMakeFiles\Tests.dir\__\src\atp\ATPElement.cpp.obj -c D:\HW\src\atp\ATPElement.cpp

test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.i"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HW\src\atp\ATPElement.cpp > CMakeFiles\Tests.dir\__\src\atp\ATPElement.cpp.i

test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.s"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HW\src\atp\ATPElement.cpp -o CMakeFiles\Tests.dir\__\src\atp\ATPElement.cpp.s

test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj: test/CMakeFiles/Tests.dir/flags.make
test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj: test/CMakeFiles/Tests.dir/includes_CXX.rsp
test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj: D:/HW/src/atp/ATPTreeGenerator.cpp
test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj: test/CMakeFiles/Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\HW\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj -MF CMakeFiles\Tests.dir\__\src\atp\ATPTreeGenerator.cpp.obj.d -o CMakeFiles\Tests.dir\__\src\atp\ATPTreeGenerator.cpp.obj -c D:\HW\src\atp\ATPTreeGenerator.cpp

test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.i"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HW\src\atp\ATPTreeGenerator.cpp > CMakeFiles\Tests.dir\__\src\atp\ATPTreeGenerator.cpp.i

test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.s"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HW\src\atp\ATPTreeGenerator.cpp -o CMakeFiles\Tests.dir\__\src\atp\ATPTreeGenerator.cpp.s

test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj: test/CMakeFiles/Tests.dir/flags.make
test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj: test/CMakeFiles/Tests.dir/includes_CXX.rsp
test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj: D:/HW/src/atp/Commands.cpp
test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj: test/CMakeFiles/Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\HW\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj -MF CMakeFiles\Tests.dir\__\src\atp\Commands.cpp.obj.d -o CMakeFiles\Tests.dir\__\src\atp\Commands.cpp.obj -c D:\HW\src\atp\Commands.cpp

test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.i"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HW\src\atp\Commands.cpp > CMakeFiles\Tests.dir\__\src\atp\Commands.cpp.i

test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.s"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HW\src\atp\Commands.cpp -o CMakeFiles\Tests.dir\__\src\atp\Commands.cpp.s

test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj: test/CMakeFiles/Tests.dir/flags.make
test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj: test/CMakeFiles/Tests.dir/includes_CXX.rsp
test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj: D:/HW/src/atp/Runner.cpp
test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj: test/CMakeFiles/Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\HW\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj -MF CMakeFiles\Tests.dir\__\src\atp\Runner.cpp.obj.d -o CMakeFiles\Tests.dir\__\src\atp\Runner.cpp.obj -c D:\HW\src\atp\Runner.cpp

test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.i"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\HW\src\atp\Runner.cpp > CMakeFiles\Tests.dir\__\src\atp\Runner.cpp.i

test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.s"
	cd /d D:\HW\build\test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\HW\src\atp\Runner.cpp -o CMakeFiles\Tests.dir\__\src\atp\Runner.cpp.s

# Object files for target Tests
Tests_OBJECTS = \
"CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj" \
"CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj" \
"CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj" \
"CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj"

# External object files for target Tests
Tests_EXTERNAL_OBJECTS =

test/Tests.exe: test/CMakeFiles/Tests.dir/__/src/atp/ATPElement.cpp.obj
test/Tests.exe: test/CMakeFiles/Tests.dir/__/src/atp/ATPTreeGenerator.cpp.obj
test/Tests.exe: test/CMakeFiles/Tests.dir/__/src/atp/Commands.cpp.obj
test/Tests.exe: test/CMakeFiles/Tests.dir/__/src/atp/Runner.cpp.obj
test/Tests.exe: test/CMakeFiles/Tests.dir/build.make
test/Tests.exe: src/atp/libatp.a
test/Tests.exe: test/CMakeFiles/Tests.dir/linkLibs.rsp
test/Tests.exe: test/CMakeFiles/Tests.dir/objects1.rsp
test/Tests.exe: test/CMakeFiles/Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\HW\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Tests.exe"
	cd /d D:\HW\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/Tests.dir/build: test/Tests.exe
.PHONY : test/CMakeFiles/Tests.dir/build

test/CMakeFiles/Tests.dir/clean:
	cd /d D:\HW\build\test && $(CMAKE_COMMAND) -P CMakeFiles\Tests.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/Tests.dir/clean

test/CMakeFiles/Tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\HW D:\HW\test D:\HW\build D:\HW\build\test D:\HW\build\test\CMakeFiles\Tests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Tests.dir/depend
