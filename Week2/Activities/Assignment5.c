#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    size_t capacity;
    size_t count;
    float *data;
} array_t;

void array_reserve(array_t *p_array, size_t min_capacity) {
    size_t capacity = p_array->capacity;
    while (capacity < min_capacity) {
        capacity = (capacity + 1) * 1, 5;
    }

    if (capacity != p_array->capacity) {
        p_array->data = malloc(sizeof(float[capacity]));
        p_array->capacity = capacity;
	}
}

int main(void) {
}