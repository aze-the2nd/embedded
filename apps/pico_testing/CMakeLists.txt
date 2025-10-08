
add_executable(pico_testing
  source/main_pico.cpp
)

target_compile_options(pico_testing PRIVATE -mcpu=cortex-m0plus -mthumb)
target_link_options(pico_testing    PRIVATE -mcpu=cortex-m0plus -mthumb)

# include e.g. lwipopts.h
target_include_directories(pico_testing PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# WLAN/CYW43 + lwIP 
target_link_libraries(pico_testing
  pico_stdlib
  pico_cyw43_arch_lwip_threadsafe_background
  pico_multicore
)

# I/O
pico_enable_stdio_usb(pico_testing 1)
pico_enable_stdio_uart(pico_testing 0)

# uf2/elf/bin
pico_add_extra_outputs(pico_testing)