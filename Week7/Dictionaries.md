# Week 7 - Dictionaries

## Team

>Members:
>
>- Mārtiņš Dāvis Bernhards
>- Damīrs Zaļums
>
> Date: 08 04 2024

## Activities 

Make sure to have the activities signed off regularly to ensure progress is tracked.

Download the provided project and open it in CLion.

### Activity 1: The ctype header file
int iscntrl(int c)
This function checks whether the passed character is control character.

int tolower(int c)
This function converts uppercase letters to lowercase.

int isspace(int c)
This function checks whether the passed character is white-space.

int isalpha(int c)
This function checks whether the passed character is alphabetic.

### Activity 2: Count letters in a string

```c
unsigned long count_letters(unsigned long counts[static 26], const char* str)
{
    unsigned long count = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            counts[tolower(str[i]) - 'a']++;
            count++;
        }
    }

    return count;
}

int main(void){
	unsigned long counts[26] = {0};
	const char* text = "The Quick Brown Fox Jumps Over The Lazy Dog.";
	unsigned long total = count_letters(&counts[0], text);
	assert(35 == total);
	print_counts(&counts[0], true, false);
}
```

### Activity 3: Recognizing languages

```c
const char* make_signature(unsigned long counts[static 26])
{
    static char buffer[7] = {0};
    int maxIndex = 0;

    for (size_t j = 0; j < 6; j++)
    {
        for (size_t i = 0; i < 25; i++)
        {
            if(counts[i] > counts[maxIndex])
            {
                maxIndex = i;
            }
        }

        counts[maxIndex] = 0;
        buffer[j] = (char)(maxIndex + 'a');
    }
    
    return buffer;
}

int main(void) {
    unsigned long counts1[26] = {15,3,4,5,16,6,7,8,9,7,6,3,2,11,14,1,2,12,13};
	unsigned long counts2[26] = {16,4,7,5,20,7,4,3,14,5,9,1,2,18,6,12,9,13,9,15};
	assert(strcmp("eaosrn", make_signature(counts1)) == 0);
	assert(strcmp("enatir", make_signature(counts2)) == 0);
}
```

| File       | Signature | Language |
| ---------- | --------- | -------- |
| alice0.txt |   etaoin  |    en    |
| alice1.txt |   iantes  |    fi    |
| alice2.txt |   eaionr  |    it    |
| alice3.txt |   enisra  |    de    |

### Activity 4: Find out: dictionaries in other languages

Dictionary names:
C# - Dictionary<TKey, TValue>()
Python - Dictionary
Java - Java.util.Dictionary
GdScript - Dictionary
	Insert - Dictionary[key] = value
	Delete - erase ( Variant key )
	Check - has ( Variant key ) const
	Get - get ( Variant key, Variant default=null ) const or = Dictionary[key]
Ruby - Hashes
	Insert - dictionary[key] = value
	Delete - delete(key)
	Check - include?(key) or h.has_key?(value)
	Get - dictionary.fetch(value) or dictionary[key]

### Activity 5: Generic sorting in C

```c
int compare_strings(const void* a, const void* b) 
{
    const char *char_ptr_a = *(char**)a;
    const char *char_ptr_b = *(char**)b;
    return strcmp(char_ptr_a,char_ptr_b);
}

int main(void) {
    const char * strings[] = {"Spam", "Cheese", "Knights", "Holy Grail", "Lumberjack", "Ministry", "Swallow",
                              "Silly", "Black Knight", "Camelot", "Coconut", "Parrot", "Shrubbery", "Taunt", "Argument"};
							  
    qsort(strings, 15, sizeof(*strings), compare_strings);

    print_string_array(strings, sizeof(strings) / sizeof(const char *));

	return 0;
}
```

[Argument, Black Knight, Camelot, Cheese, Coconut, Holy Grail, Knights, Lumberjack, Ministry, Parrot, Shrubbery, Silly, Spam, Swallow, Taunt]

### Activity 6: Generic searching in C

```c
int main(void) {
    const char * strings[] = {"Spam", "Cheese", "Knights", "Holy Grail", "Lumberjack", "Ministry", "Swallow",
                              "Silly", "Black Knight", "Camelot", "Coconut", "Parrot", "Shrubbery", "Taunt", "Argument"};

    qsort(strings, 15, sizeof(*strings), compare_strings);
    print_string_array(strings, sizeof(strings) / sizeof(const char *));

    const char * targets[] = {"Holy Grail", "Parrot", "Rabbit"};
    
    for (size_t i = 0; i < 3; i++)
    {
        bsearch_result_t result = binary_search(&targets[i], strings, 15, sizeof(*strings), compare_strings);

        if (result.found)
        {
            printf("%s found at: %zu \n", targets[i], result.index);
        }
        else
        {
            printf("%s not found \n", targets[i]);
        }
    }
    
    return 0;
}
```
Holy Grail found at: 5 
Parrot found at: 9 
Rabbit not found

### Activity 7: Counter - function implementations

```c
bool counter_contains_key(const counter_t *counter, const char *key)
{
    if (counter == NULL && key == NULL)
    {
        return false;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;

    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);
    return result.found;
}

size_t counter_get_count(const counter_t *counter, const char *key)
{
    if (counter == NULL && key == NULL)
    {
        return false;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;

    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);

    if (result.found)
    {
        return counter->data[result.index].value;
    }
    else
    {
        return 0;
    }
}

void counter_remove_key(counter_t *counter, const char *key) 
{
    if (counter == NULL && key == NULL)
    {
        return;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;
    
    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);

    if (!result.found)
    {
        return;
    }

    memcpy(&counter->data[result.index], &counter->data[result.index + 1], (counter->count - result.index - 1) * sizeof(pair_t));
    counter->count--;
}

void counter_increment(counter_t *counter, const char *key) 
{
    if (counter == NULL && key == NULL)
    {
        return;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;

    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);

    if (result.found)
    {
        counter->data[result.index].value++;

    }
    else if (_ensure_capacity(counter))
    {
        memcpy(&counter->data[result.index + 1], &counter->data[result.index], (counter->count - result.index) * sizeof(pair_t));
        counter->data[result.index] = tempPair;
        counter->count++;
    }
}

void counter_destroy(counter_t *counter) 
{
    if (counter == NULL && counter->data == NULL)
    {
        return;
    }

    for (size_t i = 0; i < counter->count; i++)
    {
       destroy_pair(&counter->data[i]);
    }

    free(counter->data);
    counter = NULL;
}
```

### Activity 8: Find out: function `strtok`

strtok breaks string str into a series of tokens using the delimiter delim, delim is the value by the string gets searched for, it can change every call.
This function returns a pointer to the first token found in the string. A null pointer is returned if there are no tokens left to retrieve.

```c
void process_line(counter_t* counter, char* line) 
{
	// separator characters / delim
	const char* sep = "\t (),.;:?!\"\r\n'_-*";

	// Gets the first token
	char* token = strtok(line, sep);
	while (token) 
	{
		// if the token isn't empty go in if
		if (strlen(token) > 0)
		{
			// Saves the word in dictionary or increments count
			process_word(counter, token);
		}

	// Gets the next token	
	token = strtok(NULL, sep);
	}
}

```

### Activity 9: How many words?

```c
void process_word(counter_t* counter, const char* word) 
{
    counter_increment(counter, word);
}

int main(void) 
{
    counter_t counter;
    counter_init(&counter, 10);
    process_file("alice0.txt", &counter);

    const char * targets[] = {"Alice", "the", "Rabbit"};
    
    for (size_t i = 0; i < 3; i++)
    {
        if (counter_contains_key(&counter, targets[i]))
        {
            size_t count = counter_get_count(&counter, targets[i]);
            printf("%s found %zu times\n", targets[i], count);
        }
        else
        {
            printf("%s not found \n", targets[i]);
        }
    }

    printf("found %zu different words\n", counter.count);

    counter_destroy(&counter);
    return 0;
}
```

Alice found 401 times
the found 1691 times
Rabbit found 47 times
found 3713 different words

### Activity 10: Most frequent words

```c
int compare_pair_values(const void* a, const void* b) 
{
    const pair_t pair_t_ptr_a = *(const pair_t *)a;
    const pair_t pair_t_ptr_b = *(const pair_t *)b;
    return pair_t_ptr_b.value - pair_t_ptr_a.value;
}

int main(void) 
{
    counter_t counter;
    counter_init(&counter, 10);
    process_file("alice0.txt", &counter);

    counter_t* newCounter = counter_create(counter.count);
    memcpy(newCounter, &counter, sizeof(counter_t));
    qsort(newCounter->data, newCounter->count, sizeof(pair_t), compare_pair_values);

    for (size_t i = 0; i < 10; i++)
    {
		printf("%s found %zu times\n", newCounter->data[i].key, newCounter->data[i].value);
    }

    counter_destroy(&counter);
    return 0;
}
```
the found 1691 times
and found 817 times
to found 797 times
a found 672 times
of found 610 times
it found 523 times
she found 508 times
said found 458 times
in found 418 times
you found 402 times

## Looking back

### What we've learnt

We've learned how to create / use dictionaries.

### What were the surprises

Casting functions

### What problems we've encountered

Casting functions

### What was or still is unclear

~Casting functions

### How did the group perform?

Good?