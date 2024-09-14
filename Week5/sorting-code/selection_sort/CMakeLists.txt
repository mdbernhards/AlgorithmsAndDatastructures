add_executable(selection_sort main.c selection_sort.c selection_sort.h test_selection_sort.c test_selection_sort.h)
target_compile_options(selection_sort PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(selection_sort PRIVATE ../include)

if (USE_ASAN)
    target_compile_options(selection_sort PRIVATE -fsanitize=address)
    target_link_options(selection_sort PRIVATE -fsanitize=address)
endif()
