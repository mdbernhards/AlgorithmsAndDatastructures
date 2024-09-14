//
// Created by rgr24 on 07/04/2023.
//

#ifndef HASHING_TEST_HASHMAP_H
#define HASHING_TEST_HASHMAP_H

#include "hashmap.h"

void test_hashmap_init(void);
void test_hashmap_add(void);
void test_hashmap_lookup(void);
void test_hashmap_get(void);
void test_hashmap_remove(void);
void test_hashmap_rehash(void);

void test_fnv1a(hash_fun_t fun);
void test_contract(hash_fun_t hashfun, eq_fun_t eqfun);
void test_equality_fun(eq_fun_t fun);

#endif //HASHING_TEST_HASHMAP_H
