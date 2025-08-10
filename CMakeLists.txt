cmake_minimum_required(VERSION 3.10)
project(Chess C)  # Tell CMake this is a C project

# Write JSON for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use C89 standard (a.k.a. ANSI C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # Disable compiler-specific extensions

# Add the executable
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_executable(chess ${SRC_FILES})
