add_executable(sets_unsorted ../shared/set.c set.c test_set.c test_set.h sets_unsorted.c)

target_compile_options(sets_unsorted PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(sets_unsorted PRIVATE .)

if (USE_ASAN)
    target_compile_options(sets_unsorted PRIVATE -fsanitize=address)
    target_link_options(sets_unsorted PRIVATE -fsanitize=address)
endif()
