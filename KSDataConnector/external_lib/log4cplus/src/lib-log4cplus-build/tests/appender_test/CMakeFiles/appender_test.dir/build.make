# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /root/Programs/cmake-3.2.0/bin/cmake

# The command to remove a file.
RM = /root/Programs/cmake-3.2.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build

# Include any dependencies generated for this target.
include tests/appender_test/CMakeFiles/appender_test.dir/depend.make

# Include the progress variables for this target.
include tests/appender_test/CMakeFiles/appender_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/appender_test/CMakeFiles/appender_test.dir/flags.make

tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o: tests/appender_test/CMakeFiles/appender_test.dir/flags.make
tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o: /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/tests/appender_test/main.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o"
	cd /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/appender_test.dir/main.cxx.o -c /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/tests/appender_test/main.cxx

tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/appender_test.dir/main.cxx.i"
	cd /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/tests/appender_test/main.cxx > CMakeFiles/appender_test.dir/main.cxx.i

tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/appender_test.dir/main.cxx.s"
	cd /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/tests/appender_test/main.cxx -o CMakeFiles/appender_test.dir/main.cxx.s

tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.requires:
.PHONY : tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.requires

tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.provides: tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.requires
	$(MAKE) -f tests/appender_test/CMakeFiles/appender_test.dir/build.make tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.provides.build
.PHONY : tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.provides

tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.provides.build: tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o

# Object files for target appender_test
appender_test_OBJECTS = \
"CMakeFiles/appender_test.dir/main.cxx.o"

# External object files for target appender_test
appender_test_EXTERNAL_OBJECTS =

bin/appender_test: tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o
bin/appender_test: tests/appender_test/CMakeFiles/appender_test.dir/build.make
bin/appender_test: src/liblog4cplus.so.1.2.0
bin/appender_test: /usr/lib/x86_64-linux-gnu/librt.so
bin/appender_test: /usr/lib/x86_64-linux-gnu/libnsl.so
bin/appender_test: tests/appender_test/CMakeFiles/appender_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/appender_test"
	cd /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/appender_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/appender_test/CMakeFiles/appender_test.dir/build: bin/appender_test
.PHONY : tests/appender_test/CMakeFiles/appender_test.dir/build

tests/appender_test/CMakeFiles/appender_test.dir/requires: tests/appender_test/CMakeFiles/appender_test.dir/main.cxx.o.requires
.PHONY : tests/appender_test/CMakeFiles/appender_test.dir/requires

tests/appender_test/CMakeFiles/appender_test.dir/clean:
	cd /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test && $(CMAKE_COMMAND) -P CMakeFiles/appender_test.dir/cmake_clean.cmake
.PHONY : tests/appender_test/CMakeFiles/appender_test.dir/clean

tests/appender_test/CMakeFiles/appender_test.dir/depend:
	cd /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus/tests/appender_test /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test /root/workspace/github/CPlusProject/KSDataConnector/external_lib/log4cplus/src/lib-log4cplus-build/tests/appender_test/CMakeFiles/appender_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/appender_test/CMakeFiles/appender_test.dir/depend

