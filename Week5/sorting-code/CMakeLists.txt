cmake_minimum_required(VERSION 3.20)
project(sorting C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(merge_sort)
add_subdirectory(selection_sort)
add_subdirectory(sortinglib)

target_link_libraries(merge_sort sortinglib)
target_link_libraries(selection_sort sortinglib)
