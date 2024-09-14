#ifndef HASHING_PAIR_H
#define HASHING_PAIR_H

#include <stddef.h>

typedef struct pair {
    const char * key;
    size_t value;
} pair_t;

/// Creates a new pair with the given key and value.
/// Allocates memory for the pair and for the key.
/// @param key the key of the pair
/// @param value the value of the pair
pair_t *create_pair(const char *key, size_t value);

/// Frees the memory allocated for the pair and the key.
/// @param pair the pair to destroy
void destroy_pair(pair_t *pair);

#endif //HASHING_PAIR_H
