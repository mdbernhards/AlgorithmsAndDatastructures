#ifndef HASHING_COMPLETED_HASHFUNCTIONS_H
#define HASHING_COMPLETED_HASHFUNCTIONS_H

#include <stddef.h>
#include <stdbool.h>

/// Computes the FNV-1a hash of the given string.
/// @see Activity 5
/// @param str the string to hash
/// @return the hash of the string
size_t fnv1a_hash(const char *str);

/// Compares two strings for equality, ignoring case.
/// @see Activity 6
/// @param s1 the first string
/// @param s2 the second string
/// @return true if the strings are equal, false otherwise
bool str_equals(const char *s1, const char *s2);

#endif //HASHING_COMPLETED_HASHFUNCTIONS_H
