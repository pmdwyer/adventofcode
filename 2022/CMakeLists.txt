cmake_minimum_required(VERSION 3.22)
project(aoc22)

set(CMAKE_CXX_STANDARD 20)

add_executable(aoc22 main.cpp)

target_include_directories(aoc22
    PRIVATE
    include
    )

target_sources(aoc22
    PRIVATE
    src/fs.cpp
    src/grid.cpp
    src/knots.cpp
    src/utils.cpp
    src/advent.cpp
    src/crt.cpp
    src/boulders.cpp
    src/hill.cpp
    )
