
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/cpu_idle.S" "/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/cpu_idle.S.obj"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/isr_wrapper.S" "/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/isr_wrapper.S.obj"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/nmi_on_reset.S" "/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/nmi_on_reset.S.obj"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/swap_helper.S" "/home/hyc/zephyrproject/hyc/02_2_key_exit/build/zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/swap_helper.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "HSE_VALUE=8000000"
  "KERNEL"
  "STM32F103xB"
  "USE_FULL_LL_DRIVER"
  "USE_HAL_DRIVER"
  "__PROGRAM_START"
  "__ZEPHYR_SUPERVISOR__"
  "__ZEPHYR__=1"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "/home/hyc/zephyrproject/zephyr/kernel/include"
  "/home/hyc/zephyrproject/zephyr/arch/arm/include"
  "/home/hyc/zephyrproject/zephyr/include"
  "zephyr/include/generated"
  "/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/stm32f1"
  "/home/hyc/zephyrproject/zephyr/drivers"
  "/home/hyc/zephyrproject/zephyr/soc/arm/st_stm32/common"
  "/home/hyc/zephyrproject/modules/lib/acpica/../../zephyr/include"
  "/home/hyc/zephyrproject/modules/lib/acpica/.."
  "/home/hyc/zephyrproject/modules/lib/acpica/source/include"
  "/home/hyc/zephyrproject/modules/lib/acpica/source/include/platform"
  "/home/hyc/zephyrproject/modules/lib/acpica/source/compiler"
  "/home/hyc/zephyrproject/modules/lib/acpica/generate/zephyr"
  "/home/hyc/zephyrproject/modules/lib/acpica/source/tools/acpiexec"
  "/home/hyc/zephyrproject/modules/lib/acpica/source/tools/acpidump"
  "/home/hyc/zephyrproject/modules/hal/cmsis/CMSIS/Core/Include"
  "/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/soc"
  "/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include"
  "/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/stm32f1xx/drivers/include/Legacy"
  "/home/hyc/zephyrproject/modules/hal/stm32/stm32cube/common_ll/include"
  "/home/hyc/zephyrproject/zephyr/lib/libc/minimal/include"
  "/home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/../lib/gcc/arm-zephyr-eabi/12.2.0/include"
  "/home/hyc/zephyr-sdk-0.16.1/arm-zephyr-eabi/bin/../lib/gcc/arm-zephyr-eabi/12.2.0/include-fixed"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/fatal.c" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/fatal.c.obj" "gcc" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/fatal.c.obj.d"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/irq_manage.c" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/irq_manage.c.obj" "gcc" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/irq_manage.c.obj.d"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/nmi.c" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/nmi.c.obj" "gcc" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/nmi.c.obj.d"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/prep_c.c" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/prep_c.c.obj" "gcc" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/prep_c.c.obj.d"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/swap.c" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/swap.c.obj" "gcc" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/swap.c.obj.d"
  "/home/hyc/zephyrproject/zephyr/arch/arm/core/aarch32/thread.c" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/thread.c.obj" "gcc" "zephyr/arch/arch/arm/core/aarch32/CMakeFiles/arch__arm__core__aarch32.dir/thread.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
