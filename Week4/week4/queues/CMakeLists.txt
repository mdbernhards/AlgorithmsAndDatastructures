add_executable(queues queues.c deque.c)

configure_file(input.txt input.txt COPYONLY)

target_compile_options(queues PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(queues PRIVATE ../include)

if (USE_ASAN)
    target_compile_options(queues PRIVATE -fsanitize=address)
    target_link_options(queues PRIVATE -fsanitize=address)
endif()
