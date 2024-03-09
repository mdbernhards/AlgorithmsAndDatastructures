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

void array_insert(array_t* arr, size_t index, float value) {
    arr->capacity++;
    arr->data = realloc(arr->data, sizeof(float[arr->capacity]));
	for (int k = arr->count; k > index; k--){        
    	arr->data[k] = arr->data[k-1];
	}
	arr->data[index] = value;
	arr->count++;
}

void test_array_insert(void) {
    array_t array;
    array_init(&array, 0);	// initialize array with capacity of 0
    array_insert(&array, 0, 1.0f);	// insert an element at the end
    assert(array.count == 1);	// count must now be one
    assert(array.capacity >= array.count);	// capacity must be sufficient
    assert(array.data[0] == 1.0f);	// element was stored at index 0

    array_insert(&array, 0, 2.0f);	// insert in front of array
    assert(array.count == 2);	// count must now be two
    assert(array.capacity >= array.count);	// capacity must be sufficient
    assert(array.data[0] == 2.0f);	// inserted element is at index 0
    assert(array.data[1] == 1.0f);	// previously inserted element is now at index 1

    array_insert(&array, 1, 3.0f);	// insert at index 1
    assert(array.count == 3);	// count must now be three
    assert(array.capacity >= array.count);	// capacity must be sufficient
    assert(array.data[0] == 2.0f);	// element at index 0 has not changed
    assert(array.data[1] == 3.0f);	// inserted element is at index 1
    assert(array.data[2] == 1.0f);	// value 1.0 has shifted to index 2

    array_insert(&array, 0, 4.0f);	// insert at index 0
    assert(array.count == 4);	// count must now be four
    assert(array.capacity >= array.count);	// capacity must be sufficient
    assert(array.data[0] == 4.0f);	// inserted element is at index 0
    assert(array.data[1] == 2.0f);	// 2.0f has shifted to index 1
    assert(array.data[2] == 3.0f);	// 3.0f has shifted to index 2
    assert(array.data[3] == 1.0f);	// 1.0f has shifted to index 3
    array_destroy(&array);
    fputs("test_array_insert PASSED\n", stderr);
}

int main( void ) {
	test_array_insert();
}