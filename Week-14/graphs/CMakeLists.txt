cmake_minimum_required(VERSION 3.15)
project(graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(graphs main.cpp graph.cpp graph.h colours.h visitor.cpp visitor.h topological_sort.cpp topological_sort.h dot_writer.cpp dot_writer.h colours.cpp traversal_tester.cpp traversal_tester.h)

file(GLOB MY_PUBLIC_HEADERS "graphs/*")
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${CMAKE_BINARY_DIR})
configure_file(tasks.txt tasks.txt COPYONLY)

target_compile_options(graphs PRIVATE -Wall -Wextra -pedantic -Werror)
