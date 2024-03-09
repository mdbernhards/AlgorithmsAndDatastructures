#include <stdlib.h>  

int* allocate_memory(int count)
{
    return (int*) malloc(sizeof(int[count]));
}

int main(void) {
    unsigned long *a;
    float *b, *c;

    a = (unsigned long*) malloc(sizeof(unsigned long));
    b = (float*) malloc(256 * sizeof(float));
    c = (float*) malloc(sizeof(float[256]));
}