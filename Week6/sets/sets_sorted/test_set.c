//
// Created by rgr24 on 21/03/2023.
//

#include <stdio.h>
#include "test_set.h"
#include <set.h>
#include <math.h>
#include <assert.h>

/// Simple comparison function that can be used in a set_t, for testing purposes.
/// According to this function, a and b are equal if they're less than 0.5 apart
/// \param a
/// \param b
/// \return 0 if a and b are considered equal, -1 if a < b, and 1 if a > b
int simple_double_equals(double a, double b) {
    if (fabs(a - b) < 0.5) return 0;
    else if (a > b) return 1;
    else return -1;
}

int accurate_double_equals(double a, double b) {
    if (fabs(a - b) < 1e-5) return 0;
    else if (a > b) return 1;
    else return -1;
}

void test_sorted_set_add(void) {
    set_t set;
    set_init(&set, 10, simple_double_equals);
    set_add(&set, 1.0);
    assert(set.count == 1);
    assert(set.data[0] == 1.0);

    set_add(&set, 0.0);
    assert(set.count == 2);
    assert(set.data[0] == 0.0);
    assert(set.data[1] == 1.0);

    set_add(&set, 4.0);
    assert(set.count == 3);
    assert(set.data[0] == 0.0);
    assert(set.data[1] == 1.0);
    assert(set.data[2] == 4.0);

    set_add(&set, 3.0);
    assert(set.count == 4);
    assert(set.data[0] == 0.0);
    assert(set.data[1] == 1.0);
    assert(set.data[2] == 3.0);
    assert(set.data[3] == 4.0);

    set_add(&set, 3.3);
    assert(set.count == 4);
    assert(set.data[0] == 0.0);
    assert(set.data[1] == 1.0);
    assert(set.data[2] == 3.0);
    assert(set.data[3] == 4.0);

    set_add(&set, 2.0);
    assert(set.count == 5);
    assert(set.data[0] == 0.0);
    assert(set.data[1] == 1.0);
    assert(set.data[2] == 2.0);
    assert(set.data[3] == 3.0);
    assert(set.data[4] == 4.0);

    set_destroy(&set);

    fputs("test_sorted_set_add PASS\n", stderr);
}

void test_sorted_set_remove(void) {
    set_t set;
    set_init(&set, 5, simple_double_equals);

    set.data[0] = 4.0;
    set.data[1] = 5.0;
    set.data[2] = 10.0;
    set.data[3] = 11.0;
    set.data[4] = 21.0;
    set.count = 5;

    set_remove(&set, 0.0);
    assert(set.count == 5);

    set_remove(&set, 5.3);
    assert(set.count == 4);
    assert(set.data[0] == 4.0);
    assert(set.data[1] == 10.0);
    assert(set.data[2] == 11.0);
    assert(set.data[3] == 21.0);

    set_remove(&set, 21.1);
    assert(set.count == 3);
    assert(set.data[0] == 4.0);
    assert(set.data[1] == 10.0);
    assert(set.data[2] == 11.0);

    set_remove(&set, 4.1);
    assert(set.count == 2);
    assert(set.data[0] == 10.0);
    assert(set.data[1] == 11.0);

    set_remove(&set, 11.2);
    assert(set.count == 1);
    assert(set.data[0] == 10.0);

    set_remove(&set, 10.3);
    assert(set.count == 0);

    set_destroy(&set);

    fputs("test_sorted_set_remove PASS\n", stderr);
}

void test_sorted_set_contains(void) {
    set_t set;
    set_init(&set, 9, simple_double_equals);

    set.data[0] = 4.0;
    set.data[1] = 5.0;
    set.data[2] = 10.0;
    set.data[3] = 11.0;
    set.data[4] = 21.0;
    set.data[5] = 25.0;
    set.data[6] = 30.0;
    set.data[7] = 42.0;
    set.data[8] = 420.0;
    set.count = 9;

    assert(set_contains(&set, 4.1));
    assert(set_contains(&set, 4.8));
    assert(set_contains(&set, 10.1));
    assert(set_contains(&set, 10.9));
    assert(set_contains(&set, 21.0));
    assert(set_contains(&set, 24.7));
    assert(set_contains(&set, 30.2));
    assert(set_contains(&set, 42.1));
    assert(set_contains(&set, 420.4));

    assert(!set_contains(&set, 7.0));
    assert(!set_contains(&set, 12.0));
    assert(!set_contains(&set, 20.0));
    assert(!set_contains(&set, 24.0));
    assert(!set_contains(&set, 28.0));
    assert(!set_contains(&set, 45.0));
    assert(!set_contains(&set, 450.0));

    set.cmp_fun = accurate_double_equals;
    assert(set_contains(&set, 4.0));
    assert(!set_contains(&set, 4.1));
    assert(!set_contains(&set, 4.8));
    assert(set_contains(&set, 5.0));
    assert(set_contains(&set, 42.0));
    assert(!set_contains(&set, 42.1));

    set_destroy(&set);

    fputs("test_sorted_set_contains PASS\n", stderr);
}

void test_sorted_set_index_of(void) {
    set_t set;
    set_init(&set, 10, simple_double_equals);
    size_t idx = set_index_of(&set, 0.0);
    assert(0 == idx);

    set.data[0] = 1.0;
    set.count = 1;
    idx = set_index_of(&set, 0.0);
    assert(0 == idx);
    idx = set_index_of(&set, 1.0);
    assert(0 == idx);
    idx = set_index_of(&set, 1.4);
    assert(0 == idx);
    idx = set_index_of(&set, 2.0);
    assert(1 == idx);

    set.data[1] = 5.0;
    set.count = 2;
    idx = set_index_of(&set, 2.0);
    assert(1 == idx);
    idx = set_index_of(&set, 5.0);
    assert(1 == idx);
    idx = set_index_of(&set, 6.0);
    assert(2 == idx);

    set.data[2] = 10.0;
    set.data[3] = 11.0;
    set.data[4] = 21.0;
    set.data[5] = 25.0;
    set.data[6] = 30.0;
    set.data[7] = 42.0;
    set.data[8] = 420.0;
    set.count = 9;

    assert(2 == set_index_of(&set, 10.1));
    assert(3 == set_index_of(&set, 11.2));
    assert(4 == set_index_of(&set, 21.3));
    assert(5 == set_index_of(&set, 25.4));
    assert(6 == set_index_of(&set, 30.1));
    assert(7 == set_index_of(&set, 42.2));
    assert(8 == set_index_of(&set, 420.3));

    set_destroy(&set);

    fputs("test_sorted_set_index_of PASS\n", stderr);
}
