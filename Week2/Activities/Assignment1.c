#include <stdio.h>
#define COUNT (50)

void fill_fibonacci(unsigned long long * storage, int count) {
	storage[0] = 0;
	storage[1] = 1;
	for (int i = 2; i < count; i++) {
		storage[i] = storage[i-1] + storage[i-2];
	}
}

int main(void) {
	unsigned long long array[COUNT];
	fill_fibonacci(array, COUNT);
	for (int i = 1; i < COUNT; i++) {
		printf("f(%d) = %llu\n", i, array[i]);
	}
}