cmake_minimum_required(VERSION 3.22)
project(adventofcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(adventofcode main.cpp)

target_include_directories(adventofcode
    PRIVATE
        include/
    )

target_sources(adventofcode
    PRIVATE
        src/fs.cpp
        src/grid.cpp
        src/utils.cpp
        src/advent.cpp
    )
