#ifndef HASHING_STATISTICS_H
#define HASHING_STATISTICS_H

#include "hashmap.h"
#include <stdio.h>

typedef struct load_statistics {
    float free_slots_fraction;              // empty slots / total slots
    float load_factor;                      // count / capacity
    size_t slots_with_more_than_x_items[5];   // nr. of lists with more than 0..4 nodes
    size_t length_of_longest_chain;         // longest list length
} load_statistics_t;

/// Computes the load statistics of the given hashmap.
/// @param map the hashmap to analyze
/// @return the load statistics of the hashmap
load_statistics_t hashmap_get_load_statistics(const hashmap_t *map);

/// Prints the load statistics of the given hashmap to the given file.
/// @param f the file to print to (to print to stdout, use stdout)
/// @param map the hashmap to analyze
void hashmap_print_load_statistics(FILE *f, const hashmap_t *map);

#endif //HASHING_STATISTICS_H
