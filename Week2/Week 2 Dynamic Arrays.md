﻿# Week 2 - Dynamic Arrays

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 06.03.2023

### Activity 1: Random access

 Original code last output: f(49) = 7778742049
 New code last output: f(49) = 7778742049

Rewrite the code by replacing **all** expressions in which pointers are dereferenced with equivalent ones that use the *array index operator* ("[..]").

````c
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
````

### Activity 2: Array definition

Explain what each of the three fields of the `array_t` structure listed below is used for.

Find out, for your system, what the maximum number of elements is that can be stored in the array.

1. size_t capacity; - How many elements possible
2. size_t count; - How many elements inside
3. float *data; - Pointer To the first element

Maximum Capacity is 33624024


```C
typedef struct array {
    size_t capacity;
    size_t count;
    float *data;
} array_t;
```

### Activity 3: Correct initialization

Record your answer here.

```C
array_t* array_init(array_t *p_array, size_t capacity) { // version 2
    if (p_array != NULL) {
        p_array->data = malloc(sizeof(float[capacity]));
        p_array->count = 0;
        p_array->capacity = p_array->data != NULL ? capacity : 0;
    }

    return p_array;
 }
```
first one is not correct,because it creates stack array, not dynamic.


### Activity 4: Cleaning up

The correct program is the second one, because freeing the memory is only required for dynamic arrays, those who use malloc.
Also the first program throws an exception.

```c
int main(void) {
    // program 2
    array_t *array2 = (array_t *) malloc(sizeof(array_t));
    array_init(array2, 10);
    // .... do some work ...
    // finally, clean up
    array_destroy(array2);
    free(array2);
}
```

### Activity 5: Resizing an array
A typical "growth rate" of a "dynamic array" is 1.5, this is what we will pick.

```c
void array_reserve(array_t *p_array, size_t min_capacity) {
    size_t capacity = p_array->capacity;
    while (capacity < min_capacity) {
        capacity = (capacity + 1) * 1, 5;
    }

    if (capacity != p_array->capacity) {
        p_array->data = malloc(sizeof(float[capacity]));
        p_array->capacity = capacity;
	}
}
```

### Activity 6: Appending values

Record your function definition here.

```c
void array_append(array_t *arr, float value){
    arr->capacity++;
    arr->data = realloc(arr->data, sizeof(float[arr->capacity]));
    arr->data[arr->count++] = value;
}
```
Passed the test


### Activity 7: Inserting values

Record your function definition here.

```c
void array_insert(array_t* arr, size_t index, float value) {
    arr->capacity++;
    arr->data = realloc(arr->data, sizeof(float[arr->capacity]));
	for (int k = arr->count; k > index; k--){        
    	arr->data[k] = arr->data[k-1];
	}
	arr->data[index] = value;
	arr->count++;
}
```

Passed the test.

### Activity 8: Removing by index

Record your function definition here.

```c
void array_remove(array_t * arr, size_t index) {
	for (int i = index; i < arr->count - 1; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	
	arr->count--;
}
```
Passed the test.

### Activity 9: Constant time complexity

 a constant time complexity meaning : However much data you give it it finishes in the same amount of time always.
 It is writen: O(1)

### Activity 10: Worst-case time complexity

| Operation       | ----------------------- Worst-case time complexity ---------------------------------- | Big O Notation |
| --------------- | ------------------------------------------------------------------------------------- | -------------- |
| Insert          | If you insert at 0 position, because you need to move all elements by one position    |      O(n)      |
| Remove          | If you delete the first value, because again you need to move all of the elements.    |      O(n)      |
| Lookup / access | time complexity always the same? Looks for the element at any index at the same speed |      O(1)      |

### Activity 11: Complexity of *append*

Worst-case time complexity of the append operation: O(n)
Average case (or amortized) time complexity of the append operation: O(1)
append operation, how is it different from the worst-case time complexity, and why?

Because usually you just add a single element at the end, so it always on average takes the same time. 
But worst case when you need to move each element it takes O(n). 

### Activity 12: Storing grades in a dynamically growing array

```c

// keep asking the user to enter a grade, stop when user enters 0
void input_grades(array_t * grades) {
    while(1) {
        printf("Please enter a grade:");
        float num;

        scanf("%f", &num);  

        if (num == 0)
        {
            break;
        }
        
        array_append(grades, num);
    }
}

// computes and returns the average grade
float compute_average(const array_t * grades) {
    float summ = 0;
    for (int i = 0; i < grades->count ; ++i) {
        summ += grades->data[i];
    }

    return summ/grades->count;
}

// counts and returns the number of grades that are at least the ←
//threshold
int num_passed(const array_t * grades, float threshold) {
    int passed = 0;
    for (int i = 0; i < grades->count; ++i) {
        if (grades->data[i] >= threshold){
            passed++;
        }
    }

    return passed;
}

int main() {
    array_t grades;
    array_init(&grades, 0);
    input_grades(&grades);
    float average = compute_average(&grades);
    int passed = num_passed(&grades, 5.5f);
    printf("Average grade: %.2f\n", average);
    printf("%d out of %zu students passed\n", passed, grades.count);
    array_destroy(&grades);
    return 0;
}
```


## Looking back

### What we've learnt

Formulate at least one lesson learned.

### What were the surprises

Fill in...

### What problems we've encountered

Fill in...

### What was or still is unclear

Fill in...

### How did the group perform?

How was the collaboration? What were the reasons for hick-ups? What worked well? What can be improved next time?





> Written with [StackEdit](https://stackedit.io/).
