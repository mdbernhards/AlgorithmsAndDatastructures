#include <stdlib.h>  

typedef struct array {
    size_t capacity;
    size_t count;
    float *data;
} array_t;

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

int main(void) {
    // program 1
    array_t array;
    array_init(&array, 10);
    // .... do some work ...
    // finally, clean up
    array_destroy(&array);
    free(&array);

    // program 2
    array_t *array2 = (array_t *) malloc(sizeof(array_t));
    array_init(array2, 10);
    // .... do some work ...
    // finally, clean up
    array_destroy(array2);
    free(array2);
}