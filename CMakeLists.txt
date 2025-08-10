# CMakeLists.txt (root)
cmake_minimum_required(VERSION 3.10)
project(Chess C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.c")

# split main.c out of the lib
set(MAIN_SRC "")
foreach(f ${SRC_FILES})
    if(f MATCHES "/main\\.c$")
        set(MAIN_SRC ${f})
    endif()
endforeach()
set(LIB_SRC ${SRC_FILES})
list(REMOVE_ITEM LIB_SRC ${MAIN_SRC})

add_library(chess_lib ${LIB_SRC})
target_include_directories(chess_lib PUBLIC ${CMAKE_SOURCE_DIR}/src)

if(MAIN_SRC)
  add_executable(chess ${MAIN_SRC})
  target_link_libraries(chess PRIVATE chess_lib)
endif()

include(CTest)
enable_testing()

file(GLOB TEST_SRC CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/*.c")
add_executable(chess_tests ${TEST_SRC})
target_include_directories(chess_tests PRIVATE ${CMAKE_SOURCE_DIR}/tests)
target_link_libraries(chess_tests PRIVATE chess_lib)
add_test(NAME chess_tests COMMAND chess_tests)
