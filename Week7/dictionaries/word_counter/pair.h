//
// Created by rgr24 on 16/03/2024.
//

#ifndef DICTIONARIES_PAIR_H
#define DICTIONARIES_PAIR_H

typedef struct pair {
    const char * key;   // the key, which is the thing we're counting
    unsigned long value;       // the count associated with the key
} pair_t;

typedef int (*pair_compare_fun_t)(const pair_t*,const pair_t);

/// A function to compare two pairs based on their key
int compare_pairs(const pair_t* a, const pair_t* b);

int compare_pair_values(const void *a, const void *b);

/// Returns a pair that contains a heap-allocated copy of the string as its key, and value set to 1
/// \param string the key
/// \return a pair with key counter to the heap-allocated copy of string as its key, and value set to 1
pair_t make_pair(const char * string);

/// Destroys a pair by deallocating the memory used to store the key
/// \param pair The pair to destroy
void destroy_pair(pair_t *pair);

#endif //DICTIONARIES_PAIR_H
