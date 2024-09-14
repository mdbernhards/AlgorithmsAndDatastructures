#include <stdio.h>

#include "test_hashmap.h"
#include "hashmapfunctions.h"

size_t simple_hash(const char* str) 
{
    size_t hash = 0;
    while (*str) 
    {
        hash += *str;
        str++;
    }

    return hash;
}

int main(void) {
    test_fnv1a((hash_fun_t) fnv1a_hash);    // FIXME: Make tests pass (Activity 5)
    test_equality_fun((eq_fun_t) str_equals);   // FIXME: Make tests pass (Activity 6)
    test_contract((hash_fun_t) fnv1a_hash, (eq_fun_t) str_equals);  // FIXME: Make tests pass (Activity 5 & 6)
    test_hashmap_init();
    test_hashmap_lookup();  // FIXME: Make tests pass (Activity 7)
    test_hashmap_add();
    test_hashmap_remove();
    test_hashmap_get();
    test_hashmap_rehash();

    /*
    const char* array[11] = {"pictures", "strength", "partners", "computer", "empty",
        "words", "nasty", "spoon", "visit", "busy", "work"};

    for (size_t i = 0; i < 11; i++)
    {
        size_t hash = simple_hash(array[i]);
        printf("%s has the hash: %zu \n", array[i], hash);
    } // FIXME: Make tests pass (Activity 8)  // FIXME: Make tests pass (Activity 8)  // FIXME: Make tests pass (Activity 12)
    */
    return 0;
}
