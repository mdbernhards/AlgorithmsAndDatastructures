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

1.	
	function returns address of local variable [-Wreturn-local-addr]
2.	
	create_array returns the address of a local variable, so after it gets returned the variables lifetime ends.
3. 
	No because local variable gets destroyed after the function ends.

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

```c
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
```

### Activity 5: Allocating zero bytes

```c
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
```
1.	
	It returns a memory address
2.	
	It stores the value probably because it overwrites other values?
3. 
	No because I think it loops back around and tries to alocate a very large size, error message: argument 1 value '18446744073709551611' exceeds maximum object size 9223372036854775807 [-Walloc-size-larger-than=]

### Activity 6: Using allocated memory as an array

1.	
	Capacity is 24, int size is 4 so 24/4  is 6 int's
2.	
	It works okay???
3. 
	size_t should be capacity*sizeof(int) or 4 and in for loop it should start with int i = 0

```c
int * create_array(size_t capacity) {
	int *ptr = (int*) malloc(capacity*4);
	return ptr;
}

int main( void ) {
	const size_t capacity = 24;
	int * array = create_array(capacity);
	for (size_t i = 0; i <= capacity; i++) array[i] = 42;
	for (size_t i = 0; i <= capacity; i++) {
		printf("array[%zu] = %d\n", i, array[i]);
	}
}
```

### Activity 7: Fixing a memory leak

Added free(ptr) after the if else, because after that a new ptr gets created and the old one stops being used

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
		free(ptr);
	}
	puts("All done!");
}
```

### Activity 8: Dangerous `free`s

1. Using free() on a pointer that was not obtained using malloc. You get expetion: Segmentation fault
2. Using free() on a pointer, whose value is NULL. Works okay, because it doesn't point to anything?

### Activity 9: Using realloc

Out of 10000 times it relocates the address 99.89% of the time.

```c
int main( void ) {
	float *grades = NULL;
	size_t capacity = 1024;
	for (int count = 0; count < 10000; capacity += 1024, ++count) {
		float *new_grades = (float*)realloc(grades, sizeof(float[capacity]));
		if (new_grades != NULL){
            if (grades == new_grades)
            {
                newMemoryAdressCount++;
            }

			grades = new_grades;
		}
	}
    printf("New adress count: %d\n", newMemoryAdressCount);
}
```

### Activity 10: Using a dynamically sized buffer



```c
#include <stdio.h>      // for printf, fopen, fgetc
#include <stdlib.h>     // for realloc & free
#include <assert.h>     // for assert

/*
 * Reads the file "E.coli.txt" into a dynamically allocated array
 */
int main( void ) {
    char *ptr = NULL; // the memory address of the array
    size_t capacity = 20; // the capacity of the array
    size_t count = 0; // the number of actual values stored in the array
    int multiplier = 1;

    ptr = realloc(ptr, sizeof(char[capacity])); // allocate memory
    if (ptr == NULL){ // check if allocation worked
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // open the file "E.coli.txt" for reading in text mode
    FILE *file = fopen("E.coli.txt", "r");

    if (file == NULL) { // check if file was opened
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int c = fgetc(file); // read next character from file
    while (c != EOF) {

        if (count >= capacity)
        {
            ptr = realloc(ptr, sizeof(char[capacity * multiplier++]));
        }

        ptr[count++] = (char) c; // store current character, then increase count
        c = fgetc(file); // read next character from file
    }

    // count how many 'a's are in the file
    int freq = 0;
    for (size_t i = 0; i < count; ++i) if (ptr[i] == 'a') freq++;

    printf("Character 'a' appears %d times in the array - this should be 1142069\n", freq);

    // let the program crash if the frequency is not correct
    assert(freq == 1142069);

    free(ptr); // release the memory
}
```

## Looking back

### What we've learnt

We learned how lifetime works for objects, how dinamically allocated memory works

### What were the surprises

How much text there was

### What problems we've encountered

Understanding the large amount of text

### What was or still is unclear

I'm not sure

