cmake_minimum_required(VERSION 3.22)
project(aoc23)

set(CMAKE_CXX_STANDARD 20)

add_executable(aoc23 main.cpp)

target_include_directories(aoc23
    PRIVATE
    include
)

target_sources(aoc23
    PRIVATE
    src/file.cpp
    src/str.cpp
    src/maths.cpp
    src/day1.cpp
    src/day2.cpp
    src/day3.cpp
    src/day4.cpp
    src/day5.cpp
    src/day6.cpp
    src/day7.cpp
)