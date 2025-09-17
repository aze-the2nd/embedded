cmake_minimum_required(VERSION 3.21)

# 1) Import the sdk before the project()
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# 2) Try-Compile NICHT linken lassen (früh setzen!)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(ultrasonic C CXX ASM)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pico W aktivieren (vor pico_sdk_init)
set(PICO_BOARD pico_w CACHE STRING "Board" FORCE)

pico_sdk_init()

add_executable(ultrasonic
  source/main.cpp
)

target_include_directories(ultrasonic PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ultrasonic
  pico_cyw43_arch_lwip_threadsafe_background
  pico_stdlib
)

pico_enable_stdio_usb(ultrasonic 1)
pico_enable_stdio_uart(ultrasonic 0)

pico_add_extra_outputs(ultrasonic)
