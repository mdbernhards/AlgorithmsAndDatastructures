#include <stdio.h>      // for printf, fopen, fgetc
#include <stdlib.h>     // for realloc & free
#include <assert.h>    

typedef struct array {
    size_t capacity;
    size_t count;
    float *data;
} array_t;

int main(void) {
 array_t my_array; // declare local variable
 my_array.data = NULL;
 my_array.capacity = 0;
 my_array.count = 0;
}
 
array_t* array_init(array_t *p_array, size_t capacity) { // version 2
    if (p_array != NULL) {
        p_array->data = malloc(sizeof(float[capacity]));
        p_array->count = 0;
        p_array->capacity = p_array->data != NULL ? capacity : 0;
    }

    return p_array;
 }