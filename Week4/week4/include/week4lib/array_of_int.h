#ifndef WEEK4_ARRAY_OF_INT_H
#define WEEK4_ARRAY_OF_INT_H

#include <stdbool.h>

typedef struct array array_t;

array_t *array_create(size_t capacity);

void array_destroy(array_t* array);

void array_push_back(array_t* array, int value);

bool try_array_pop_back(array_t* array, int * value);

#endif //WEEK4_ARRAY_OF_INT_H
