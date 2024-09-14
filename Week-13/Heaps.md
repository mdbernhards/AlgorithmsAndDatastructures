# Week 13 - Heaps

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 05 06 2024

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

### Activity 1: Comparing different data structures

| Data structure     | Find-max | Delete-Max | Insert |
|--------------------|:--------:|:----------:|:------:|
| Sorted array       |   O(1)   |    O(n)    |  O(n)  |
| Sorted linked list |   O(1)   |    O(1)    |  O(n)  |
| Balanced BST       | O(log n) |  O(log n)  |O(log n)|

### Activity 2: Identify valid heaps

Tree one  - min-heap
Tree two  - Not a heap, child values are both larger and smaler
Tree tree - min-heap

### Activity 3: Do it yourself

If 12 is added as a right child of 3:
1. 12 is swaped with 3
2. 12 is swaped with 11

Two swaps were requred to restore the heap

### Activity 4: Worst-case time complexities

| Data structure  | Find-max | Delete-Max | Insert |  Find  |
|-----------------|:--------:|:----------:|:------:|:------:|
| Balanced BST    | O(log n) |  O(log n)  |O(log n)|O(log n)|
| Binary max-heap |   O(1)   |  O(log n)  |O(log n)|  O(n)  |

### Activity 5: Index computations

```c++
size_t maxheap::parent_index(size_t index) 
{
    if (index == 0) 
    {
        return npos;
    }
    
    return (index - 1) / 2;
}

size_t maxheap::left_child_index(size_t index) 
{
    return child_index(index, false, m_values.size());
}

size_t maxheap::right_child_index(size_t index) 
{
    return child_index(index, true, m_values.size());
}

size_t maxheap::child_index(size_t index, bool rightChild, size_t heapSize)
{
    auto childIndex = index * 2 + 1 + rightChild;

    if (childIndex >= heapSize)
    {
        return npos;
    }

    return childIndex;
}
```

### Activity 6: Implement the find-max operation

```c++
const task &maxheap::maximum() const 
{
    return m_values[0];
}
```

### Activity 7: Bubbling up

```c++
size_t maxheap::bubble_up(size_t index) 
{
    size_t swaps = 0;

    if (index == 0) 
    {
        return swaps;
    }

    auto parentIndex = parent_index(index);

    while (parentIndex != npos && m_values[index] > m_values[parentIndex])
    {
        swap_at_index(index, parentIndex);
        index = parentIndex;
        parentIndex = parent_index(index);
        swaps++;
    }
    
    return swaps;
}
```

### Activity 8: Bubbling down

```c++
size_t maxheap::bubble_down(size_t index) 
{
    size_t swaps = 0;

    do
    {
        auto swapIndex = index;
        auto rightIndex = right_child_index(index);
        auto leftIndex = left_child_index(index);

        if (rightIndex != npos && m_values[index] < m_values[rightIndex])
        {
            swapIndex = rightIndex;
        }

        if (leftIndex != npos && m_values[swapIndex] < m_values[leftIndex])
        {
            swapIndex = leftIndex;
        }

        if (swapIndex == index)
        {
            return swaps;
        }
        
        swaps++;
        swap_at_index(index, swapIndex);
        index = swapIndex;
    } while (true);
}
```

### Activity 9: Implement heapify

```c++
size_t maxheap::heapify() 
{
    size_t swaps = 0;

    if (!m_values.size())
    {
        return swaps;
    }
    
    for (int i = (m_values.size() / 2) - 1; i >= 0; i--)
    {
        swaps += bubble_down(i);
    }
    
    return swaps;
}
```

### Activity 10: Heapify - time complexity

| Number of values | Number of swaps  |
|------------------|:----------------:|
| 5                |      3           |
| 10               |      8           |
| 20               |      17          |
| 50               |      47          |
| 100              |      96          |
| 200              |      195         |
| 300              |      295         |
| 400              |      394         |
| 500              |      439         |
| 1000             |      992         |

Basically O(n), a couple of swaps less because of the height of the heap?

### Activity 11: Bubbling down vector elements

```c++
void bubble_down(std::vector<int> &values, size_t index, size_t count) 
{
    do
    {
        auto swapIndex = index;
        auto leftIndex = 2 * index + 1;
        auto rightIndex = leftIndex + 1;

        if (rightIndex < count && values[index] < values[rightIndex])
        {
            swapIndex = rightIndex;
        }

        if (leftIndex < count && values[swapIndex] < values[leftIndex])
        {
            swapIndex = leftIndex;
        }

        if (swapIndex == index)
        {
            return;
        }
        
        std::swap(values[index], values[swapIndex]);
        index = swapIndex;
    } while (true);
}

void heapify(std::vector<int> &values) 
{
    auto size = values.size();

    if (!size)
    {
        return;
    }
    
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        bubble_down(values, i, size);
    }
}
```

### Activity 12: In-place heap sort

```c++
void heap_sort(std::vector<int> &values)
{
    heapify(values);
    for (int i = values.size() - 1; i > 0; i--) 
    {
        std::swap(values[i], values[0]);
        bubble_down(values, 0, i);
    }
}
```

### Activity 13: General heap sort

```c++
template<typename T>
void bubble_down(std::vector<T> &values, size_t index, size_t count) 
{
    do
    {
        auto swapIndex = index;
        auto leftIndex = 2 * index + 1;
        auto rightIndex = leftIndex + 1;

        if (rightIndex < count && values[index] < values[rightIndex])
        {
            swapIndex = rightIndex;
        }

        if (leftIndex < count && values[swapIndex] < values[leftIndex])
        {
            swapIndex = leftIndex;
        }

        if (swapIndex == index)
        {
            return;
        }
        
        std::swap(values[index], values[swapIndex]);
        index = swapIndex;
    } while (true);
}

template<typename T>
void heapify(std::vector<T> &values) 
{
    auto size = values.size();

    if (!size)
    {
        return;
    }
    
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        bubble_down(values, i, size);
    }
}

template<typename T>
void heap_sort(std::vector<T> &values)
{
    heapify(values);
    for (int i = values.size() - 1; i > 0; i--) 
    {
        std::swap(values[i], values[0]);
        bubble_down(values, 0, i);
    }
}
```

## Looking back

### What we've learnt

Heaps.

### What were the surprises

templates

### What problems we've encountered

Sadness

### What was or still is unclear

How

### How did the group perform?

Good

