cmake_minimum_required(VERSION 3.0)
project(aoc23)

set(CMAKE_CXX_STANDARD 20)

add_executable(aoc23 main.cpp
)

target_include_directories(aoc23
    PRIVATE
    include
)

target_sources(aoc23
    PRIVATE
    src/file.cpp
)