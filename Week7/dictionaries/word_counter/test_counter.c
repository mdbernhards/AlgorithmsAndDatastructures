//
// Created by rgr24 on 01/04/2023.
//

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "test_counter.h"
#include "counter.h"

extern size_t num_calls_to_binary_search;

void test_counter_init(void) {
    counter_t counter;
    counter_init(&counter, 10);
    assert(counter.count == 0);
    assert(counter.capacity == 10);

    free(counter.data);

    fputs("test_counter_init PASS\n", stderr);
}

void test_counter_contains_key(void) {
    counter_t counter;
    counter_init(&counter, 2);

    // can't find Alice because there are no contents
    assert(!counter_contains_key(&counter, "Alice"));

    counter.data[0] = (pair_t) { .key = "Alice", .value = 1 };
    counter.data[1] = (pair_t) { .key = "Rabbit", .value = 10 };
    counter.count = 2;

    assert(counter_contains_key(&counter, "Alice"));
    assert(counter_contains_key(&counter, "Rabbit"));
    assert(!counter_contains_key(&counter, "Potion"));

    free(counter.data);

    // fill with unsorted content
    counter_init(&counter, 6);
    counter.data[0] = (pair_t) { .key = "Alice", .value = 1 };
    counter.data[1] = (pair_t) { .key = "Bob", .value = 10 };
    counter.data[2] = (pair_t) { .key = "Charlie", .value = 10 };
    counter.data[3] = (pair_t) { .key = "Dave", .value = 10 };
    counter.data[4] = (pair_t) { .key = "Eve", .value = 10 };
    // Apples shouldn't be here, this serves to test whether binary search is used
    // (linear search will find it, binary search will not)
    counter.data[5] = (pair_t) { .key = "Apples", .value = 10 };
    counter.count = 6;

    assert(counter_contains_key(&counter, "Alice"));
    assert(!counter_contains_key(&counter, "Apples"));

    free(counter.data);

    fputs("test_counter_contains_key PASS\n", stderr);
}

void test_counter_get_count(void) {
    counter_t counter;
    counter_init(&counter, 2);

    // can't find Alice because there are no contents
    assert(counter_get_count(&counter, "Alice") == 0);

    counter.data[0] = (pair_t) { .key = "Alice", .value = 1 };
    counter.data[1] = (pair_t) { .key = "Rabbit", .value = 10 };
    counter.count = 2;

    assert(counter_get_count(&counter, "Alice") == 1);
    assert(counter_get_count(&counter, "Rabbit") == 10);
    assert(counter_get_count(&counter, "Alice") == 1);
    // Potion is not in the counter, so the count should be 0
    assert(counter_get_count(&counter, "Potion") == 0);

    free(counter.data);

    // fill with unsorted content
    counter_init(&counter, 6);
    counter.data[0] = (pair_t) { .key = "Alice", .value = 1 };
    counter.data[1] = (pair_t) { .key = "Bob", .value = 10 };
    counter.data[2] = (pair_t) { .key = "Charlie", .value = 10 };
    counter.data[3] = (pair_t) { .key = "Dave", .value = 10 };
    counter.data[4] = (pair_t) { .key = "Eve", .value = 10 };
    // Apples shouldn't be here, this serves to test whether binary search is used
    // (linear search will find it, binary search will not)
    counter.data[5] = (pair_t) { .key = "Apples", .value = 10 };
    counter.count = 6;

    assert(counter_get_count(&counter, "Alice") == 1);
    assert(counter_get_count(&counter, "Apples") == 0);

    free(counter.data);

    fputs("test_counter_get_count PASS\n", stderr);
}

void test_counter_remove_key(void) {
    counter_t counter;
    counter_init(&counter, 4);

    counter.data[0] = make_pair("Alice");
    counter.data[1] = make_pair("Caterpillar");
    counter.data[2] = make_pair("Rabbit");
    counter.data[3] = make_pair("Wonderland");
    counter.count = 4;

    counter_remove_key(&counter, "MadHatter");
    assert(counter.count == 4);

    counter_remove_key(&counter, "Caterpillar");
    assert(counter.count == 3);
    assert(strcmp(counter.data[0].key, "Alice") == 0);
    assert(strcmp(counter.data[1].key, "Rabbit") == 0);
    assert(strcmp(counter.data[2].key, "Wonderland") == 0);

    counter_remove_key(&counter, "Alice");
    assert(counter.count == 2);
    assert(strcmp(counter.data[0].key, "Rabbit") == 0);
    assert(strcmp(counter.data[1].key, "Wonderland") == 0);

    counter_remove_key(&counter, "Wonderland");
    assert(counter.count == 1);
    assert(strcmp(counter.data[0].key, "Rabbit") == 0);

    counter_remove_key(&counter, "Rabbit");
    assert(counter.count == 0);

    free(counter.data);

    // fill with unsorted content
    counter_init(&counter, 6);
    counter.data[0] = (pair_t) { .key = "Alice", .value = 1 };
    counter.data[1] = (pair_t) { .key = "Bob", .value = 10 };
    counter.data[2] = (pair_t) { .key = "Charlie", .value = 10 };
    counter.data[3] = (pair_t) { .key = "Dave", .value = 10 };
    counter.data[4] = (pair_t) { .key = "Eve", .value = 10 };
    // Apples shouldn't be here, this serves to test whether binary search is used
    // (linear search will find it, binary search will not)
    counter.data[5] = (pair_t) { .key = "Apples", .value = 10 };
    counter.count = 6;

    // Nothing is removed when removing "Apples" because binary search can't find it
    counter_remove_key(&counter, "Apples");
    assert(counter.count == 6);

    free(counter.data);

    fputs("test_counter_remove_key PASS\n", stderr);
}

void test_counter_increment(void) {
    counter_t counter;
    counter_init(&counter, 2);

    counter_increment(&counter, "Rabbit");
    assert(counter.count == 1);
    assert(strcmp(counter.data[0].key, "Rabbit") == 0);
    assert(counter.data[0].value == 1);

    counter_increment(&counter, "Alice");
    assert(counter.count == 2);
    assert(strcmp(counter.data[0].key, "Alice") == 0);
    assert(counter.data[0].value == 1);
    assert(strcmp(counter.data[1].key, "Rabbit") == 0);
    assert(counter.data[1].value == 1);

    counter_increment(&counter, "Alice");
    assert(counter.count == 2);
    assert(strcmp(counter.data[0].key, "Alice") == 0);
    assert(counter.data[0].value == 2);
    assert(strcmp(counter.data[1].key, "Rabbit") == 0);
    assert(counter.data[1].value == 1);

    counter_increment(&counter, "Potion");
    assert(counter.count == 3);

    assert(strcmp(counter.data[0].key, "Alice") == 0);
    assert(counter.data[0].value == 2);
    assert(strcmp(counter.data[1].key, "Potion") == 0);
    assert(counter.data[1].value == 1);
    assert(strcmp(counter.data[2].key, "Rabbit") == 0);
    assert(counter.data[2].value == 1);

    counter_increment(&counter, "Wonderland");
    assert(counter.count == 4);

    assert(strcmp(counter.data[0].key, "Alice") == 0);
    assert(counter.data[0].value == 2);
    assert(strcmp(counter.data[1].key, "Potion") == 0);
    assert(counter.data[1].value == 1);
    assert(strcmp(counter.data[2].key, "Rabbit") == 0);
    assert(counter.data[2].value == 1);
    assert(strcmp(counter.data[3].key, "Wonderland") == 0);
    assert(counter.data[3].value == 1);

    counter_destroy(&counter);

    fputs("test_counter_increment PASS\n", stderr);
}

