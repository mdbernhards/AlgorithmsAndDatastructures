#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a, *b, *c, num;

    num = 22;

    a = (int*) malloc(0);
    b = (int*) malloc(sizeof(int));
    c = (int*) malloc(-5);
    
    printf("%d\n", *a);
    printf("%d\n", *b);

    a = &num;

    printf("%d\n", *a);
}