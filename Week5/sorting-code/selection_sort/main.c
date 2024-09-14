#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <sortinglib/array.h>
#include "test_selection_sort.h"
#include "selection_sort.h"

// The global var g_compares is defined externally, in selection_sort.c
// Declaring it as "extern" allows us to use that variable here as well
extern size_t g_compares;

/// Part I - Selection sort

int main(void) {

    // FIXME: make sure these two tests pass (activities 2 and 3)
    test_find_min();

    test_array_sort();
    array_t testArray;
    array_init(&testArray, 10000);

    g_compares = 0;
    testArray.count = 5;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 10;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 15;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 20;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 50;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 100;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 150;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 250;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 500;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 1000;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 5000;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    g_compares = 0;
    testArray.count = 10000;
    array_sort(&testArray);
    printf("Size: %lu, Times: %lu\n",testArray.count, g_compares);

    // Activity 4: measure nr. of comparisons made

    // setup an array
    array_t array;
    array_init(&array, 0);
    for (int i = 10; i > 0; --i) array_append(&array, i);
    printf("Sorting array ");
    array_print(&array);

    g_compares = 0; // reset nr. of comparisons
    array_sort(&array); // sort the array
    printf(" -> ");
    array_print(&array);
    printf(" (%zu comparisons)\n", g_compares);

    array_destroy(&array);  // cleanup
    return 0;
}
