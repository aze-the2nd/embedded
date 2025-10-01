cmake_minimum_required(VERSION 3.21)


set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/sdk/pico-sdk" CACHE PATH "Path to pico-sdk" FORCE)
include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")


set(PICO_BOARD pico_w CACHE STRING "Board" FORCE)

project(embedded C CXX ASM)

pico_sdk_init()


set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(apps/hello-blinky)
add_subdirectory(apps/ultrasonic)