cmake_minimum_required(VERSION 3.12)

set(PICO_INSTALL_PATH "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1")
set(CMAKE_MAKE_PROGRAM "C:\\Program Files\\Raspberry Pi\\Pico SDK v1.5.1\\ninja\\ninja.exe")
# set(PICO_TOOLCHAIN_PATH "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1")
# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

include(pico_extras_import_optional.cmake)

include(pimoroni_pico_import.cmake)

project(rtos-screen C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

#set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

include(example_auto_set_url.cmake)

#include Libraries
SET(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/port/FreeRTOS-Kernel" CACHE STRING "Local Config")
include_directories("${FREERTOS_CONFIG_FILE_DIRECTORY}") 
include(FreeRTOS_Kernel_import.cmake)
add_compile_definitions(
    FREE_RTOS_KERNEL_SMP=0
    portSUPPORT_SMP=0
)

#pimoroni directories for drivers, libaries...
add_subdirectory(lib)

#Add main source directory
add_subdirectory(src)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()


