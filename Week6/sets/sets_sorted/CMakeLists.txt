add_executable(sets_sorted set.c ../shared/set.c sets_sorted.c test_set.c test_set.h)

target_compile_options(sets_sorted PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(sets_sorted PRIVATE .)

if (USE_ASAN)
    target_compile_options(sets_sorted PRIVATE -fsanitize=address)
    target_link_options(sets_sorted PRIVATE -fsanitize=address)
endif()
