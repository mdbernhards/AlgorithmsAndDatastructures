add_executable(circular-buffer circular-buffer.c buffer.c buffer.h test_buffer.c test_buffer.h ../queues/deque.c ../queues/deque.h)

configure_file(input.txt input.txt COPYONLY)

target_compile_options(circular-buffer PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(circular-buffer PRIVATE ../include)

if (USE_ASAN)
    target_compile_options(circular-buffer PRIVATE -fsanitize=address)
    target_link_options(circular-buffer PRIVATE -fsanitize=address)
endif()
