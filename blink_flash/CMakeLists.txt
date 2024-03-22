add_executable(blink_flash
  blink_flash.cpp
)

# pull in common dependencies
target_link_libraries(blink_flash
  pico_stdlib
  pico_cyw43_arch_none
  FlashPROM
)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_flash)

pico_enable_stdio_usb(blink_flash 1)
pico_enable_stdio_uart(blink_flash 0)