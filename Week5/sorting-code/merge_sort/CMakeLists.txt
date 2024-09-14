add_executable(merge_sort main.c merge_sort.c merge_sort.h test_merge_sort.c test_merge_sort.h)
target_compile_options(merge_sort PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(merge_sort PRIVATE ../include)

if (USE_ASAN)
    target_compile_options(merge_sort PRIVATE -fsanitize=address)
    target_link_options(merge_sort PRIVATE -fsanitize=address)
endif()
