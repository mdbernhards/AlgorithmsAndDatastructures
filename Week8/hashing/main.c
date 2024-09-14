#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashmap.h"
#include "statistics.h"
#include "hashmapfunctions.h"

void process_word(hashmap_t * counter, const char* word) 
{
    pair_t *pair = hashmap_lookup(counter, word);

    if (pair)
    {
        hashmap_add(counter, word, pair->value + 1);
    }
    else
    {
        hashmap_add(counter, word, 1);
    }
}

void process_line(hashmap_t* counter, char* line) {
    const char* sep = "\t” (),.;:?!\"\r\n'`_-*";

    char* token = strtok(line, sep);
    while (token) {
        if (strlen(token) > 0) process_word(counter, token);
        token = strtok(NULL, sep);
    }
}

bool process_file(const char* filename, hashmap_t * counter) {
    FILE* fp = fopen(filename, "r");
    if (fp != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp)) {
            process_line(counter, buffer);
        }
        return true;
    }
    return false;
}

int pairCompare(const void *a, const void *b) 
{
    pair_t *pairA = *(pair_t **)a;
    pair_t *pairB = *(pair_t **)b;

    return pairB->value - pairA->value;
}

void print_top_n(hashmap_t * counter, size_t n) 
{
    pair_t **all_pairs = (pair_t **) malloc(counter->count * sizeof(pair_t));

    size_t index = 0;
    for (size_t i = 0; i < counter->capacity; i++)
    {
        node_t* current = counter->slots[i].head;
        while (current) 
        {
            all_pairs[index++] = (pair_t *)current->data;
            current = current->next;
        }
    }

    qsort(all_pairs, counter->count, sizeof(pair_t*), pairCompare);

    for (size_t i = 0 ; i < n; i++)
    {
        printf("%s: %zu times \n", all_pairs[i]->key, all_pairs[i]->value);
    }

    free(all_pairs);

    // TODO (Activity 9):
    //  1. copy the contents from the hashmap to the array
    //  2. use qsort to sort the array on the value of the pairs, descending
    //  3. print the first n pairs from the array
}

int main(void) {
    setbuf(stdout, NULL);

    size_t capacity = 31;
    // TODO (Activity 10)
    //  1. Implement the hashmap_get_load_statistics function in statistics.c
    //  2. Print the load statistics of the hashmap after processing the file
    hashmap_t counter;
    hashmap_init(&counter, capacity, (hash_fun_t) fnv1a_hash, (eq_fun_t) str_equals);
    process_file("alice0.txt", &counter);
    print_top_n(&counter, 50);

    printf("Rabbit: %zu\n", hashmap_get_value(&counter, "Rabbit"));
    printf("Caterpillar: %zu\n", hashmap_get_value(&counter, "Caterpillar"));
    printf("Cat: %zu\n", hashmap_get_value(&counter, "Cat"));
    printf("Dog: %zu\n", hashmap_get_value(&counter, "Dog"));

    printf("At index 10 there are %zu words\n", list_length(&counter.slots[10]));

    size_t count = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        if (counter.slots[i].head == NULL)
        {
            count++;
        }
    }
    
    printf("Empty slots %zu \n", count);

    size_t max = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        if (list_length(&counter.slots[i]) > max)
        {
            max = list_length(&counter.slots[i]);
        }
    }
    printf("Max slot %zu \n", max);
    hashmap_print_load_statistics(stdout, &counter);
    


    hashmap_destroy(&counter);
    return 0;
    // TODO (Activity 9): Determine word count in file "alice0.txt"
    //  1. Create a suitable hash function for strings, and a suitable equality function (either case sensitive or insensitive)
    //  2. Setup a hashmap with your hash & equality function
    //  3. Implement the process_word function so that it uses the hashmap to count the words
    //  4. Process the file "alice0.txt" using the process_file function
    //  5. Implement the print_top_n function & call it to print the top 25 words in the file
}

/*

    for (size_t i = 1; i <= 200000; i++)
    {
        hashmap_t counter2;
        hashmap_init(&counter2, i, (hash_fun_t) fnv1a_hash, (eq_fun_t) str_equals);
        process_file("short.txt", &counter2);
        load_statistics_t result = hashmap_get_load_statistics(&counter2);
        if (result.length_of_longest_chain == 1)
        {
            printf("Lowest slot is %zu \n", i);
            hashmap_destroy(&counter2);
            return 0;
        }

        if (i % 31 == 0)
        {
            printf("at %zu \n", i);
            printf("Longest Chain %zu \n", result.length_of_longest_chain);
        }
        
    }*/