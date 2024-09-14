#include <string.h>
#include "pair.h"
#include <stdlib.h>
#include <ctype.h>

pair_t *create_pair(const char *key, size_t value) {
    pair_t *pair = malloc(sizeof(pair_t));
    if (pair == NULL) return NULL;  // out of memory
    char *key_copy = (char*) malloc(strlen(key) + 1);
    if (key_copy == NULL) {
        free(pair);
        return NULL;  // out of memory
    }
    strcpy(key_copy, key);
    for (char *ptr = key_copy; *ptr != '\0'; ++ptr) *ptr = tolower(*ptr);
    key_copy[0] = toupper(key_copy[0]);
    pair->key = key_copy;
    pair->value = value;
    return pair;
}

void destroy_pair(pair_t *pair) {
    free((void*) pair->key);
    free(pair);
}

