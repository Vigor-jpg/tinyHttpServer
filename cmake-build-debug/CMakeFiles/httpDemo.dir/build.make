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
CMAKE_COMMAND = /usr/local/program/cmake-3.17.5/bin/cmake

# The command to remove a file.
RM = /usr/local/program/cmake-3.17.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/local/clion/httpDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/clion/httpDemo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/httpDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/httpDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/httpDemo.dir/flags.make

CMakeFiles/httpDemo.dir/Http/utils.cpp.o: CMakeFiles/httpDemo.dir/flags.make
CMakeFiles/httpDemo.dir/Http/utils.cpp.o: ../Http/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/local/clion/httpDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/httpDemo.dir/Http/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/httpDemo.dir/Http/utils.cpp.o -c /usr/local/clion/httpDemo/Http/utils.cpp

CMakeFiles/httpDemo.dir/Http/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpDemo.dir/Http/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/clion/httpDemo/Http/utils.cpp > CMakeFiles/httpDemo.dir/Http/utils.cpp.i

CMakeFiles/httpDemo.dir/Http/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpDemo.dir/Http/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/clion/httpDemo/Http/utils.cpp -o CMakeFiles/httpDemo.dir/Http/utils.cpp.s

CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.o: CMakeFiles/httpDemo.dir/flags.make
CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.o: ../Http/MyHttpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/local/clion/httpDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.o -c /usr/local/clion/httpDemo/Http/MyHttpServer.cpp

CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/clion/httpDemo/Http/MyHttpServer.cpp > CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.i

CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/clion/httpDemo/Http/MyHttpServer.cpp -o CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.s

CMakeFiles/httpDemo.dir/main.cpp.o: CMakeFiles/httpDemo.dir/flags.make
CMakeFiles/httpDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/local/clion/httpDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/httpDemo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/httpDemo.dir/main.cpp.o -c /usr/local/clion/httpDemo/main.cpp

CMakeFiles/httpDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpDemo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/clion/httpDemo/main.cpp > CMakeFiles/httpDemo.dir/main.cpp.i

CMakeFiles/httpDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpDemo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/clion/httpDemo/main.cpp -o CMakeFiles/httpDemo.dir/main.cpp.s

# Object files for target httpDemo
httpDemo_OBJECTS = \
"CMakeFiles/httpDemo.dir/Http/utils.cpp.o" \
"CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.o" \
"CMakeFiles/httpDemo.dir/main.cpp.o"

# External object files for target httpDemo
httpDemo_EXTERNAL_OBJECTS =

httpDemo: CMakeFiles/httpDemo.dir/Http/utils.cpp.o
httpDemo: CMakeFiles/httpDemo.dir/Http/MyHttpServer.cpp.o
httpDemo: CMakeFiles/httpDemo.dir/main.cpp.o
httpDemo: CMakeFiles/httpDemo.dir/build.make
httpDemo: CMakeFiles/httpDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/local/clion/httpDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable httpDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/httpDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/httpDemo.dir/build: httpDemo

.PHONY : CMakeFiles/httpDemo.dir/build

CMakeFiles/httpDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/httpDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/httpDemo.dir/clean

CMakeFiles/httpDemo.dir/depend:
	cd /usr/local/clion/httpDemo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/clion/httpDemo /usr/local/clion/httpDemo /usr/local/clion/httpDemo/cmake-build-debug /usr/local/clion/httpDemo/cmake-build-debug /usr/local/clion/httpDemo/cmake-build-debug/CMakeFiles/httpDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/httpDemo.dir/depend

