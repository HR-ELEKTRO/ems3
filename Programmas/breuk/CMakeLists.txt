cmake_minimum_required(VERSION 3.26)
project(breuk)
add_executable(main main.c breuk.c)
target_compile_options(main PRIVATE -std=c18 -Wall -Wextra -Wpedantic -g3 -O0)
