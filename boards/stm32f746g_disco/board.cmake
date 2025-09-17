# STM32F746NGH6 (F7, FPU, single-precision)
set(MCU_FAMILY STM32F7)
set(MCU_FLAGS
    -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard
    -ffunction-sections -fdata-sections
    -fno-exceptions -fno-rtti
)

set(LD_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/linker/STM32F746NGH_FLASH.ld) # TODO: einfügen
set(LD_FLAGS "-Wl,--gc-sections -Wl,-Map=${CMAKE_BINARY_DIR}/app.map")

function(stm32_target name)
  target_compile_options(${name} PRIVATE ${MCU_FLAGS})
  target_link_options(${name} PRIVATE ${MCU_FLAGS} ${LD_FLAGS} -T ${LD_SCRIPT})
  target_link_libraries(${name} m c gcc)
endfunction()

