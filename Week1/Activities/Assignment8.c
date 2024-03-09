#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int stack_variable = 42;
	int* ptr = &stack_variable;
	free(ptr); // 1. free a variable that has automatic lifetime

	int* null_ptr = NULL;
	free(null_ptr); // 2. calling free on a pointer that is NULL
}