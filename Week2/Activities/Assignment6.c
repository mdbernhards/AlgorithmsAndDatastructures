#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

array_t *array_init(array_t *pArray, size_t capacity) {
    if (pArray != NULL) {
        pArray->data = malloc(sizeof(float[capacity]));
        pArray->count = 0;
        pArray->capacity = pArray->data != NULL ? capacity : 0;
    }

    return pArray;
}

array_t* array_create(size_t capacity) {
    return array_init((array_t *) malloc(sizeof(array_t)), capacity);
}

void array_destroy(array_t *pArray) {
    if (pArray != NULL) {
        free(pArray->data);
        pArray->data = NULL;
        pArray->count = pArray->capacity = 0;
    }
}

void array_append(array_t *arr, float value){
    arr->capacity++;
    arr->data = realloc(arr->data, sizeof(float[arr->capacity]));
    arr->data[arr->count++] = value;
}


void test_array_append(void) {
    array_t array;
    array_init(&array, 0);	// initialize array with capacity of 0
    array_append(&array, 1.0f);	// append an element
    assert(array.count == 1);	// count must now be one
    assert(array.capacity >= array.count);	// capacity must be sufficient
    assert(array.data[0] == 1.0f);	// element was stored at index 0

    array_append(&array, 2.0f);	// append another element
    assert(array.count == 2);	// count must now be two
    assert(array.capacity >= array.count);	// capacity must be sufficient
    assert(array.data[0] == 1.0f);	// first element has not changed
    assert(array.data[1] == 2.0f);	// new element was stored at index 1
    array_destroy(&array);
    fputs("test_array_append PASSED\n", stderr);
}

int main( void ) {
     array_t* array = array_create(10);
     array_append(array, 10);
     array_append(array, 8);
     array_append(array, 4);
     array_append(array, 3);
     test_array_append();
}