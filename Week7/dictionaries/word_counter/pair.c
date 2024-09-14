//
// Created by rgr24 on 16/03/2024.
//

#include "pair.h"
#include <string.h>
#include <stdlib.h>

int compare_pairs(const pair_t* a, const pair_t* b) {
    return strcmp(a->key, b->key);
}

int compare_pair_values(const void* a, const void* b) 
{
    const pair_t pair_t_ptr_a = *(const pair_t *)a;
    const pair_t pair_t_ptr_b = *(const pair_t *)b;
    return pair_t_ptr_b.value - pair_t_ptr_a.value;
}

pair_t make_pair(const char *string) {
    char * buf = malloc(strlen(string) + 1);    // allocate enough memory to hold the string, including the terminating zero
    strcpy(buf, string);    // copy the string into the buffer
    pair_t result = { .key = buf, .value = 1 }; // create a pair_t with the string as key and a value of 1
    return result;
}

void destroy_pair(pair_t *pair) {
    free((void*) pair->key);    // deallocate the memory that was allocated for storing the key
    pair->key = NULL;           // set key to NULL to avoid dangling pointers
}
