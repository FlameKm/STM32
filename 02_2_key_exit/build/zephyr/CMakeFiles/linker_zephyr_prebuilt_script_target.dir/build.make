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

# Utility rule file for linker_zephyr_prebuilt_script_target.

# Include any custom commands dependencies for this target.
include zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/compiler_depend.make

# Include the progress variables for this target.
include zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/progress.make

zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target: zephyr/linker_zephyr_pre0.cmd

zephyr/linker_zephyr_pre0.cmd: /home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/stm32f1/linker.ld
zephyr/linker_zephyr_pre0.cmd: zephyr/include/generated/autoconf.h
zephyr/linker_zephyr_pre0.cmd: zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hyc/zephyrproject/hyc/02_2_key_exit/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating linker_zephyr_pre0.cmd"
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr && /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc -x assembler-with-cpp -undef -MD -MF linker_zephyr_pre0.cmd.dep -MT linker_zephyr_pre0.cmd -D_LINKER -D_ASMLANGUAGE -imacros /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/include/generated/autoconf.h -I/home/hyc/zephyrproject/zephyr/include -I/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/include/generated -I/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/stm32f1 -I/home/hyc/zephyrproject/zephyr/lib/libc/minimal/include -I/home/hyc/zephyrproject/zephyr/drivers -I/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/common -I/home/hyc/zephyrproject/modules/lib/acpica/../../zephyr/include/ -I/home/hyc/zephyrproject/modules/lib/acpica//..// -I/home/hyc/zephyrproject/modules/lib/acpica//source/include// -I/home/hyc/zephyrproject/modules/lib/acpica//source/include//platform/ -I/home/hyc/zephyrproject/modules/lib/acpica//source/compiler/ -I/home/hyc/zephyrproject/modules/lib/acpica/generate/zephyr/ -I/home/hyc/zephyrproject/modules/lib/acpica//source/tools/acpiexec/ -I/home/hyc/zephyrproject/modules/lib/acpica//source/tools/acpidump/ -I/home/hyc/zephyrproject/modules/hal/cmsis/CMSIS/Core/Include -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/soc -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include/Legacy -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/common_ll/include -D__GCC_LINKER_CMD__ -DLINKER_ZEPHYR_PREBUILT -E /home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/stm32f1/linker.ld -P -o linker_zephyr_pre0.cmd

linker_zephyr_prebuilt_script_target: zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target
linker_zephyr_prebuilt_script_target: zephyr/linker_zephyr_pre0.cmd
linker_zephyr_prebuilt_script_target: zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/build.make
.PHONY : linker_zephyr_prebuilt_script_target

# Rule to build all files generated by this target.
zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/build: linker_zephyr_prebuilt_script_target
.PHONY : zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/build

zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/clean:
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr && $(CMAKE_COMMAND) -P CMakeFiles/linker_zephyr_prebuilt_script_target.dir/cmake_clean.cmake
.PHONY : zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/clean

zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/depend:
	cd /home/hyc/zephyrproject/hyc/02_2_key_exit/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyc/zephyrproject/hyc/02_2_key_exit /home/hyc/zephyrproject/zephyr /home/hyc/zephyrproject/hyc/02_2_key_exit/build /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : zephyr/CMakeFiles/linker_zephyr_prebuilt_script_target.dir/depend

