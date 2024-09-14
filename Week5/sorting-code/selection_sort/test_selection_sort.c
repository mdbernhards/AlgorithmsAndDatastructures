#include "test_selection_sort.h"
#include "selection_sort.h"
#include <assert.h>
#include <stdio.h>

void test_array_sort(void) {
    array_t array;
    array_init(&array, 1);
    array_append(&array, 1);
    array_sort(&array); // sort the array {1}
    assert(1 == array.count);
    assert(array_is_sorted(&array));

    array.count = 0;
    array_sort(&array); // sorting an empty array
    assert(0 == array.count);

    array_append(&array, 4);
    array_append(&array, 3);
    array_append(&array, 2);
    array_append(&array, 1);
    array_sort(&array); // sort the array {4, 3, 2, 1}
    assert(4 == array.count);
    assert(array_is_sorted(&array));

    array.count = 0;
    array_append(&array, 4);
    array_append(&array, 3);
    array_append(&array, 2);
    array_append(&array, 1);
    array_append(&array, 5);
    array_append(&array, 6);
    array_append(&array, 7);
    array_append(&array, 8);
    array_sort(&array); // sort the array {4, 3, 2, 1, 5, 6, 7, 8}
    assert(8 == array.count);
    assert(array_is_sorted(&array));

    array_destroy(&array);

    fputs("test_array_sort PASSED\n", stderr);
}

void test_find_min(void) {
    int * ptr = find_min(NULL, 0);  // finding the min. element of a non-existing array
    assert(NULL == ptr);            // must return NULL

    int values[] = {-3, -4, -2, -5, -3};
    ptr = find_min(values, 5);      // finding the min. element in the array "values", which has 5 elements
    assert(&values[3] == ptr);      // must return the address of the fourth element (at index 3)

    int values2[] = {3, 2, 1, 3, 2};
    ptr = find_min(values2, 5);     // finding the min. element in the array "values2", which has 5 elements
    assert(values2 + 2 == ptr);     // must return the address of the third element (at index 2)

    int values3[] = {1, 2, 3 };
    ptr = find_min(values3, 3);     // finding the min. element in the array "values3", which has 3 elements
    assert(values3 == ptr);         // must return the address of the first element (at index 0)

    fputs("test_find_min PASSED\n", stderr);
}
