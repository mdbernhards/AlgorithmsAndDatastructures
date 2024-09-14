add_library(sortinglib list.c array.c)
target_compile_options(sortinglib PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(sortinglib PRIVATE ../include/sortinglib)