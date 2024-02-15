#include <stdio.h>      // for printf, fopen, fgetc
#include <stdlib.h>     // for realloc & free
#include <assert.h>     // for assert

int sum_ints(void) {
    int integers [1024] = {1};
    for (int i = 1; i < 1024; ++i) integers [i] = integers [i - 1] + 1;
    printf("Array \"integers\" has size %zu, and is stored in memory from %p to %p\n", sizeof(integers), (void*) &integers[0], (void*) &integers[1024]);

    return integers [1023];
}

double mul_doubles (int init) {
    double doubles [1024] = {init};
    for (int i = 1; i < 1024; ++i) doubles [i] = doubles [i - 1] * 0.999;
    printf("Array \"doubles\" has size %zu, and is stored in memory from %p to %p\n", sizeof(doubles), (void*) &doubles[0], (void*) &doubles[1024]);
    
    return doubles [1023];
}

int main(void) {
    double result = mul_doubles(sum_ints());
    printf("Result = %lf\n", result);
}
