add_library(week4lib STATIC week4lib.c ../include/week4lib/utils.h ../include/week4lib/array_of_int.h ../include/week4lib/list_of_char.h)

target_compile_options(week4lib PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(week4lib PRIVATE ../include)
