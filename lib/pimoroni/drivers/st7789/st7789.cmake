set(DRIVER_NAME st7789)

#added to pull in sdk includes
# message("PIO.h: " ${PICO_SDK_PATH}/src/rp2_common/hardware_pio/include/hardware)
# include_directories(${PICO_SDK_PATH}/src/rp2_common/hardware_pio/include/)

add_library(${DRIVER_NAME} INTERFACE)

target_sources(${DRIVER_NAME} INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/${DRIVER_NAME}.cpp)

pico_generate_pio_header(${DRIVER_NAME} ${CMAKE_CURRENT_LIST_DIR}/st7789_parallel.pio)

target_include_directories(${DRIVER_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(st7789 INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Pull in pico libraries that we need
target_link_libraries(${DRIVER_NAME} INTERFACE pico_stdlib pimoroni_bus hardware_spi hardware_pwm hardware_pio hardware_dma pico_graphics)
