# Week 8 - Hashing

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 16 05 2024 13.49

## Activities

Make sure to have the activities signed off regularly to ensure progress is tracked.

Download the provided project and open it in CLion.

### Activity 1: The costs of maintaining order

|  Moved     | 8609 | 6348 | 4992 | 5839 | 1622 | 5450 | 7198 | 4827 |
| ---------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|     0      | 8609 |      |      |      |      |      |      |      |
|     1      | 6348 | 8609 |      |      |      |      |      |      |
|     2      | 4992 | 6348 | 8609 |      |      |      |      |      |
|     2      | 4992 | 5839 | 6348 | 8609 |      |      |      |      |
|     4      | 1622 | 4992 | 5839 | 6348 | 8609 |      |      |      |
|     3      | 1622 | 4992 | 5450 | 5839 | 6348 | 8609 |      |      |
|     1      | 1622 | 4992 | 5450 | 5839 | 6348 | 7198 | 8609 |      |
|     6      | 1622 | 4827 | 4992 | 5450 | 5839 | 6348 | 7198 | 8609 |

Total records moved: 19

### Activity 2: Calculate the moduli

| id         | 8609 | 6348 | 4992 | 5839 | 1622 | 5450 | 7198 | 4827 |
| ---------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| **mod 8**  |  1   |  4   |  0   |  7   |  6   |  2   |  6   |  3   |
| **mod 16** |  1   |  12  |  0   |  15  |  6   |  10  |  14  |  11  |
| **mod 17** |  7   |  7   |  11  |  8   |  7   |  10  |  7   |  16  |

Maybe in some other configuration, but it doesn't look reliable, the mod 16 for example has only 16 values it could be so if there are more then 16 elements it will 100% repeat.

### Activity 3: Hash functions

Hash function is used to index values to fixed-size values returning a hash that could be used in a hash table to map the values to the smaller hashes.
It should always output the same output for a specific input.

You can hash passwords, check file integrity so that someone can't edit the files, etc.

Problems could be that a Hash function can be backwards engineered and that multiple inputs can have the same output.

### Activity 4: Simplistic hash function

```c
size_t simple_hash(const char* str) 
{
    size_t hash = 0;
    while (*str) 
    {
        hash += *str;
        str++;
    }

    return hash;
}
```

What is the hash of the strings "pictures", "strength", "partners", "computer", "empty", "words", "nasty", "spoon", "visit", "busy", and "work" when using the `simple_hash` function?

| Word        | hash |
| ----------- | ---- |
| pictures    | 879  |
| strength    | 879  |
| partners    | 879  |
| computer    | 879  |
| empty       | 559  |
| words       | 559  |
| nasty       | 559  |
| spoon       | 559  |
| visit       | 559  |
| busy        | 451  |
| work        | 451  |

### Activity 5: Implement FNV-1a

```c
size_t fnv1a_hash(const char *str) 
{
    const size_t FNV_PRIME = 0x00000100000001b3;
    const size_t FNV_OFFSET_BASIS = 0xcbf29ce484222325;

    size_t hash = FNV_OFFSET_BASIS;

    int i = 0;
    while (str[i] != '\0')
    {
        hash = ((tolower(str[i]) ^ hash) * FNV_PRIME);
        i++;
    }
    
    return hash;
}
```

### Activity 6: Case-insensitive string equality

```c
bool str_equals(const char *s1, const char *s2) 
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (tolower(s1[i]) != tolower(s2[i]))
        {
            return false;
        }
        
        i++;
    }

    if(s1[i] == '\0' && s2[i] == '\0')
    {
        return true;
    }
    
    return false;
}
```

### Activity 7: Implement lookup

```c
pair_t * hashmap_lookup(const hashmap_t *map, const char *key) 
{
    if (!map || !key) 
    {
        return false;
    }

    size_t index = map->hash_fun(key) % map->capacity;
    node_t *current = (map->slots[index]).head;
    
    while (current) 
    {
        pair_t *pair = current->data;
        if (map->equals_fun(pair->key, key)) 
        {
            return pair;
        }
        
        current = current->next;
    }
    
    return NULL;
}
```

### Activity 8: Adding and removing keys and values

```c
bool hashmap_add(hashmap_t *map, const char *key, size_t value) 
{
    if (!map || !key) 
    {
        return false;
    }

    pair_t *pair = hashmap_lookup(map, key);

    if (pair) 
    {
        pair->value = value;
        return false;
    }

    pair_t *tempPair = create_pair(key, value);
    node_t *tempNode = node_create(tempPair);

    size_t index = map->hash_fun(key) % map->capacity;
    list_prepend(&map->slots[index], tempNode);

    map->count++;
    _rehash(map);
    
    return true;
}

void hashmap_remove(hashmap_t *map, const char *key) 
{
    if (!map || !key) 
    {
        return;
    }

    size_t index = map->hash_fun(key) % map->capacity;

    pair_t *tempPair = hashmap_lookup(map, key);
    node_t *tempNode = node_create(tempPair);
    list_remove(&map->slots[index], tempNode);

    map->count--;
}
```

### Activity 9: Word counting

#### Top 10 words in "alice0.txt"

| rank | word      | frequency |
| ---- | --------- | --------- |
| 1    |  The      |  1644     |
| 2    |  And      |  872      |
| 3    |  To       |  729      |
| 4    |  A        |  632      |
| 5    |  It       |  595      |
| 6    |  She      |  553      |
| 7    |  I        |  545      |
| 8    |  Of       |  514      |
| 9    |  Said     |  462      |
| 10   |  You      |  411      |

#### Frequencies of the following words

| word        | frequency |
| ----------- | --------- |
| Dog         |   3       |
| Caterpillar |  28       |
| Cat         |  37       |
| Rabbit      |  51       |

#### Words in slot

How many words are stored in the slot with index 10?

 71 words?

#### Empty slots

How many slots are empty? 
0?

#### Length of longest chain

What is the length of the longest of the 31 linked lists?

104?

### Activity 10: Tracking load statistics

| Capacity                     | 3331 | 7333 | 15149 |
| ---------------------------- | ---- | ---- | ----- |
| Items                        | 2576 | 2576 | 2576  |
| Load factor                  | 0.77 | 0.35 | 0.17  |
| Fraction of free slots       | 0.46 | 0.70 | 0.84  |
| Slots with more than 0 items | 1797 | 2167 | 2384  |
| Slots with more than 1 item  |  601 |  358 |  182  |
| Slots with more than 2 items |  141 |   45 |   10  |
| Slots with more than 3 items |   32 |    6 |    0  |
| Slots with more than 4 items |    5 |    0 |    0  |
| Length of longest chain      |    5 |    4 |    3  |

Capacity smaller than 200000 for which no slot has more than one word stored after processing "alice0.txt": Didn't find any??? took atleast 2h ;D

### Activity 11: Time complexity

| Operation | Time complexity |
| --------- | --------------- |
| Lookup    |   O(1)        |
| Insert    |   O(1)        |
| Remove    |   O(1)        |

### Activity 12: Implement rehashing

```c
void hashmap_rehash(hashmap_t *map, size_t new_capacity) 
{
    list_t *newSlots = malloc(sizeof(list_t*) * new_capacity);
    for (size_t i = 0; i < new_capacity; i++) 
    {
        list_init(&newSlots[i]);
    }

    for (size_t i = 0; i < map->capacity; i++)
    {
        node_t* current = map->slots[i].head;
        while (current) 
        {
            node_t* next = current->next;
            pair_t* temp = current->data;

            size_t index = map->hash_fun(temp->key) % new_capacity;
            list_prepend(&newSlots[index], current);
            
            current = next;
        }
    }

    free(map->slots);

    map->capacity = new_capacity;
    map->slots = newSlots;
}
```

Load statistics when starting with an initial capacity of 31, after processing the file "alice0.txt":

| Capacity                     | ???? |
| ---------------------------- | ---- |
| Items                        | 2576 |
| Load factor                  | 0.65 |
| Fraction of free slots       | 0.52 |
| Slots with more than 0 items | 1908 |
| Slots with more than 1 item  | 545  |
| Slots with more than 2 items | 100  |
| Slots with more than 3 items | 20   |
| Slots with more than 4 items | 3    |
| Length of longest chain      | 5    |

## Looking back

### What we've learnt

Hashmaps are cool

### What were the surprises

how it works

### What problems we've encountered

Segmentation fault

### What was or still is unclear

Fill in...

### How did the group perform?

How was the collaboration? What were the reasons for hick-ups? What worked well? What can be improved next time?
