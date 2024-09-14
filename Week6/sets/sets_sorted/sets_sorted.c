#include <stdio.h>
#include <math.h>
#include "set.h"
#include "test_set.h"

// global var to keep track of nr. of comparisons in binary search (activity 8)
extern size_t g_comparisons;

int cmp_dbl(double d1, double d2){
    if ((d1-d2) < (__FLT_EPSILON__ * -1))
    {
        return -1;
    }
    else if ((d1-d2) > __FLT_EPSILON__)
    {
        return 1;
    }

    return 0;
}

int main(void) {
    // Part 2 - a set using a sorted array

    // Activity 6
    // TODO: implement function cmp_dbl
    const double a = 41.0 + 0.5 + 0.2 + 0.2 + 0.1;
    const double b = 43.0 - 0.5 - 0.2 - 0.2 - 0.1;
    const double pi_1 = 3.14159265;
    const double pi_2 = 355.0 / 113.0;

    printf("compare(%lf, %lf) == %d\n", a, b, cmp_dbl(a, b));
    printf("compare(%lf, %lf) == %d\n", b, b, cmp_dbl(b, a));
    printf("compare(%.7lf, %.7lf) == %d\n", pi_1, pi_2, cmp_dbl(pi_1, pi_2));
    printf("compare(%.7lf, %.7lf) == %d\n", pi_2, pi_1, cmp_dbl(pi_2, pi_1));

    // Activity 7 - implement set_index_of
    test_sorted_set_index_of();

    // Activity 8 - Time complexity of binary search
    int count = 16;      // constant for array size used in set
    set_t set;                  // create a set variable
    set_init(&set, count, cmp_dbl);   // initialize the set
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0); // fill set
    g_comparisons = 0;          // reset comparison count
    set_index_of(&set, 9);    // run binary search to find 42.5
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 32;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 64;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 128;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 256;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 1000;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 4000;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 10000;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 9);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);
    
    count = 1048576;
    set_init(&set, count, cmp_dbl);
    for (int i = 0; i < count; ++i) set_add(&set, i * 2.0);
    g_comparisons = 0;
    set_index_of(&set, 333.5);
    printf("Binary search in %d elements. Nr. of comparisons: %zu\n", count, g_comparisons);

    // Activity 9 - Finalize the set
    test_sorted_set_contains();
    test_sorted_set_add();
    test_sorted_set_remove();

    return 0;
}
