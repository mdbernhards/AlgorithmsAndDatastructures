set(CMAKE_C_STANDARD 11)

add_executable(singly_linked_lists main.c list.c list.h test_list.c test_list.h)

target_compile_options(singly_linked_lists PRIVATE -Wall -Wextra -pedantic -Werror)

if (USE_ASAN)
    target_compile_options(singly_linked_lists PRIVATE -fsanitize=address)
    target_link_options(singly_linked_lists PRIVATE -fsanitize=address)
endif()
