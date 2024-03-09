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
	arr->capacity;
}

void array_remove(array_t * arr, size_t index){
	for (int i = index; i < arr->count - 1; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	
	arr->count--;
}

void test_array_remove(void) {
    array_t array;
    array_init(&array, 5);	// initialize array with capacity of 5
    // set contents to {0.0f, 1.0f, 2.0f, 3.0f, 4.0f}
    for (int i = 0; i < 5; ++i) array_append(&array, 1.0f * i);

    array_remove(&array, 4);	// remove last element
    assert(array.count == 4);	// count must now be three
    assert(array.data[0] == 0.0f);
    assert(array.data[1] == 1.0f);
    assert(array.data[2] == 2.0f);
    assert(array.data[3] == 3.0f);

    array_remove(&array, 0);	// remove first element
    assert(array.count == 3);	// count must now be three
    assert(array.data[0] == 1.0f);	// elements have shifted to indices 0..2
    assert(array.data[1] == 2.0f);
    assert(array.data[2] == 3.0f);

    array_remove(&array, 1);	// remove second element
    assert(array.count == 2);	// count must now be two
    assert(array.data[0] == 1.0f);
    assert(array.data[1] == 3.0f);
    array_destroy(&array);
    fputs("test_array_remove PASSED\n", stderr);
}

int main( void ) {
	test_array_remove();
}