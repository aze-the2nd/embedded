
add_executable(auv
  source/main_pico.cpp
)

target_compile_options(auv PRIVATE -mcpu=cortex-m0plus -mthumb)
target_link_options(auv    PRIVATE -mcpu=cortex-m0plus -mthumb)

# include e.g. lwipopts.h
target_include_directories(auv PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# WLAN/CYW43 + lwIP 
target_link_libraries(auv
  pico_stdlib
  pico_cyw43_arch_lwip_threadsafe_background
)

# I/O
pico_enable_stdio_usb(auv 1)
pico_enable_stdio_uart(auv 0)

# uf2/elf/bin
pico_add_extra_outputs(auv)