cmake_minimum_required(VERSION 3.27)
project(plagiaat_scanner)
add_executable(plagiaat_scanner identifier_extractor.cpp plagiaat_scanner.cpp)
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -std=c++23 -Wall -Wextra -Wpedantic -g3 -O0")
