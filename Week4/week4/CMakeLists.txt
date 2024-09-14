cmake_minimum_required(VERSION 3.21)
project(week4 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(week4lib)
add_subdirectory(stacks)
add_subdirectory(queues)
add_subdirectory(circular-buffer)

target_link_libraries(stacks week4lib)
target_link_libraries(queues week4lib)
target_link_libraries(circular-buffer week4lib)
