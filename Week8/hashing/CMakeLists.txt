cmake_minimum_required(VERSION 3.21)
project(hashing C)

set(CMAKE_C_STANDARD 11)

add_executable(hashing main.c list.c hashmap.h hashmap.c test_hashmap.c statistics.c statistics.h hashmapfunctions.c hashmapfunctions.h
        pair.c
        pair.h)
add_executable(test_hashmap test_hashmap.c hashmap.c list.c test_main.c hashmapfunctions.c hashmapfunctions.h pair.c pair.h)

#target_compile_options(hashing PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(hashing PRIVATE -Wall -Wextra -pedantic)
target_compile_options(test_hashmap PRIVATE -Wall -Wextra -pedantic -Werror)

configure_file(alice0.txt alice0.txt COPYONLY)
configure_file(short.txt short.txt COPYONLY)

if (USE_ASAN)
    target_compile_options(hashing PRIVATE -fsanitize=address)
    target_link_options(hashing PRIVATE -fsanitize=address)

    target_compile_options(test_hashmap PRIVATE -fsanitize=address)
    target_link_options(test_hashmap PRIVATE -fsanitize=address)
endif ()
