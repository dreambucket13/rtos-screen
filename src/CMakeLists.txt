set(NAME "rtos-screen")

add_executable(${NAME}
        main.cpp
        Agent.cpp
        Screen.cpp
        ScreenWriter.cpp
        Heartbeat.cpp
        )


# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
	 pico_stdlib
     FreeRTOS-Kernel-Heap4
     hardware_spi
     hardware_pwm
     hardware_dma
     rgbled
     button
     pico_display_2
     st7789
     pico_graphics
	)


target_include_directories(${NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../lib/FreeRTOS-Kernel/include
     )
     
# target_compile_definitions(${NAME} PRIVATE
#     FREE_RTOS_KERNEL_SMP=1
#     portSUPPORT_SMP=1
# )

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable uart output, disable usb output
pico_enable_stdio_usb(${NAME} 0)
pico_enable_stdio_uart(${NAME} 1)