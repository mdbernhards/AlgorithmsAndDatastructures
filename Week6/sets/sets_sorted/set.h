#ifndef SETS_SET_H
#define SETS_SET_H

#include <stddef.h>
#include <stdbool.h>

// Function pointer type to point to a function that compares two doubles
// and returns -1, 0, or 1
typedef int (*compare_fun_t)(double, double);

typedef struct set {
    compare_fun_t cmp_fun;
    size_t capacity;
    size_t count;
    double * data;
} set_t;

/// Uses binary search to find either the location of a value, or the location at which
/// the value should be inserted to maintain a sorted order.
/// \param set The set to search
/// \param value The value to search for in the set
/// \return The index of the value in the set's data array at which it is found, or into which it should be inserted.
size_t set_index_of(const set_t * set, double value);

/// Adds a value to a set, if it is not already present
/// \param set The set to add the value to
/// \param value The value to add to the set
void set_add(set_t * set, double value);

/// Removes a value from a set, if it is present
/// \param set The set to remove the value from
/// \param value The value to remove from the set
void set_remove(set_t * set, double value);

/// Checks if a value is in the set
/// \param set The set to search
/// \param value The value to search for in the set
/// \return true if the value is present, false if it is not
bool set_contains(const set_t * set, double value);

/// Heap-allocates a set and initializes it
/// \param init_cap The initial capacity for the set
/// \param cmp_fun The function used to compare two values
/// \return An initialized set, or NULL if it could not be created
set_t * set_create(size_t init_cap, compare_fun_t cmp_fun);

/// Initializes a set
/// \param set The set to initialize
/// \param init_cap The initial capacity for the set
/// \param cmp_fun The function used to compare two values
/// \return The initialized set
set_t * set_init(set_t * set, size_t init_cap, compare_fun_t cmp_fun);

/// Deallocates the dynamic memory resources used by the set
/// Defined in shared/set.c
/// \param set The set to destroy
void set_destroy(set_t * set);

/// Ensures that the set can store at least one more element
/// Defined in shared/set.c
/// \param set The set
bool ensure_capacity(set_t * set);


#endif //SETS_SET_H
