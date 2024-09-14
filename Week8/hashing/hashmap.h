//
// Created by rgr24 on 04/04/2023.
//

#ifndef HASHING_HASHMAP_H
#define HASHING_HASHMAP_H

#include "list.h"
#include <stdbool.h>
#include <stddef.h>
#include "pair.h"

typedef size_t (*hash_fun_t)(const char *);
typedef bool (*eq_fun_t)(const char *, const char *);

typedef struct hashmap {
    hash_fun_t hash_fun;
    eq_fun_t equals_fun;
    list_t *slots;
    size_t capacity;
    size_t count;
} hashmap_t;

pair_t * hashmap_lookup(const hashmap_t *map, const char *key);
bool hashmap_contains_key(const hashmap_t *map, const char *key);
bool hashmap_add(hashmap_t *map, const char *key, size_t value);
size_t hashmap_get_value(const hashmap_t *map, const char *key);

void hashmap_remove(hashmap_t *map, const char *key);

/// Rehashes the set to the given capacity.
/// \param map the hashset to rehash
/// \param new_capacity the new capacity of the hashset
void hashmap_rehash(hashmap_t *map, size_t new_capacity);

void hashmap_destroy(hashmap_t *map);

hashmap_t *hashmap_create(size_t capacity, hash_fun_t hash_fun, eq_fun_t equals_fun);

hashmap_t *hashmap_init(hashmap_t *map, size_t capacity, hash_fun_t hash_fun, eq_fun_t equals_fun);

#endif //HASHING_HASHMAP_H
