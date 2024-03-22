add_executable(blink_usb
  blink_usb.cpp
)

# pull in common dependencies
target_link_libraries(blink_usb
  pico_stdlib
  pico_cyw43_arch_none
)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_usb)

pico_enable_stdio_usb(blink_usb 1)
pico_enable_stdio_uart(blink_usb 0)