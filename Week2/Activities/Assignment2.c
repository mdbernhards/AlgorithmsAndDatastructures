#include <stdio.h>      // for printf, fopen, fgetc
#include <stdlib.h>     // for realloc & free
#include <assert.h>     // for assert

typedef struct array {
    size_t capacity;
    size_t count;
    float *data;
} array_t;

int main(void) {

    array_t a;
    a.capacity = sizeof(a);
    a.data = NULL;
    a.data = realloc(a.data, sizeof(float[a.capacity]));
    a.count = 0;
    
    while(1)
    {
        a.data[a.count++] = 5;
        a.capacity += 100;
        if (a.capacity <= a.count)
        {
            a.capacity = a.capacity * 2;
            a.data = realloc(a.data, sizeof(float[a.capacity]));
        }
        printf("%d\n",a.capacity);
    }
}
