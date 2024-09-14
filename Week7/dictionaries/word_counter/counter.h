#ifndef DICTIONARIES_COUNTER_H
#define DICTIONARIES_COUNTER_H

#include <stddef.h>
#include <stdbool.h>
#include "pair.h"

typedef struct counter {
    pair_compare_fun_t *cmp_fun;
    pair_t *data;             // dynamic array
    size_t capacity;        // current capacity of data (max. nr. of items that can be contained)
    size_t count;           // current nr. of items in data
} counter_t;

/// Checks if an item is in the counter
/// \param counter The counter to search
/// \param key The item to search for in the counter
/// \return true if the item is present, false if it is not
bool counter_contains_key(const counter_t *counter, const char *key);

/// Returns the count associated with the given key, or 0 if the key is not present
/// TODO: Implement in counter.c
/// \param counter
/// \param key
/// \return the count associated with string, or 0 if string is not in the counter
size_t counter_get_count(const counter_t *counter, const char *key);

/// Looks up the string in the counter, and increments its associated count (by one) if
/// it string was found. Otherwise, adds string to the counter with an associated count of one.
/// TODO: Implement in counter.c
/// \param counter
/// \param key
void counter_increment(counter_t *counter, const char *key);

/// Removes the key from the counter. If it does not exist, the function does nothing.
/// \param counter The counter to remove the key from
/// \param key The key to remove
void counter_remove_key(counter_t *counter, const char *key);

/// Heap-allocates a counter and initializes it
/// \param init_cap The initial capacity for the counter
/// \param init_size The size (nr. of bytes) of a single item
/// \param cmp_fun The function used to compare two keys
/// \return An initialized counter, or NULL if it could not be created
counter_t *counter_create(size_t init_cap);

/// Initializes a counter
/// \param counter The counter to initialize
/// \param init_cap The initial capacity for the counter
/// \param init_size The size (nr. of bytes) of a single item
/// \param cmp_fun The function used to compare two values
/// \return The initialized counter
counter_t *counter_init(counter_t *counter, size_t init_cap);

/// Deallocates the dynamic memory resources used by the counter
/// \param counter The counter to destroy
void counter_destroy(counter_t *counter);

#endif //DICTIONARIES_COUNTER_H
