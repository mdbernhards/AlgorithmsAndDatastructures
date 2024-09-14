//
// Created by rgr24 on 04/04/2023.
//

#include <malloc.h>
#include <string.h>
#include "hashmap.h"

/// Rehashes the map if the load factor is greater than 0.70.
/// @see Activity 12
/// @param map the map to rehash
static void _rehash(hashmap_t * map) {
    if (map->count * 10 < map->capacity * 7) return;        // no need to rehash if load factor < 0.70
    hashmap_rehash(map, map->capacity * 3 / 2);
}

pair_t * hashmap_lookup(const hashmap_t *map, const char *key) 
{
    if (!map || !key) 
    {
        return NULL;
    }

    size_t index = map->hash_fun(key) % map->capacity;
    node_t *current = (map->slots[index]).head;
    
    while (current) 
    {
        pair_t *pair = current->data;
        if (map->equals_fun(pair->key, key)) 
        {
            return pair;
        }
        
        current = current->next;
    }
    
    return NULL;
}

bool hashmap_contains_key(const hashmap_t *map, const char *key) {
    return hashmap_lookup(map, key) != NULL;
}

bool hashmap_add(hashmap_t *map, const char *key, size_t value) 
{
    if (!map || !key) 
    {
        return false;
    }

    pair_t *pair = hashmap_lookup(map, key);

    if (pair) 
    {
        pair->value = value;
        return false;
    }

    pair_t *tempPair = create_pair(key, value);
    node_t *tempNode = node_create(tempPair);

    size_t index = map->hash_fun(key) % map->capacity;
    list_prepend(&map->slots[index], tempNode);

    map->count++;
    _rehash(map);
    
    return true;
}

size_t hashmap_get_value(const hashmap_t *map, const char *key) {
    const pair_t * existing = hashmap_lookup(map, key);
    if (existing != NULL) return existing->value;
    else return 0;
}

void hashmap_remove(hashmap_t *map, const char *key) 
{
    if (!map || !key) 
    {
        return;
    }

    size_t index = map->hash_fun(key) % map->capacity;

    node_t *current = map->slots[index].head;
    node_t *last = NULL;

    while (current) 
    {
        pair_t *pair = current->data;
        if (map->equals_fun(pair->key, key)) 
        {
            if (last) 
            {
                last->next = current->next;
            } 
            else 
            {
                map->slots[index].head = current->next;
            }

            destroy_pair(pair);
            free(current);
            map->count--;

            return;
        }

        last = current;
        current = current->next;
    }
}


hashmap_t *hashmap_init(hashmap_t *map, size_t capacity, hash_fun_t hash_fun, eq_fun_t equals_fun) {
    if (map == NULL) return NULL;
    map->slots = malloc(sizeof(list_t) * capacity);
    map->capacity = capacity;
    map->count = 0;
    map->hash_fun = hash_fun;
    map->equals_fun = equals_fun;
    for (size_t i = 0; i < map->capacity; ++i) {
        list_init(map->slots + i);
    }
    return map;
}

hashmap_t *hashmap_create(size_t capacity, hash_fun_t hash_fun, eq_fun_t equals_fun) {
    return hashmap_init((hashmap_t *) malloc(sizeof(hashmap_t)), capacity, hash_fun, equals_fun);
}

void hashmap_destroy(hashmap_t *map) {
    if (map == NULL) return;
    for (size_t i = 0; i < map->capacity; ++i) {
        for (node_t *current = map->slots[i].head; current != NULL; current = current->next) {
            destroy_pair((pair_t *) current->data);
        }
        list_destroy(map->slots + i);
    }
    free(map->slots);
    map->slots = NULL;
}


void hashmap_rehash(hashmap_t *map, size_t new_capacity) 
{
    list_t *newSlots = malloc(sizeof(list_t*) * new_capacity);
    for (size_t i = 0; i < new_capacity; i++) 
    {
        list_init(&newSlots[i]);
    }

    for (size_t i = 0; i < map->capacity; i++)
    {
        node_t* current = map->slots[i].head;
        while (current) 
        {
            node_t* next = current->next;
            pair_t* temp = current->data;

            size_t index = map->hash_fun(temp->key) % new_capacity;
            list_prepend(&newSlots[index], current);
            
            current = next;
        }
    }

    free(map->slots);

    map->capacity = new_capacity;
    map->slots = newSlots;
}

