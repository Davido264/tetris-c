cmake_minimum_required(VERSION 3.10)

project(Tetris-C)

find_package(Curses REQUIRED)

add_executable(tetris-c
    src/data_structures.c
    src/render.c
    src/tetromino.c
    src/main.c)

target_include_directories(tetris-c PRIVATE 
    include
    ${CURSES_INCLUDE_DIR})

target_link_libraries(tetris-c ${CURSES_LIBRARIES})
