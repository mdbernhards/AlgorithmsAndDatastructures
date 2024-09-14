//
// Created by rgr24 on 07/04/2023.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "test_hashmap.h"
#include "hashmap.h"
#include <ctype.h>
#include <stdlib.h>

static unsigned long hash_strlen(const char *string) {
    return (unsigned long) (strlen(string) % 100);
}

static bool equals_str(const void *a, const void *b) {
    int i1 = 0, i2 = 0;
    const char *pa = (const char *) a, *pb = (const char *) b;
    for (;*pa != '\0'; ++pa) i1 += *pa - '0';
    for (;*pb != '\0'; ++pb) i2 += *pb - '0';
    return i1 == i2;
}

void test_hashmap_init(void) {
    hashmap_t map;
    hashmap_init(&map, 6, (hash_fun_t) hash_strlen, (eq_fun_t) equals_str);
    assert(map.capacity == 6);
    assert(map.count == 0);
    assert(map.hash_fun == (hash_fun_t) hash_strlen);
    assert(map.equals_fun == (eq_fun_t) equals_str);
    for (size_t i = 0; i < map.capacity; i++) {
        assert(map.slots[i].head == NULL);
    }
    free(map.slots);

    fputs("test_hashmap_init PASSED\n", stderr);
}

void test_hashmap_add(void) {
    bool res;
    hashmap_t map;
    hashmap_init(&map, 6, (hash_fun_t) hash_strlen, (eq_fun_t) equals_str);

    res = hashmap_add(&map, "12345", 1);
    assert(res);
    assert(map.slots[5].head != NULL);
    assert(equals_str(((pair_t*) map.slots[5].head->data)[0].key, "12345"));
    assert(((pair_t*) map.slots[5].head->data)[0].value == 1);
    assert(map.slots[5].head->next == NULL);

    res = hashmap_add(&map, "12", 42);
    assert(res);
    assert(map.slots[2].head != NULL);
    assert(equals_str(((pair_t*) map.slots[2].head->data)[0].key, "12"));
    assert(((pair_t*) map.slots[2].head->data)[0].value == 42);
    assert(map.slots[2].head->next == NULL);

    res = hashmap_add(&map, "12345012345", 15);
    assert(res);
    assert(map.slots[5].head != NULL);
    assert(equals_str(((pair_t*) map.slots[5].head->data)[0].key, "12345012345"));
    assert(((pair_t*) map.slots[5].head->data)[0].value == 15);

    assert(map.slots[5].head->next != NULL);
    assert(equals_str(((pair_t*) map.slots[5].head->next->data)[0].key, "12345"));
    assert(((pair_t*) map.slots[5].head->next->data)[0].value == 1);
    assert(map.slots[5].head->next->next == NULL);

    res = hashmap_add(&map, "21", 24);    // add existing key with different value
    assert(!res);
    assert(map.slots[2].head != NULL);
    assert(equals_str(((pair_t*) map.slots[2].head->data)[0].key, "12"));  // key was not updated
    assert(((pair_t*) map.slots[2].head->data)[0].value == 24); // value was updated
    assert(map.slots[2].head->next == NULL);


    assert(map.slots[0].head == NULL);
    assert(map.slots[1].head == NULL);
    assert(map.slots[3].head == NULL);
    assert(map.slots[4].head == NULL);

    hashmap_destroy(&map);

    fputs("test_hashmap_add PASSED\n", stderr);
}

void test_hashmap_lookup(void) {
    hashmap_t map;
    hashmap_init(&map, 6, (hash_fun_t) hash_strlen, (eq_fun_t) equals_str);

    map.hash_fun = (hash_fun_t) hash_strlen;
    map.equals_fun = (eq_fun_t) equals_str;

    pair_t pair1 = { .key = "12345", .value = 1 };
    pair_t pair2 = { .key = "12345012345", .value = 15 };
    pair_t pair3 = { .key = "12", .value = 42 };
    pair_t pair4 = { .key = "9", .value = 111 };

    map.slots[5].head = node_create(&pair2);
    map.slots[5].head->next = node_create(&pair1);
    map.slots[2].head = node_create(&pair3);
    map.slots[0].head = node_create(&pair4); // should be in slot 1, so won't be found
    map.count = 4;

    assert(hashmap_lookup(&map, "12345") == &pair1);
    assert(hashmap_lookup(&map, "12345012345") == &pair2);
    assert(hashmap_lookup(&map, "12") == &pair3);
    assert(hashmap_lookup(&map, "9") == NULL);
    assert(hashmap_lookup(&map, "54321") == &pair1);
    assert(hashmap_lookup(&map, "21") == &pair3);

    list_destroy(&map.slots[0]);
    list_destroy(&map.slots[2]);
    list_destroy(&map.slots[5]);
    map.slots[0].head = map.slots[2].head = map.slots[5].head = NULL;
    hashmap_destroy(&map);

    fputs("test_hashmap_lookup PASSED\n", stderr);
}


void test_hashmap_get(void) {
    hashmap_t map;
    hashmap_init(&map, 6, (hash_fun_t) hash_strlen, (eq_fun_t) equals_str);

    map.hash_fun = (hash_fun_t) hash_strlen;
    map.equals_fun = (eq_fun_t) equals_str;

    pair_t pair1 = { .key = "12345", .value = 1 };
    pair_t pair2 = { .key = "12345012345", .value = 15 };
    pair_t pair3 = { .key = "12", .value = 42 };
    pair_t pair4 = { .key = "9", .value = 111 };

    map.slots[5].head = node_create(&pair2);
    map.slots[5].head->next = node_create(&pair1);
    map.slots[2].head = node_create(&pair3);
    map.slots[0].head = node_create(&pair4); // should be in slot 1, so won't be found
    map.count = 4;

    assert(hashmap_get_value(&map, "12345") == 1);
    assert(hashmap_get_value(&map, "12345012345") == 15);
    assert(hashmap_get_value(&map, "12") == 42);
    assert(hashmap_get_value(&map, "9") == 0);
    assert(hashmap_get_value(&map, "54321") == 1);
    assert(hashmap_get_value(&map, "21") == 42);

    list_destroy(&map.slots[0]);
    list_destroy(&map.slots[2]);
    list_destroy(&map.slots[5]);
    map.slots[0].head = map.slots[2].head = map.slots[5].head = NULL;
    hashmap_destroy(&map);

    fputs("test_hashmap_get PASSED\n", stderr);
}

void test_hashmap_remove(void) {
    hashmap_t map;
    hashmap_init(&map, 6, (hash_fun_t) hash_strlen, (eq_fun_t) equals_str);

    pair_t *pair1 = create_pair("12345", 1);          // hash: 5, slot: 5
    pair_t *pair2 = create_pair("12345012345", 15);   // hash: 11, slot: 5
    pair_t *pair3 = create_pair("12", 42);            // hash: 2, slot: 2
    pair_t *pair4 = create_pair("9", 111);            // hash: 1, correct slot: 1

    map.slots[5].head = node_create(pair2);
    map.slots[5].head->next = node_create(pair1);
    map.slots[2].head = node_create(pair3);
    map.slots[0].head = node_create(pair4); // should be in slot 1, so won't be found
    map.count = 4;

    hashmap_remove(&map, "54321");
    assert(map.slots[5].head != NULL);
    assert(map.slots[5].head->data == pair2);
    assert(map.slots[5].head->next == NULL);
    assert(map.count == 3);

    hashmap_remove(&map, "12345012345");
    assert(map.slots[5].head == NULL);
    assert(map.count == 2);

    hashmap_remove(&map, "12");
    assert(map.slots[2].head == NULL);
    assert(map.count == 1);

    hashmap_remove(&map, "9");
    assert(map.slots[0].head != NULL);
    assert(map.slots[0].head->data == pair4);
    assert(map.slots[0].head->next == NULL);
    assert(map.count == 1);

    hashmap_destroy(&map);

    fputs("test_hashmap_remove PASSED\n", stderr);
}

void test_hashmap_rehash(void) {
    hashmap_t *map = hashmap_create(10, (hash_fun_t) hash_strlen, (eq_fun_t) equals_str);

    pair_t pair1 = { .key = "12345", .value = 1 };          // hash: 5  (cap 10: 5, cap 6: 5)
    pair_t pair2 = { .key = "12345012345", .value = 15 };   // hash: 11 (cap 10: 1, cap 6: 5)
    pair_t pair3 = { .key = "12", .value = 42 };            // hash: 2  (cap 10: 2, cap 6: 2)
    pair_t pair4 = { .key = "9", .value = 111 };            // hash: 1  (cap 10: 1, cap 6: 1)
    pair_t pair5 = { .key = "123456789", .value = 42 };     // hash: 9  (cap 10: 9, cap 6: 3)
    pair_t pair6 = { .key = "123456788", .value = 41 };     // hash: 9  (cap 10: 9, cap 6: 3)
    pair_t pair7 = { .key = "1234", .value = 4 };     // hash: 4  (cap 10: 4, cap 6: 4)

    map->slots[0].head = node_create(&pair4);   // NOTE: pair4 should be in slot 1, not in 0
    map->slots[1].head = node_create(&pair2);
    map->slots[2].head = node_create(&pair3);
    map->slots[4].head = node_create(&pair7);
    map->slots[5].head = node_create(&pair1);
    map->slots[9].head = node_create(&pair5);
    map->slots[9].head->next = node_create(&pair6);
    map->count = 7;

    hashmap_rehash(map, 6); // rehash to a capacity of 6
    assert(map->capacity == 6);
    assert(map->count == 7);

    assert(map->slots[0].head == NULL);

    assert(map->slots[1].head != NULL);
    assert(map->slots[1].head->data == &pair4);
    assert(map->slots[1].head->next == NULL);

    assert(map->slots[2].head != NULL);
    assert(map->slots[2].head->data == &pair3);
    assert(map->slots[2].head->next == NULL);

    assert(map->slots[3].head != NULL);
    assert(map->slots[3].head->next != NULL);
    assert(map->slots[3].head->next->next == NULL);
    assert(map->slots[3].head->data == &pair6 && map->slots[3].head->next->data == &pair5);

    assert(map->slots[4].head != NULL);
    assert(map->slots[4].head->data == &pair7);
    assert(map->slots[4].head->next == NULL);

    assert(map->slots[5].head != NULL);
    assert(map->slots[5].head->next != NULL);
    assert(map->slots[5].head->next->next == NULL);
    assert((map->slots[5].head->data == &pair1 && map->slots[5].head->next->data == &pair2) ||
           (map->slots[5].head->data == &pair2 && map->slots[5].head->next->data == &pair1));

    list_destroy(&map->slots[1]);
    list_destroy(&map->slots[2]);
    list_destroy(&map->slots[3]);
    list_destroy(&map->slots[4]);
    list_destroy(&map->slots[5]);
    map->slots[1].head = map->slots[2].head = map->slots[3].head = map->slots[5].head = NULL;
    hashmap_destroy(map);
    free(map);

    fputs("test_hashset_rehash PASSED\n", stderr);
}

void test_fnv1a(hash_fun_t fun) {
    assert(fun("") == 0xcbf29ce484222325);
    assert(fun("0") == 0xaf63ad4c86019caf);
    assert(fun("01") == 0x7fc1707b4bd207a);
    assert(fun("012") == 0x4e7b6a181d5dda58);
    assert(fun("0123") == 0xb98fb1f9e67a23d1);

    fputs("test_fnv1a PASSED\n", stderr);
}

void test_contract(hash_fun_t hashfun, eq_fun_t eqfun) {
    const char *s1 = "Hello", *s2 = "hello", *s3 = "World", *s4 = "world", *s5 = "";

    // same strings -> same hash, so we can't have the same strings but different hashes
    // different hash -> different strings, so we can't have different hashes but the same strings
    // -> either the hash is the same, or the strings are different
    assert(!eqfun(s1, s2) || hashfun(s1) == hashfun(s2));
    assert(!eqfun(s1, s3) || hashfun(s1) == hashfun(s3));
    assert(!eqfun(s1, s4) || hashfun(s1) == hashfun(s4));
    assert(!eqfun(s1, s5) || hashfun(s1) == hashfun(s5));

    assert(!eqfun(s2, s3) || hashfun(s2) == hashfun(s3));
    assert(!eqfun(s2, s4) || hashfun(s2) == hashfun(s4));
    assert(!eqfun(s2, s5) || hashfun(s2) == hashfun(s5));

    assert(!eqfun(s3, s4) || hashfun(s3) == hashfun(s4));
    assert(!eqfun(s3, s5) || hashfun(s3) == hashfun(s5));

    assert(!eqfun(s4, s5) || hashfun(s4) == hashfun(s5));

    fputs("test_contract PASSED\n", stderr);
}

void test_equality_fun(eq_fun_t fun) {
    assert(!fun("Hello", "World"));
    assert(fun("Hello", "Hello"));
    assert(fun("Hello", "hELLo"));
    assert(!fun("Hello!", "Hello"));
    assert(!fun("Hello", "Hello!"));
    assert(!fun("\tHello", " Hello"));
    assert(fun("H\ne\nl\nl\no", "H\ne\nl\nl\no"));
    assert(fun("42 __@#!", "42 __@#!"));
    assert(fun("Hello\0world", "Hello\0moon"));

    fputs("test_equality_fun PASSED\n", stderr);
}
