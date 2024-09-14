cmake_minimum_required(VERSION 3.15)
project(heap_full)

set(CMAKE_CXX_STANDARD 20)

add_executable(heap_full main.cpp maxheap.cpp maxheap.h heap_tester.cpp heap_tester.h task.cpp task.h)
target_compile_options(heap_full PRIVATE -Wall -Wextra -pedantic -Werror)

target_compile_options(heap_full PRIVATE -fsanitize=address)
target_link_options(heap_full PRIVATE -fsanitize=address)
