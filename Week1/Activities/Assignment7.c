#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const int size = 1024 * 1024;
	for (int i = 0; i < size; ++i) {
		int * ptr = (int*) malloc(sizeof(int[size]));
		if (ptr != NULL) for (int j = 0; j < size; ++j) 
        {
            ptr[j] = j;
        }
		else 
        {
			printf("Failed to allocate %zu bytes of memory\n", sizeof(int[size]));
			break;
		}
        free(ptr);
    }
    puts("All done!");
}