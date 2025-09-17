cmake_minimum_required(VERSION 3.21)


# --- Pico SDK direkt importieren (ohne board.cmake) ---
# Erwartet: PICO_SDK_PATH ist gesetzt (z.B. /home/<user>/Dev/sdk/pico-sdk)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)


# Dieses App-Projekt baut NUR den Pico/Pico W Target
project(hello-blinky C CXX ASM)

# Standards (optional, aber gut)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# --- WICHTIG: Pico W aktivieren (vor pico_sdk_init!) ---
set(PICO_BOARD pico_w CACHE STRING "Board" FORCE)



# SDK initialisieren
pico_sdk_init()

# Sanity-Check: lwipopts.h vorhanden?
if (NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/include/lwipopts.h)
  message(FATAL_ERROR "lwipopts.h fehlt unter ${CMAKE_CURRENT_LIST_DIR}/include")
endif()

# Target
add_executable(hello-blinky
  src/main_pico.cpp
)

target_include_directories(hello-blinky PRIVATE  
  ${CMAKE_CURRENT_LIST_DIR}/include
  )

# --- CYW43/Wi-Fi einbinden (Header + Libs) ---
# Wähle genau EINE der Arch-Varianten; meist bequem:
  target_link_libraries(hello-blinky

  pico_cyw43_arch_lwip_threadsafe_background
  pico_stdlib
#  pico_lwip
#  pico_cyw43_arch_none
)

# I/O
pico_enable_stdio_usb(hello-blinky 1)
pico_enable_stdio_uart(hello-blinky 0)

# UF2/ELF/BIN erzeugen
pico_add_extra_outputs(hello-blinky)

