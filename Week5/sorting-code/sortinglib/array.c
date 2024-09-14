#include "array.h"
#include <stdlib.h>
#include <stdio.h>

void array_init(array_t *array, size_t cap) {
    array->data = (int*) malloc(sizeof(int) * cap);
    array->capacity = array->data == NULL ? 0 : cap;
    array->count = 0;
}

void array_destroy(array_t *array) {
    free(array->data);
    array->data = NULL;
}

bool array_ensure_capacity(array_t * array, size_t min_cap) {
    if (!array) return false;
    size_t cap = array->capacity;
    while (cap < min_cap) cap = (cap + 1) * 3 / 2;
    if (cap != array->capacity) {
        int *ptr = (int *) realloc(array->data, sizeof(int[cap]));
        if (!ptr) return false;
        array->data = ptr;
        array->capacity = cap;
    }
    return true;
}

void array_append(array_t * array, int value) {
    array_ensure_capacity(array, array->count + 1);
    array->data[array->count++] = value;
}

void array_fill(array_t *array, int * values, size_t count) {
    if (count > array->capacity) {
        int * ptr = (int*) realloc(array->data, count * sizeof(int));
        if (ptr != NULL) {
            array->data = ptr;
            array->capacity = count;
        }
    }

    if (count > array->capacity) count = array->capacity;
    for (size_t i = 0; i < count; i++) {
        array->data[i] = values[i];
    }
    array->count = count;
}

void array_print(const array_t *array) {
    printf("[");
    if (array->count > 0) {
        printf("%d", array->data[0]);
        for (size_t i = 1; i < array->count; i++) printf(", %d", array->data[i]);
    }
    printf("]");
}

bool array_is_sorted(const array_t *array) {
    for (size_t i = 1; i < array->count; ++i) {
        if (array->data[i] < array->data[i - 1]) return false;
    }
    return true;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
