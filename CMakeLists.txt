cmake_minimum_required(VERSION 3.21)

# Board-Option zentral
set(BOARD "pico_w" CACHE STRING "Target board: pico | stm32")

# WICHTIG: Wenn Pico, dann SDK VOR project() importieren,
# damit CMAKE_*_COMPILER auf arm-none-eabi-* gesetzt wird.
if(BOARD STREQUAL "pico")
  include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
endif()

project(embedded-superrepo C CXX ASM)

# Falls Pico: SDK initialisieren (einmal pro Buildbaum)
if(BOARD STREQUAL "pico")
  pico_sdk_init()
endif()

add_subdirectory(apps/hello-blinky)
add_subdirectory(apps/ultrasonic)
#cmake_minimum_required(VERSION 3.21)
#project(embedded-superrepo)
#add_subdirectory(apps/hello-blinky)
