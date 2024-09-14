set(CMAKE_C_STANDARD 11)

add_executable(doubly_linked_list main.c list.c list.h test_list.c test_list.h)

target_compile_options(doubly_linked_list PRIVATE -Wall -Wextra -pedantic -Werror)

if (USE_ASAN)
    target_compile_options(doubly_linked_list PRIVATE -fsanitize=address)
    target_link_options(doubly_linked_list PRIVATE -fsanitize=address)
endif()
