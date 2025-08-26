cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME stm32f103zet6_cube_test)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add middlewares sources
file(GLOB_RECURSE MIDDLEWARES_SOURCES
    # Add FatFS sources
    # ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/FatFS/*.c

    # Add RT-Thread sources
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/RT-Thread/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/RT-Thread/*.s
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ${MIDDLEWARES_SOURCES}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add FatFS include paths
    # ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/FatFS/inc/
    # ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/FatFS/port/

    # Add RT-Thread include paths
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/RT-Thread/components/finsh/
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/RT-Thread/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/RT-Thread/port/
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
