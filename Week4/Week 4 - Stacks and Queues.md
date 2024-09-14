﻿# Week 4 - Stacks and Queues

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 20 03 2023

## Provided code

The `zip` file on Blackboard contains the C code for this week.
The project contains three *targets*: `stacks`, `queues` and `circular-buffer`.

Also, the project uses a static library that provides an array and a linked list.
If you're on Windows, then run your code on WSL.

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

### Activity 1: LIFO vs FIFO

LIFO - Last In First Out
FIFO - First In First Out
LIFO memory buffer - Because you can temporary store date in a specific order and only get it when you need it

### Activity 2: Stacks and LIFO

the sequence is: syeuqtsaonie

### Activity 3: Pushes and pops

Answer: (a) 4 3 2 1 0 9 8 7 6 5 
a 50/50 would have to fail 9 times in a row for 9 to be after 0

### Activity 4: Communication through a linked list

Option 2. (Read FRONT, Write REAR) and 4. (Read REAR, Write FRONT) work correctly.
Others reverse

### Activity 5: FIFO and queues

Answer is: EASYQUESTION

### Activity 6: Arrays, linked lists, and queues

| Operation                          |      Array      |   Linked List  |
| ---------------------------------- | --------------- | -------------- |
| Insert / remove **first** element  |      O(n)       |       O(1)     |
| Insert / remove **last** element   |      O(1)       |       O(1)     |
| Peek first / last element          |      O(1)       |       O(1)     |

Linked list is better in this comparison?
But you should use an array if you want to peek at the elements in the middle.

### Activity 7: Time complexities, once again

| Operation                     | Time complexity |
| ----------------------------- | --------------- |
| Insert / remove first element |     O(1)        |
| Insert / remove last element  |     O(1)        |
| Peek first / last element     |     O(1)        |

### Activity 8: Clock arithmetic

```c
size_t buffer_get_rear_idx(const buffer_t *buffer) {
    
    return (buffer->head + buffer->count) % buffer->capacity;
}
```

### Activity 9: Writing into a circular buffer

```c
bool buffer_try_write(buffer_t *buffer, char character) {
    if (buffer->count < buffer->capacity)
    {
        size_t write_idx = buffer_get_rear_idx(buffer);
        buffer->data[write_idx] = character;
        buffer->count++;

        return true;
    }

    return false;
}
```

### Activity 10: Reading from a circular buffer

```c
bool buffer_try_read(buffer_t *buffer, char *character) {
    if (buffer->count > 0)
    {
        *character = buffer->data[buffer->head];
        if(*character != '\0')
        {
            buffer->count--;
            buffer->head = (buffer->head + 1) % buffer->capacity;
            
            return true;
        }
    }

    return false;
}
```

### Activity 11: Testing the queue

Everything seems to be correctly copied to the output file

## Looking back

### What we've learnt

circular arrays

### What were the surprises

theres a type of array thats better for a queue than a linked list

### What problems we've encountered

couldn't find the output file

### What was or still is unclear

I'm not sure

### How did the group perform?

Good
