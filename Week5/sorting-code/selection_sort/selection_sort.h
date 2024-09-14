#ifndef SORTING_SELECTION_SORT_H
#define SORTING_SELECTION_SORT_H

#include <sortinglib/array.h>

/// Finds the minimum value in an array of integers
/// \param values Address of a (non-dynamic) array
/// \param count The number of elements in the array
/// \return Address of the minimum element, or NULL if there are no elements
int *find_min(int *values, size_t count);

/// Sorts an array, using selection sort
/// \param array The array to be sorted
void array_sort(array_t *array);

#endif //SORTING_SELECTION_SORT_H
