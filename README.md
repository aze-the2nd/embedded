# Build-Commands

cmake -S /home/alex/Dev/embedded
-B /home/alex/Dev/embedded/build/pico -G Ninja
-DPICO_BOARD=pico_w
-DCMAKE_BUILD_TYPE=Debug
-DPICO_SDK_PATH=/home/alex/Dev/embedded/sdk/pico-sdk
-DCMAKE_SYSTEM_NAME=Generic
-DCMAKE_SYSTEM_PROCESSOR=arm
-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY
-DCMAKE_C_COMPILER=/usr/bin/arm-none-eabi-gcc
-DCMAKE_CXX_COMPILER=/usr/bin/arm-none-eabi-g++
-DCMAKE_ASM_COMPILER=/usr/bin/arm-none-eab

cmake --build build/pico -j



# Connection to SerialPort for Debugging-Information

groups | grep dialout || sudo usermod -a -G dialout $USER
- check permissions

sudo screen /dev/ttyACM0 115200
- actual connection with printout
- exit: Ctrl-A, then K, then 'y'

picocom -b 115200 --imap lfcrlf /dev/ttyACM0
- for CRLF-endings

