add_executable(blink_serial
  blink_serial.c
)

# pull in common dependencies
target_link_libraries(blink_serial
  pico_stdlib
  pico_cyw43_arch_none
)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_serial)

# add url via pico_set_program_url
example_auto_set_url(blink_serial)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 1)