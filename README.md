# rp2040-freertos
Program Raspberry Pi Pico with FreeRTOS.

* [tutorial video](https://youtu.be/5pUY7xVE2gU)
* [sample github](https://github.com/lowlevellearning/rp2040-freertos)
* [FreeRTOS Kernel Developer Docs](https://www.freertos.org/features.html)
* [Pico SDK examples](https://raspberrypi.github.io/pico-sdk-doxygen/examples_page.html)
* [Pico SDK github](https://github.com/raspberrypi/pico-sdk)

# 1. Setup
```sh
$ cd ~/workspace_arm

$ git clone git@github.com:raspberrypi/pico-sdk.git --depth 1
$ cd pico-sdk
$ git submodule update --init
$ cd ..

$ mkdir rp2040-freertos
$ cd rp2040-freertos/
$ git init
$ git submodule add --depth 1 git@github.com:FreeRTOS/FreeRTOS-Kernel.git FreeRTOS-Kernel

# import pico sdk
$ cp ~/workspace_arm/pico-sdk/external/pico_sdk_import.cmake ./

# cmake presets
$ export PICO_SDK_PATH=~/workspace_pico/pico-sdk
$ export PICO_TOOLCHAIN_PATH=/c/Program\ Files\ \(x86\)/Arm\ GNU\ Toolchain\ arm-none-eabi/12.2\ mpacbti-bet1/bin
$ export PICO_PLATFORM=rp2040

# Build
$ mkdir build
$ cd build/
/build$ cmake ..
/build$ make
/build$ ll
total 968
drwxr-xr-x 7 ryan ryan   4096 Sep 23 18:57 ./
drwxr-xr-x 7 ryan ryan   4096 Sep 23 18:56 ../
-rw-r--r-- 1 ryan ryan  18611 Sep 23 18:56 CMakeCache.txt
drwxr-xr-x 6 ryan ryan   4096 Sep 23 18:57 CMakeFiles/
-rw-r--r-- 1 ryan ryan  92518 Sep 23 18:56 Makefile
-rwxr-xr-x 1 ryan ryan  21192 Sep 23 18:57 blink.bin*
-rw-r--r-- 1 ryan ryan 401644 Sep 23 18:57 blink.dis
-rwxr-xr-x 1 ryan ryan  61660 Sep 23 18:57 blink.elf*
-rw-r--r-- 1 ryan ryan 193809 Sep 23 18:57 blink.elf.map
-rw-r--r-- 1 ryan ryan  59673 Sep 23 18:57 blink.hex
-rw-r--r-- 1 ryan ryan  42496 Sep 23 18:57 blink.uf2
-rw-r--r-- 1 ryan ryan   1583 Sep 23 18:56 cmake_install.cmake
drwxr-xr-x 6 ryan ryan   4096 Sep 23 18:57 elf2uf2/
drwxr-xr-x 3 ryan ryan   4096 Sep 23 18:56 generated/
-rw-r--r-- 1 ryan ryan  43454 Sep 23 18:57 libFreeRTOS.a
drwxr-xr-x 6 ryan ryan   4096 Sep 23 18:56 pico-sdk/
drwxr-xr-x 3 ryan ryan   4096 Sep 23 18:57 pioasm/

/build$ cp blink.uf2 /media/user/RPI-RP2/
```

## `git` submodule commands
```sh
# add shallow submodule
git submodule add --depth 1 <repo-url> <path>
git config -f .gitmodules submodule.<path>.shallow true

# later unshallow
git config -f .gitmodules submodule.<path>.shallow false
git submodule update <path>
```