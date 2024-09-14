#include "test_merge_sort.h"
#include "merge_sort.h"
#include <assert.h>
#include <stdio.h>

void test_split(void) {
    node_t *sequence = node_make_sequence((int[]) {1, 2}, 2);
    node_t *tail = split(sequence);
    // a list with two nodes is split into two lists of one node
    assert(1 == node_sequence_length(sequence));
    assert(1 == node_sequence_length(tail));
    node_sequence_destroy(sequence);
    node_sequence_destroy(tail);

    sequence = node_make_sequence((int[]) {1}, 1);
    // a list with one node can't be split
    tail = split(sequence);
    assert(1 == node_sequence_length(sequence));
    assert(NULL == tail);
    node_sequence_destroy(sequence);

    sequence = node_make_sequence((int[]) {1, 2, 3}, 3);
    tail = split(sequence);
    // when splitting a list that has an odd number of nodes into two lists,
    // the first has one node more than the second list
    assert(2 == node_sequence_length(sequence));
    assert(1 == node_sequence_length(tail));
    node_sequence_destroy(sequence);
    node_sequence_destroy(tail);

    sequence = node_make_sequence((int[]) {1, 2, 3, 4}, 4);
    tail = split(sequence);
    // when splitting a list that has an even number of nodes into two lists,
    // both lists have the same number of nodes
    assert(2 == node_sequence_length(sequence));
    assert(2 == node_sequence_length(tail));
    node_sequence_destroy(sequence);
    node_sequence_destroy(tail);

    fputs("test_split PASSED\n", stderr);
}

void test_merge(void) {
    node_t *first = node_make_sequence((int[]) {1, 3}, 2);
    node_t *second = node_make_sequence((int[]) {2, 4}, 2);
    node_t *result = merge(first, second);

    // merging {1, 3} and {2, 4} gives {1, 2, 3, 4}
    assert(result != NULL);
    assert(4 == node_sequence_length(result));
    assert(result->value == 1);
    assert(result->next->value == 2);
    assert(result->next->next->value == 3);
    assert(result->next->next->next->value == 4);
    node_sequence_destroy(result);

    first = node_make_sequence((int[]) {1, 2}, 2);
    second = node_make_sequence((int[]) {3, 4}, 2);
    result = merge(first, second);
    // merging {1, 2} and {3, 4} gives {1, 2, 3, 4}
    assert(result != NULL);
    assert(4 == node_sequence_length(result));
    assert(result->value == 1);
    assert(result->next->value == 2);
    assert(result->next->next->value == 3);
    assert(result->next->next->next->value == 4);
    node_sequence_destroy(result);

    first = node_make_sequence((int[]) {3, 4}, 2);
    second = node_make_sequence((int[]) {1, 2}, 2);
    result = merge(first, second);
    // merging {3, 4} and {1, 2} gives {1, 2, 3, 4}
    assert(result != NULL);
    assert(4 == node_sequence_length(result));
    assert(result->value == 1);
    assert(result->next->value == 2);
    assert(result->next->next->value == 3);
    assert(result->next->next->next->value == 4);
    node_sequence_destroy(result);

    first = NULL;
    // merging {} and {1} gives {1}
    assert(result != NULL);
    second = node_make_sequence((int[]) {1}, 1);
    result = merge(first, second);
    assert(1 == node_sequence_length(result));
    assert(result->value == 1);
    node_sequence_destroy(result);

    first = node_make_sequence((int[]) {1}, 1);
    second = NULL;
    // merging {1} and {} gives {1}
    assert(result != NULL);
    result = merge(first, second);
    assert(1 == node_sequence_length(result));
    assert(result->value == 1);
    node_sequence_destroy(result);

    first = node_make_sequence((int[]) {1, 5, 3}, 3);
    second = node_make_sequence((int[]) {2, 4, 0}, 3);
    result = merge(first, second);

    // merging {1, 5, 3} and {2, 4, 0} gives {1, 2, 4, 0, 5, 3}
    assert(result != NULL);
    assert(6 == node_sequence_length(result));
    assert(result->value == 1);
    assert(result->next->value == 2);
    assert(result->next->next->value == 4);
    assert(result->next->next->next->value == 0);
    assert(result->next->next->next->next->value == 5);
    assert(result->next->next->next->next->next->value == 3);
    node_sequence_destroy(result);

    fputs("test_merge PASSED\n", stderr);
}

void test_merge_sort(void) {
    node_t *sequence = node_make_sequence((int[]) {1}, 1);
    node_t *sorted = merge_sort(sequence);
    assert(1 == node_sequence_length(sorted));
    node_sequence_destroy(sorted);

    sequence = node_make_sequence((int[]) {4, 3, 2, 1}, 4);
    sorted = merge_sort(sequence);
    assert(4 == node_sequence_length(sorted));
    assert(list_is_sorted(sorted));
    node_sequence_destroy(sorted);

    sequence = node_make_sequence((int[]) {3, 5, 4, 2, 1}, 5);
    sorted = merge_sort(sequence);
    assert(5 == node_sequence_length(sorted));
    assert(list_is_sorted(sorted));
    node_sequence_destroy(sorted);

    sequence = node_make_sequence((int[]) {7, 8, 6, 3, 5, 4, 2, 1}, 8);
    sorted = merge_sort(sequence);
    assert(8 == node_sequence_length(sorted));
    assert(list_is_sorted(sorted));
    node_sequence_destroy(sorted);

    fputs("test_merge_sort PASSED\n", stderr);
}
