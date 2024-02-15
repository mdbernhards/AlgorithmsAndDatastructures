cmake_minimum_required(VERSION 3.20)
project(activity10 C)

set(CMAKE_C_STANDARD 11)

add_executable(activity10 main.c)

configure_file(E.coli.txt E.coli.txt COPYONLY)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
