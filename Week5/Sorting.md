
# Week 5 - Sorting

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 25 03 2024

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

Download the provided project and open it in CLion.

### Activity 1: Benefits of sorted data

Sorted array time complexity - O(log n)
Unsorted array time complexity - O(n)
To effectively search a sorted array you use - Binary search

### Activity 2: Find the smallest element

```c
int *find_min(int *values, size_t count) 
{
    int* min = values;

    if (count <= 0)
    {
        return NULL;
    }

    for (size_t i = 0; i < count; i++)
    {
        if (*min > values[i])
        {
            min = &values[i];
        }
    }
    
    return min;
}
```

### Activity 3: Implement selection sort

```c
void array_sort(array_t *array) 
{
    if (array->count <= 0)
    {
        return;
    }

    for (size_t i = 0; i < array->count; i++)
    {
        swap(&array->data[i], find_min(&array->data[i], array->count - i));
    }
}
```
### Activity 4: Selection sort: comparisons

| Array size | Comparisons |
|------------|-------------|
| 5          | 10          |
| 10         | 45          |
| 15         | 105         |
| 20         | 190         |
| 50         | 1225        |
| 100        | 4950        |
| 150        | 11175       |
| 250        | 31125       |
| 500        | 124750      |
| 1000       | 499500      |
| 5000       | 12497500    |
| 10000      | 49995000    |
### Activity 5: Merge sort - step by step
Stage Subsequences
13 lists: [9], [0], [31], [5], [2], [8], [15], [13], [6], [4], [7], [11], [19]
7 lists: [0, 9], [5, 31], [2, 8], [13, 15], [4, 6], [7, 11], [19]
4 lists: [0, 5, 9, 31], [2, 8, 13, 15], [4, 6, 7, 11], [19]
2 lists: [0, 2, 5, 8, 9, 13, 15, 31], [4, 6, 7, 11, 19]
1 list: [0, 2, 4, 5, 6, 7, 8, 9, 11, 13, 15, 19, 31]


### Activity 6: Splitting a linked list in two halves

```c
node_t *split(node_t *phead) 
{
    node_t *fast = phead->next;

    while (fast != NULL && fast->next != NULL) 
    {
        fast = fast->next;
        fast = fast->next;
        phead = phead->next;
    }

    node_t *secondHalfStart = phead->next;
    phead->next = NULL;

    return secondHalfStart;
}
```

### Activity 7: Merging two linked lists

```c
node_t *merge(node_t *a, node_t *b) 
{
    node_t sentinel = {.next = NULL};
    node_t *result = &sentinel;

    while (a != NULL && b != NULL) 
    {
        g_compares++;

        if (a->value < b->value) 
        {
            result->next = a;
            a = a->next;
        } 
        else 
        {
            result->next = b;
            b = b->next;
        }

        result = result->next;
    }
    
    if (a == NULL)
    {
        result->next = b;
    }
    else
    {
        result->next = a;
    }

    return sentinel.next;
}
```

### Activity 8: Implement merge sort

```c
node_t *merge_sort(node_t *first) 
{
    if (first->next == NULL)
    {
        return first;
    }

    node_t * next = split(first);

    first = merge_sort(first);
    next = merge_sort(next);

    first = merge(first, next);

    return first;
}
```

### Activity 9: Merge sort: impact of order

Using Merge sort sorting 12345 takes more steps than merging 54321, because each time when it is comparing and the node with the smallest value has a pointer to the next one it also needs to compare with it. Also with the first split() they are  split in to first 3 numbers and the last two and in 12345 the first three are the smallest ones, so more comparisons are needed.

### Activity 10: Merge sort: determining efficiency

| List length | Comparisons |
|-------------|-------------|
| 5           | 5 - 7       |
| 10          | 15 - 19     |
| 15          |   31        |
| 20          |   48        |
| 50          |   153       |
| 100         |   356       |
| 250         |   1011      |
| 500         |   2272      |
| 1000        |   5044      |
| 5000        |   32004     |
| 10000       |   853904    |

### Activity 11: Compare merge sort and selection sort

|    Algorithm    |   Time complexity   |
| ------------------------------------- |
| Merge sort      |    O(a+ x*log(x))   |
| Selection sort  |    O(a(x-b)^2 +c)   |

## Looking back

### What we've learnt

Learned how to implement merge sort and how effective / ineffective different sorting algorithms are.

### What were the surprises

Activity 9

### What problems we've encountered

Activity 9

### What was or still is unclear

I'm not sure

### How did the group perform?

Good
