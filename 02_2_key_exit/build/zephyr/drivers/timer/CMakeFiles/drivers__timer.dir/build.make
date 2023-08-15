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
CMAKE_SOURCE_DIR = /home/hyc/zephyrproject/hyc/02_2_key_exit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hyc/zephyrproject/hyc/02_2_key_exit/build

# Include any dependencies generated for this target.
include zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/compiler_depend.make

# Include the progress variables for this target.
include zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/progress.make

# Include the compile flags for this target's objects.
include zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/flags.make

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/flags.make
zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj: /home/hyc/zephyrproject/zephyr/drivers/timer/sys_clock_init.c
zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyc/zephyrproject/hyc/02_2_key_exit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && ccache /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj -MF CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj.d -o CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj -c /home/hyc/zephyrproject/zephyr/drivers/timer/sys_clock_init.c

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drivers__timer.dir/sys_clock_init.c.i"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hyc/zephyrproject/zephyr/drivers/timer/sys_clock_init.c > CMakeFiles/drivers__timer.dir/sys_clock_init.c.i

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drivers__timer.dir/sys_clock_init.c.s"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hyc/zephyrproject/zephyr/drivers/timer/sys_clock_init.c -o CMakeFiles/drivers__timer.dir/sys_clock_init.c.s

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/flags.make
zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj: /home/hyc/zephyrproject/zephyr/drivers/timer/cortex_m_systick.c
zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyc/zephyrproject/hyc/02_2_key_exit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && ccache /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj -MF CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj.d -o CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj -c /home/hyc/zephyrproject/zephyr/drivers/timer/cortex_m_systick.c

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drivers__timer.dir/cortex_m_systick.c.i"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hyc/zephyrproject/zephyr/drivers/timer/cortex_m_systick.c > CMakeFiles/drivers__timer.dir/cortex_m_systick.c.i

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drivers__timer.dir/cortex_m_systick.c.s"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hyc/zephyrproject/zephyr/drivers/timer/cortex_m_systick.c -o CMakeFiles/drivers__timer.dir/cortex_m_systick.c.s

# Object files for target drivers__timer
drivers__timer_OBJECTS = \
"CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj" \
"CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj"

# External object files for target drivers__timer
drivers__timer_EXTERNAL_OBJECTS =

zephyr/drivers/timer/libdrivers__timer.a: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/sys_clock_init.c.obj
zephyr/drivers/timer/libdrivers__timer.a: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/cortex_m_systick.c.obj
zephyr/drivers/timer/libdrivers__timer.a: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/build.make
zephyr/drivers/timer/libdrivers__timer.a: zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hyc/zephyrproject/hyc/02_2_key_exit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libdrivers__timer.a"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && $(CMAKE_COMMAND) -P CMakeFiles/drivers__timer.dir/cmake_clean_target.cmake
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drivers__timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/build: zephyr/drivers/timer/libdrivers__timer.a
.PHONY : zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/build

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/clean:
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer && $(CMAKE_COMMAND) -P CMakeFiles/drivers__timer.dir/cmake_clean.cmake
.PHONY : zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/clean

zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/depend:
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyc/zephyrproject/hyc/02_2_key_exit /home/hyc/zephyrproject/zephyr/drivers/timer /home/hyc/zephyrproject/hyc/02_2_key_exit/build /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : zephyr/drivers/timer/CMakeFiles/drivers__timer.dir/depend

