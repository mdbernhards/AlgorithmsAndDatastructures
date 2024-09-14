#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counter.h"

void process_word(counter_t* counter, const char* word) 
{
    counter_increment(counter, word);
}

void process_line(counter_t* counter, char* line) {
    const char* sep = "\t” (),.;:?!\"\r\n'_-*";

    // TODO: How does this function work? (Activity 9)
    char* token = strtok(line, sep);
    while (token) {
        if (strlen(token) > 0) process_word(counter, token);
        token = strtok(NULL, sep);
    }
}

bool process_file(const char* filename, counter_t * counter) {
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

int main(void) {
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

    printf("found %zu different words\n\n\n", counter.count);

    counter_t* newCounter = counter_create(counter.count);
    memcpy(newCounter, &counter, sizeof(counter_t));
    qsort(newCounter->data, newCounter->count, sizeof(pair_t), compare_pair_values);

    for (size_t i = 0; i < 10; i++)
    {
        printf("%s found %lu times\n", newCounter->data[i].key, newCounter->data[i].value);
    }

    counter_destroy(&counter);
    return 0;
}
