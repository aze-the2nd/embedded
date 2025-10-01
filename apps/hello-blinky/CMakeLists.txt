
add_executable(hello-blinky
  source/main_pico.cpp
)

target_compile_options(hello-blinky PRIVATE -mcpu=cortex-m0plus -mthumb)
target_link_options(hello-blinky    PRIVATE -mcpu=cortex-m0plus -mthumb)

# include e.g. lwipopts.h
target_include_directories(hello-blinky PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# WLAN/CYW43 + lwIP 
target_link_libraries(hello-blinky
  pico_stdlib
  pico_cyw43_arch_lwip_threadsafe_background
)

# I/O
pico_enable_stdio_usb(hello-blinky 1)
pico_enable_stdio_uart(hello-blinky 0)

# uf2/elf/bin
pico_add_extra_outputs(hello-blinky)



