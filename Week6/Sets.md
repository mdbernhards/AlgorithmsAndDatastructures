# Week 6 - Sets

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 02-04-2024                                                   |      |

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

Download the provided project and open it in CLion.

### Activity 1: Comparing floating point numbers

```c
bool equals_dbl(double a, double b)
{
    return fabs(a-b) < __FLT_EPSILON__;
}
```

### Activity 2: Function pointers

```c
int print_subtraction(int a, int b) 
{
    return a - b;
}

int print_division_remainder(int a, int b) 
{
    return a % b;
}

void fun_with_ints(int (*funptr)(int, int)) 
{
    for (int r = 1; r <= 15; ++r) 
    {
        for (int c = 1; c <= 15; ++c) 
        {
            int result = funptr(r, c);
            printf(" %5d", result);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(void) 
{
    int (*fun_ptr)(int, int) = print_subtraction;
    fun_with_ints(fun_ptr);

    fun_ptr = print_division_remainder;
    fun_with_ints(fun_ptr);

    return 0;
}
```

### Activity 3: Function implementations

```c
/// Adds a value to a set, if it is not already present
/// @param set The set to add the value to
/// @param value The value to add to the set
void set_add(set_t * set, double value) 
{
    if (!ensure_capacity(set) || set_contains(set, value)) 
    {
        return;
    }

    set->data[set->count++] = value;
}

/// Removes a value from a set, if it is present
/// @param set The set to remove the value from
/// @param value The value to remove from the set
void set_remove(set_t * set, double value) 
{
    bool valueFound = false;

    for (size_t i = 0; i < set->count; i++)
    {
        if (set->eq_fun(set->data[i], value) && !valueFound)
        {
            valueFound = true;
            set->data[i] = set->data[i + 1];
            set->count--;
        }
        else if (valueFound)
        {
            set->data[i] = set->data[i + 1];
        }
    }
}

/// Checks if a value is in the set
/// @param set The set to search
/// @param value The value to search for in the set
/// @return true if the value is present, false if it is not
bool set_contains(const set_t * set, double value) 
{
    for (size_t i = 0; i < set->count; i++)
    {
        if (set->eq_fun(set->data[i], value))
        {
            return true;
        }
    }
    
    return false;
}
```

### Activity 4: Time complexity of unsorted set operations

| Operation | Time complexity |
|-----------| --------------- |
| Contains  |        O(n)     |
| Add       |        O(n)     |
| Remove    |        O(n)     |

### Activity 5: Binary search

Value to find: 46:
1, 5, 8, 9, 14, 15, 16, 18, 27, 35, 36, 43, 44, 46, 59, 64

| Binary search step | lo  | hi  | mid |
|--------------------|-----|-----|-----|
| 1                  | 0   | 16  |  8  |
| 2                  | 9   | 16  | 13  |
| 3                  |     |     |     |
| 4                  |     |     |     |
| 5                  |     |     |     |

Value to find: 4:

| Binary search step | lo  | hi  | mid |
|--------------------|-----|-----|-----|
| 1                  | 0   | 16  |  8  |
| 2                  | 0   |  8  |  4  |
| 3                  | 0   |  4  |  2  |
| 4                  | 0   |  2  |  1  |
| 5                  | 0   |  1  |  ?  |

### Activity 6: Ordering doubles

```c
int cmp_dbl(double d1, double d2)
{
    if ((d1-d2) < (__FLT_EPSILON__ * -1))
    {
        return -1;
    }
    else if ((d1-d2) > __FLT_EPSILON__)
    {
        return 1;
    }

    return 0;
}
```

### Activity 7: Implementing binary search

```c
size_t set_index_of(const set_t * set, double value) {
    size_t lo = 0, hi = set->count;

    while (lo != hi)
    {
        int mid = (hi + lo) / 2;

        if (set->cmp_fun(set->data[mid], value) == 0)
        {
            return mid;
        }
        else if (set->cmp_fun(set->data[mid], value) == -1)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    return hi;
}
```

Record your answer here

### Activity 8: Binary search - Time complexity

| Array size | Lookups |
|------------|---------|
| 16         |  5 (4?) |
| 32         |  5      |
| 64         |  6      |
| 128        |  7      |
| 256        |  8      |
| 1000       | 10      |
| 4000       | 12      |
| 10000      | 13      |
| 1048576    | 20      |

Record your answer here


### Activity 9: Finalizing the sorted array

```c
/// Adds a value to a set, if it is not already present
/// @param set The set to add the value to
/// @param value The value to add to the set
void set_add(set_t * set, double value) 
{
    if (!ensure_capacity(set)) 
    {
        return;
    }

    size_t insertIndex = set_index_of(set, value), temp1, temp2;

    if (set->cmp_fun(set->data[insertIndex], value) == 0) 
    {
        return;
    }

    temp2 = set->data[insertIndex];
    set->data[insertIndex] = value;

    for (size_t i = insertIndex; i < set->count ; i++)
    {
        temp1 = temp2;
        temp2 = set->data[i + 1];
        set->data[i + 1] = temp1;
    }

    set->data[insertIndex] = value;
    set->count++;
}

/// Removes a value from a set, if it is present
/// @param set The set to remove the value from
/// @param value The value to remove from the set
void set_remove(set_t * set, double value) 
{
    size_t removeIndex = set_index_of(set, value);

    if (set->cmp_fun(set->data[removeIndex], value) != 0)
    {
        return;
    }

    for (size_t i = removeIndex; i < set->count; i++)
    {
        set->data[i] = set->data[i + 1];
    }

    memcpy(&set->data[removeIndex], &set->data[removeIndex + 1], set->count - removeIndex );

    set->count--;
}

/// Checks if a value is in the set
/// @param set The set to search
/// @param value The value to search for in the set
/// @return true if the value is present, false if it is not
bool set_contains(const set_t * set, double value) 
{
    size_t containsIndex = set_index_of(set, value);

    if (set->cmp_fun(set->data[containsIndex], value) == 0)
    {
        return true;
    }

    return false;
}
```

Record your answer here

### Activity 10: Time complexity of the sorted set

| Operation | Time complexity |
|-----------| --------------- |
| Add       | O(log(n) + n)   |
| Remove    | O(log(n) + n    |
| Contains  | O(log(n))       |

Record your answer here

## Looking back

### What we've learnt

How to create a sorted array

### What were the surprises

How efficent binary search is compared to linear search

### What problems we've encountered

Not sure how to get the time complexity for activity 10

### What was or still is unclear

Time complexity

### How did the group perform?

Good
