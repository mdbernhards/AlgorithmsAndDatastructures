#include <stdio.h>      // for printf, fopen, fgetc
#include <stdlib.h>     // for realloc & free
#include <assert.h>    

int * create_array(void)
{
    int array [10];
    return array;
}

void print_array(int values[], size_t size) 
{
    printf("[%d", values[0]);
    
    for (size_t i = 1; i < size; ++i) 
    {
        printf(", %d", values[i]);
    }

    printf("]\n");
}

int main(void) {
    int * values = create_array();

    for (int i = 0; i < 10; ++i) values[i] = i + 1;
    {
        print_array(values, 10);
    }
}