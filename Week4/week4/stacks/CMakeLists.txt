add_executable(stacks stacks.c)

target_compile_options(stacks PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(stacks PRIVATE ../include)

if (USE_ASAN)
    target_compile_options(stacks PRIVATE -fsanitize=address)
    target_link_options(stacks PRIVATE -fsanitize=address)
endif()
