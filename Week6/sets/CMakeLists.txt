cmake_minimum_required(VERSION 3.21)
project(sets C)

set(CMAKE_C_STANDARD 17)

add_executable(intro intro.c)
target_compile_options(intro PRIVATE -Wall -Wextra -pedantic)

add_subdirectory(sets_unsorted)
add_subdirectory(sets_sorted)

