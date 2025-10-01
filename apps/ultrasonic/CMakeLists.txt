
add_executable(ultrasonic
  source/main_pico.cpp
)

target_compile_options(ultrasonic PRIVATE -mcpu=cortex-m0plus -mthumb)
target_link_options(ultrasonic    PRIVATE -mcpu=cortex-m0plus -mthumb)

# include e.g. lwipopts.h
target_include_directories(ultrasonic PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# WLAN/CYW43 + lwIP 
target_link_libraries(ultrasonic
  pico_stdlib
  pico_cyw43_arch_lwip_threadsafe_background
)

# I/O
pico_enable_stdio_usb(ultrasonic 1)
pico_enable_stdio_uart(ultrasonic 0)

# uf2/elf/bin
pico_add_extra_outputs(ultrasonic)