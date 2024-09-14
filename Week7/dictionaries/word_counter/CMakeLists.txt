add_executable(word_counter counter.c word_counter.c binsearch.c binsearch.h pair.c pair.h)
add_executable(test_counter test_main.c counter.c binsearch.c test_counter.c test_counter.h
        pair.c pair.h)
add_executable(generic_functions generic_functions.c binsearch.c binsearch.h)

target_compile_options(word_counter PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(test_counter PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(generic_functions PRIVATE -Wall -Wextra -pedantic -Werror)

if (USE_ASAN)
    target_compile_options(word_counter PRIVATE -fsanitize=address)
    target_link_options(word_counter PRIVATE -fsanitize=address)

    target_compile_options(test_counter PRIVATE -fsanitize=address)
    target_link_options(test_counter PRIVATE -fsanitize=address)
endif()



