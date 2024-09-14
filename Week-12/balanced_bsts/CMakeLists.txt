cmake_minimum_required(VERSION 3.15)
project(BSTs)

set(CMAKE_CXX_STANDARD 20)

add_executable(BSTs main.cpp bintree_node.cpp bintree_node.h bintree.cpp bintree.h bintree_tester.cpp bintree_tester.h bintree_writer.cpp bintree_writer.h bintree_node_tester.cpp bintree_node_tester.h)
target_compile_options(BSTs PRIVATE -Wall -Wextra -pedantic -Werror)

configure_file(numbers1.txt numbers1.txt COPYONLY)
configure_file(numbers2.txt numbers2.txt COPYONLY)
configure_file(numbers3.txt numbers3.txt COPYONLY)

target_compile_options(BSTs PRIVATE -fsanitize=address)
target_link_options(BSTs PRIVATE -fsanitize=address)
# target_compile_definitions(BSTs PRIVATE BALANCED)
