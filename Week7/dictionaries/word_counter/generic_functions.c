#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binsearch.h"

void print_string_array(const char ** array, size_t count) {
    printf("[%s", array[0]);
    for (size_t i = 1; i < count; ++i) printf(", %s", array[i]);
    printf("]\n");
}

int compare_strings(const void* a, const void* b) 
{
    const char *char_ptr_a = *(char**)a;
    const char *char_ptr_b = *(char**)b;
    return strcmp(char_ptr_a,char_ptr_b);
}

int main(void) {
    const char * strings[] = {"Spam", "Cheese", "Knights", "Holy Grail", "Lumberjack", "Ministry", "Swallow",
                              "Silly", "Black Knight", "Camelot", "Coconut", "Parrot", "Shrubbery", "Taunt", "Argument"};

    qsort(strings, 15, sizeof(*strings), compare_strings);
    print_string_array(strings, sizeof(strings) / sizeof(const char *));

    const char * targets[] = {"Holy Grail", "Parrot", "Rabbit"};
    
    for (size_t i = 0; i < 3; i++)
    {
        bsearch_result_t result = binary_search(&targets[i], strings, 15, sizeof(*strings), compare_strings);

        if (result.found)
        {
            printf("%s found at: %zu \n", targets[i], result.index);
        }
        else
        {
            printf("%s not found \n", targets[i]);
        }
    }
    
    return 0;
}
