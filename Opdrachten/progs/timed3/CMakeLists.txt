cmake_minimum_required(VERSION 3.27)
project(timed)
add_executable(timed_contains stopwatch.cpp timed_contains.cpp)
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -std=c++23 -Wall -Wextra -Wpedantic -g3 -O0")
