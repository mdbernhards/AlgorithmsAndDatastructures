//
// Created by Dawid Zalewski on 06/12/2020.
//

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#include "letter_counter.h"

unsigned long count_letters(unsigned long counts[static 26], const char* str)
{
    unsigned long count = 0;
    for (size_t i = 0; i < strlen(str) - 1; i++)
    {
        if (isalpha(str[i]))
        {
            counts[tolower(str[i]) - 97]++;
            count++;
        }
    }

    return count;
}


static inline unsigned long sum_all_counts(unsigned long counter[static 26]) {
    unsigned long sum = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        sum += counter[i];
    }
    return sum;
}

int cmp_letter_counts(const void* a, const void* b){
    // compare ignoring the first 8 bits
    unsigned long aa = (*(const unsigned long*)b << 8);
    unsigned long bb = (*(const unsigned long*)a << 8);
    return (aa > bb) ? 1 : ((aa < bb)? -1 : 0);
}

static size_t sorted_counts(unsigned long counts[static 26], unsigned long sorted_counts[static 26]){

    const size_t shift = 8 * (sizeof(unsigned long) - 1);
    for (int i = 0; i < ALPHABET_SIZE; ++i){
        sorted_counts[i] = counts[i] | ((unsigned long)('a' + i) << shift);
    }

    qsort(sorted_counts, ALPHABET_SIZE, sizeof(unsigned long), cmp_letter_counts);
    return shift;
}

void print_counts(unsigned long counts[static 26], _Bool sorted, _Bool asFrequencies){

    const double sum = 100.0 /  (double) sum_all_counts(counts);

    if (sorted) {
        unsigned long* sorted = malloc(sizeof (unsigned long) * ALPHABET_SIZE);
        const size_t shift = sorted_counts(counts, sorted);

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            char letter = (char)(sorted[i] >> shift);
            unsigned int count = (unsigned int)((sorted[i] << 8) >> 8);
            if (asFrequencies){
                printf("%c: %0.2f%%\n", letter, (double)count * sum);
            }
            else {
                printf("%c: %u\n", letter, count);
            }
        }
        free(sorted);

    }
    else
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i) 
        {
            if (asFrequencies)
            {
                printf("%c: %0.2f%%\n", 'a' + i, (double)counts[i] * sum);
            }
            else 
            {
                printf("%c: %ld\n", 'a' + i, counts[i]);
            }
        }
    }
}

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
        buffer[j] = (char)(maxIndex + 97);
    }
    
    return buffer;
}
