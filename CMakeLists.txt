cmake_minimum_required(VERSION 3.10)
project(Chess C)  # Tell CMake this is a C project

# Use C89 standard (a.k.a. ANSI C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # Disable compiler-specific extensions

# Add the executable
add_executable(chess
    src/main.c
    src/move.c
)
