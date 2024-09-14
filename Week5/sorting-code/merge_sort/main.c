#include <stdio.h>
#include <sortinglib/list.h>
#include "merge_sort.h"
#include "test_merge_sort.h"

// The global var g_compares is defined externally, in merge_sort.c
// Declaring it as "extern" allows us to use that variable here as well
extern size_t g_compares;

/// Part II - Merge sort

int main(void) {
    /*
    test_split();
    test_merge();
    test_merge_sort();

*/
    list_t list;
    list_init(&list);
    g_compares = 0;
    list_append_multi(&list, (int[]) {5, 4, 3, 2, 1}, 5);
    list_sort(&list);

    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    list_append_multi(&list, (int[]) {1, 2, 3, 4, 5}, 5);
    list_sort(&list);

    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 15; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 20; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 50; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 100; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 250; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 500; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 1000; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 5000; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    g_compares = 0;
    for (size_t i = 0; i < 100000; i++)
    {
        list_append_multi(&list, (int[]) {i}, 1);
    }
    list_sort(&list);
    printf("Sorting ");
    printf(": %zu comparisons\n", g_compares);
    list_destroy(&list);

    return 0;
}
