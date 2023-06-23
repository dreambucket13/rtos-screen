cmake_minimum_required(VERSION 3.12)

# Change your executable name to something creative!
set(NAME rtos-screen) # <-- Name your project/executable here!

set(PICO_SDK_PATH "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/pico-sdk")
set(PICO_TOOLCHAIN_PATH "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/pico-sdk/cmake/preload/toolchains/pico_arm_gcc.cmake")

# ${CMAKE_BINARY_DIR}/${CMAKE_TOOLCHAIN_FILE}
message("CMAKE BINARY DIR IS ${CMAKE_BINARY_DIR}")
message("TOOLCHAIN FILE IS ${CMAKE_TOOLCHAIN_FILE}")


include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)



# Initialize the SDK
pico_sdk_init()



#include Libraries
SET(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/port/FreeRTOS-Kernel" CACHE STRING "Local Config")
include_directories("${FREERTOS_CONFIG_FILE_DIRECTORY}") 
include(FreeRTOS_Kernel_import.cmake)
# add_compile_definitions(
#     FREE_RTOS_KERNEL_SMP=1
#     portSUPPORT_SMP=1
# )





#pimoroni directories for drivers, libaries...
add_subdirectory(lib)

#Add main source directory
add_subdirectory(src)

#Set up files for the release packages
install(CODE "execute_process(COMMAND $ENV{HOME}/bin/picoDeploy.sh ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.elf)")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)


set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
