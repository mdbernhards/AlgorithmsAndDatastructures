#include <stdio.h>
#include <stdlib.h>

int * create_array(size_t capacity) {
	int *ptr = (int*) malloc(capacity);

	return ptr;
}

int main( void ) {
	const size_t capacity = 24;
    int a = 10;

    printf("%d\n",capacity);
    printf("%d\n",sizeof(a));

    int *array = create_array(capacity);
    a = array[100];

    printf("%d\n",a);

    array[500] = 100;

    printf("%d\n",array[500]);

    for (size_t i = 1; i <= capacity; i++)
    {
        array[i] = 42;
    }
    
    for (size_t i = 1; i <= capacity; i++) 
    {
		printf("array[%zu] = %d\n", i, array[i]);
	}
}