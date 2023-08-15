# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# compile ASM with /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc
# compile C with /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc
ASM_DEFINES = -DHSE_VALUE=8000000 -DKERNEL -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -D__PROGRAM_START -D__ZEPHYR_SUPERVISOR__ -D__ZEPHYR__=1

ASM_INCLUDES = -I/home/hyc/zephyrproject/zephyr/kernel/include -I/home/hyc/zephyrproject/zephyr/arch/arm/include -I/home/hyc/zephyrproject/zephyr/include -I/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/include/generated -I/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/stm32f1 -I/home/hyc/zephyrproject/zephyr/drivers -I/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/common -I/home/hyc/zephyrproject/modules/lib/acpica/../../zephyr/include -I/home/hyc/zephyrproject/modules/lib/acpica/.. -I/home/hyc/zephyrproject/modules/lib/acpica/source/include -I/home/hyc/zephyrproject/modules/lib/acpica/source/include/platform -I/home/hyc/zephyrproject/modules/lib/acpica/source/compiler -I/home/hyc/zephyrproject/modules/lib/acpica/generate/zephyr -I/home/hyc/zephyrproject/modules/lib/acpica/source/tools/acpiexec -I/home/hyc/zephyrproject/modules/lib/acpica/source/tools/acpidump -I/home/hyc/zephyrproject/modules/hal/cmsis/CMSIS/Core/Include -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/soc -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include/Legacy -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/common_ll/include -isystem /home/hyc/zephyrproject/zephyr/lib/libc/minimal/include -isystem /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/../lib/gcc/arm-zephyr-eabi/12.2.0/include -isystem /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/../lib/gcc/arm-zephyr-eabi/12.2.0/include-fixed

ASM_FLAGS = -Os -imacros /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/include/generated/autoconf.h -ffreestanding -fno-common -g -gdwarf-4 -fdiagnostics-color=always -mcpu=cortex-m3 -mthumb -mabi=aapcs -mfp16-format=ieee --sysroot=/home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/arm-zephyr-eabi -xassembler-with-cpp -imacros /home/hyc/zephyrproject/zephyr/include/zephyr/toolchain/zephyr_stdint.h -D_ASMLANGUAGE -Wno-unused-but-set-variable -fno-asynchronous-unwind-tables -fno-reorder-functions --param=min-pagesize=0 -fno-defer-pop -fmacro-prefix-map=/home/hyc/zephyrproject/hyc/02_2_key_exit=CMAKE_SOURCE_DIR -fmacro-prefix-map=/home/hyc/zephyrproject/zephyr=ZEPHYR_BASE -fmacro-prefix-map=/home/hyc/zephyrproject=WEST_TOPDIR -ffunction-sections -fdata-sections -nostdinc

C_DEFINES = -DHSE_VALUE=8000000 -DKERNEL -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -D__PROGRAM_START -D__ZEPHYR_SUPERVISOR__ -D__ZEPHYR__=1

C_INCLUDES = -I/home/hyc/zephyrproject/zephyr/kernel/include -I/home/hyc/zephyrproject/zephyr/arch/arm/include -I/home/hyc/zephyrproject/zephyr/include -I/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/include/generated -I/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/stm32f1 -I/home/hyc/zephyrproject/zephyr/drivers -I/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/common -I/home/hyc/zephyrproject/modules/lib/acpica/../../zephyr/include -I/home/hyc/zephyrproject/modules/lib/acpica/.. -I/home/hyc/zephyrproject/modules/lib/acpica/source/include -I/home/hyc/zephyrproject/modules/lib/acpica/source/include/platform -I/home/hyc/zephyrproject/modules/lib/acpica/source/compiler -I/home/hyc/zephyrproject/modules/lib/acpica/generate/zephyr -I/home/hyc/zephyrproject/modules/lib/acpica/source/tools/acpiexec -I/home/hyc/zephyrproject/modules/lib/acpica/source/tools/acpidump -I/home/hyc/zephyrproject/modules/hal/cmsis/CMSIS/Core/Include -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/soc -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include/Legacy -I/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/common_ll/include -isystem /home/hyc/zephyrproject/zephyr/lib/libc/minimal/include -isystem /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/../lib/gcc/arm-zephyr-eabi/12.2.0/include -isystem /home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/../lib/gcc/arm-zephyr-eabi/12.2.0/include-fixed

C_FLAGS = -fno-strict-aliasing -Os -imacros /home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/include/generated/autoconf.h -ffreestanding -fno-common -g -gdwarf-4 -fdiagnostics-color=always -mcpu=cortex-m3 -mthumb -mabi=aapcs -mfp16-format=ieee --sysroot=/home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/arm-zephyr-eabi -imacros /home/hyc/zephyrproject/zephyr/include/zephyr/toolchain/zephyr_stdint.h -Wall -Wformat -Wformat-security -Wno-format-zero-length -Wno-pointer-sign -Wpointer-arith -Wexpansion-to-defined -Wno-unused-but-set-variable -Werror=implicit-int -fno-pic -fno-pie -fno-asynchronous-unwind-tables -fno-reorder-functions --param=min-pagesize=0 -fno-defer-pop -fmacro-prefix-map=/home/hyc/zephyrproject/hyc/02_2_key_exit=CMAKE_SOURCE_DIR -fmacro-prefix-map=/home/hyc/zephyrproject/zephyr=ZEPHYR_BASE -fmacro-prefix-map=/home/hyc/zephyrproject=WEST_TOPDIR -ffunction-sections -fdata-sections -std=c99 -nostdinc

