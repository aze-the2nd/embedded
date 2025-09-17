# Pico via pico-sdk (nutzt eigene Toolchain-Logik)
# Erwartet PICO_SDK_PATH in der Umgebung
#include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
#
#function(pico_target name)
#  pico_sdk_init()
#  # nichts weiter hier; Flags/Link macht SDK
#endfunction()

