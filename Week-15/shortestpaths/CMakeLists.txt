cmake_minimum_required(VERSION 3.15)
project(shortestpaths)

set(CMAKE_CXX_STANDARD 20)

add_executable(shortestpaths main.cpp graph.cpp graph.h colours.h shortest_paths.cpp shortest_paths.h shortest_paths_tester.cpp shortest_paths_tester.h vertex_heap.cpp vertex_heap.h topological_sort.cpp topological_sort.h sp_dfs.cpp sp_dfs.h dijkstra_simple.cpp dijkstra_simple.h dijkstra_heap.cpp dijkstra_heap.h dot_writer.cpp dot_writer.h relaxer.cpp relaxer.h colours.cpp)

target_compile_options(shortestpaths PRIVATE -Wall -Wextra -pedantic)

file(GLOB MY_PUBLIC_HEADERS "graphs/*")
file(COPY ${MY_PUBLIC_HEADERS} DESTINATION ${CMAKE_BINARY_DIR})
