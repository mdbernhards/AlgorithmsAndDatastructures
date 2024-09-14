//
// Created by Dawid Zalewski on 06/12/2020.
//

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "letter_counter.h"
#include "langugage_recognizer.h"

void demo(void){
    unsigned long counts[26] = {0};
    const char* text = "The Quick Brown Fox Jumps Over The Lazy Dog.";
    unsigned long total = count_letters(&counts[0], text);
    assert(35 == total);
    print_counts(&counts[0], true, false);
}

unsigned long* process_file(const char* fileName) {

    unsigned long * counts = calloc(sizeof(unsigned long[ALPHABET_SIZE]), sizeof(unsigned long));

    FILE* fp = fopen(fileName, "r");
    unsigned long sum = 0;
    if (fp) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp)) {
            sum += count_letters(&counts[0], buffer);
        }
        printf("In total counted %ld letters.\n", sum);
    }
    return counts;
}

int main(void){
    // TODO (Activity 2): implement the count_letters function & test it with the demo function
    demo();

    // TODO (Activity 3, part 2): recognize the language of the text in the file
    unsigned long* counts = process_file("alice0.txt");
    const char* signature = make_signature(&counts[0]);
    const char* language = match_language(signature);
    printf("Signature: %s\n", signature);
    printf("Detected language = %s\n", language? language : "none");
    free(counts);

    counts = process_file("alice1.txt");
    signature = make_signature(&counts[0]);
    language = match_language(signature);
    printf("Signature: %s\n", signature);
    printf("Detected language = %s\n", language? language : "none");
    free(counts);

    counts = process_file("alice2.txt");
    signature = make_signature(&counts[0]);
    language = match_language(signature);
    printf("Signature: %s\n", signature);
    printf("Detected language = %s\n", language? language : "none");
    free(counts);

    counts = process_file("alice3.txt");
    signature = make_signature(&counts[0]);
    language = match_language(signature);
    printf("Signature: %s\n", signature);
    printf("Detected language = %s\n", language? language : "none");
    free(counts);
}
