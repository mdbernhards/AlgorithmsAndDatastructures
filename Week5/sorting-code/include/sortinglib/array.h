#ifndef SORTING_ARRAY_H
#define SORTING_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct array {
    size_t capacity, count;
    int * data;
} array_t;

/// Swaps two integers
/// \param x The address at which the first int is stored
/// \param y The address at which the second int is stored
void swap(int *x, int *y);

/// Allocates memory for storing as many ints as given by the cap
/// \param array The array to initialize
/// \param cap The number of ints to store in the array
void array_init(array_t * array, size_t cap);

/// Deallocates up the memory held by the array
/// \param array The array
void array_destroy(array_t * array);

/// Appends the given value to the given array
/// \param array
/// \param value
void array_append(array_t * array, int value);

/// Prints the contents of an array
/// \param array The array to print
void array_print(const array_t * array);

/// Checks if an array is fully sorted
/// \param array The array to check
/// \return true if the array is sorted, false otherwise
bool array_is_sorted(const array_t *array);

#endif //SORTING_ARRAY_H
