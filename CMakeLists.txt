cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(picow_blink C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_BOARD pico_w)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(lib)

# Add blink folder
add_subdirectory(blink)
add_subdirectory(blink_usb)
add_subdirectory(blink_flash)
