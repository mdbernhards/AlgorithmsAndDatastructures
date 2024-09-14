#ifndef SETS_SET_H
#define SETS_SET_H

#include <stddef.h>
#include <stdbool.h>

typedef bool (*eq_fun_t)(double, double);

typedef struct set {
    eq_fun_t eq_fun;
    size_t capacity;
    size_t count;
    double * data;
} set_t;

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
/// \param eq_fun The function used to test if two values are equal
/// \return An initialized set, or NULL if it could not be created
set_t * set_create(size_t init_cap, eq_fun_t eq_fun);

/// Initializes a set
/// \param set The set to initialize
/// \param init_cap The initial capacity for the set
/// \param eq_fun The function used to compare two values
/// \return The initialized set
set_t * set_init(set_t * set, size_t init_cap, eq_fun_t eq_fun);

/// Deallocates the dynamic memory resources used by the set
/// Defined in shared/set.c
/// \param set The set to destroy
void set_destroy(set_t * set);

/// Ensures that the set can store at least one more element
/// Defined in shared/set.c
/// \param set The set
bool ensure_capacity(set_t * set);


#endif //SETS_SET_H
