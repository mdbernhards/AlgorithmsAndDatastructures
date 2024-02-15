# Week 1 - Memory

## Team

Date:

Members:
- Mārtiņš Dāvis Bernhards	
- Damīrs Zaļums

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

Set up a project in CLion to write the small programs needed in some of the activities.

### Before you start

In your projects, make sure that the `CMakeLists.txt` file contains the following line, so that potential problems appear in the "Messages" tab:

> ```text
> target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
> ```

Make sure to check the messages after building.

### Activity 1: Printing memory addresses - I

Give the range of memory addresses occupied by the two arrays, `integers` and `doubles`, in the code listed below.
Explain why these ranges do or do not overlap.

1. 
	`integers` size is 4096, and is stored in memory from 00000000005FEE00 to 00000000005FFE00
	`doubles` size is 8192, and is stored in memory from 00000000005FDE00 to 00000000005FFE00
2.	
	Yes, memory ranges overlap, because when one array in a function lifetime ends, other array takes pervious array memory adress.
3.	
	No, they do not overlap. Because 1st functions returns an number in array and lifetime ends,second array accepts it makes some calculations and also end lifetime. So they do not overlap
4. 
	8192 bytes


They overlap because same memory location can be used to store values of different objects, as long as these objects do not need to be accessed at the same time.

```C
#include <stdio.h>

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
```

### Activity 2: Printing memory addresses - II

1. 
	`integers` size is 4096, and is stored in memory from 00000000005FCDB0 to 00000000005FDDB0
	`doubles` size is 8192, and is stored in memory from 00000000005FDE00 to 00000000005FFE00
2.	
	No, memory ranges do not overlap, because when one array in a function kills, other array takes pervious array memory adress.
3.	
	Yes, they do overlap. Because 1st functions returns an number in array and kills it,second array accepts it makes some calculations and also kills. So they do not overlap
4. 
	12288 bytes

```C
#include <stdio.h>

int sum_ints(void) {
	int integers[1024] = {1};
	for (int i = 1; i < 1024; ++i) integers[i] = integers[i - 1] + 1;
	return integers[1023];
}

double mul_doubles(void) {
	double doubles[1024] = {sum_ints()};
	for (int i = 1; i < 1024; ++i) doubles[i] = doubles[i - 1] * 0.999;
	return doubles[1023];
}

int main(void) {
	double result = mul_doubles();
	printf("Result = %lf\n", result);
}
```

### Activity 3: Using data that is no longer alive

Record the answer to the activity's questions here.

```c
#include <stdio.h>

int * create_array(void) {
	int array[10];
	return array;
}

void print_array(int values[], size_t size) {
	printf("[%d", values[0]);
	for (size_t i = 1; i < size; ++i) printf(", %d", values[i]);
	printf("]\n");
}

int main(void) {
	int * values = create_array();
	for (int i = 0; i < 10; ++i) values[i] = i + 1;
	print_array(values, 10);
}
```

### Activity 4: Using malloc

Record the answer to the activity's questions here.

### Activity 5: Allocating zero bytes

Record the answer to the activity's questions here.

### Activity 6: Using allocated memory as an array

Record the answer to the activity's questions here.

```c
int * create_array(size_t capacity) {
	int *ptr = (int*) malloc(capacity);
	return ptr;
}

int main( void ) {
	const size_t capacity = 24;
	int * array = create_array(capacity);
	for (size_t i = 1; i <= capacity; i++) array[i] = 42;
	for (size_t i = 1; i <= capacity; i++) {
		printf("array[%zu] = %d\n", i, array[i]);
	}
}
```

### Activity 7: Fixing a memory leak

Record the answer to the activity's questions here.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const int size = 1024 * 1024;
	for (int i = 0; i < size; ++i) {
		int * ptr = (int*) malloc(sizeof(int[size]));
		if (ptr != NULL) for (int j = 0; j < size; ++j) ptr[j] = j;
		else {
			printf("Failed to allocate %zu bytes of memory\n", sizeof(int[size]));
			break;
		}
	}
	puts("All done!");
}
```

### Activity 8: Dangerous `free`s

Record the answer to the activity's questions here.

### Activity 9: Using realloc

Record the answer to the activity's questions here.

```c
int main( void ) {
	float *grades = NULL;
	size_t capacity = 1024;
	for (int count = 0; count < 10000; capacity += 1024, ++count) {
		float *new_grades = (float*)realloc(grades, sizeof(float[capacity]));
		if (new_grades != NULL){
			// TODO: count how often the memory is reallocated to another memory address
			//       by comparing the memory addresses of the block before and after the reallocation
			grades = new_grades;	// make the new block the current block
		}
	}
}
```

### Activity 10: Using a dynamically sized buffer

Download the project for this activity from Blackboard.

Include your code & notes here.

## Looking back

### What we've learnt

Formulate at least one lesson learned.

### What were the surprises

Fill in...

### What problems we've encountered

Fill in...

### What was or still is unclear

Fill in...


