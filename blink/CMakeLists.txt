add_executable(blink
  blink.cpp
)

# pull in common dependencies
target_link_libraries(blink
  pico_stdlib
  pico_cyw43_arch_none
)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)
