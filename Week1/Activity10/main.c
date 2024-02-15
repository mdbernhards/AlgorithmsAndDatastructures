#include <stdio.h>      // for printf, fopen, fgetc
#include <stdlib.h>     // for realloc & free
#include <assert.h>     // for assert

/*
 * Reads the file "E.coli.txt" into a dynamically allocated array
 */
int main( void ) {
    char *ptr = NULL; // the memory address of the array
    size_t capacity = 20; // the capacity of the array
    size_t count = 0; // the number of actual values stored in the array

    ptr = realloc(ptr, sizeof(char[capacity])); // allocate memory
    if (ptr == NULL){ // check if allocation worked
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // open the file "E.coli.txt" for reading in text mode
    FILE *file = fopen("E.coli.txt", "r");

    if (file == NULL) { // check if file was opened
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int c = fgetc(file); // read next character from file
    while (c != EOF) {
        /* TODO: re-allocate memory pointed to by ptr if count == capacity
        *  TODO: check if the pointer returned by realloc is not NULL
        */

        ptr[count++] = (char) c; // store current character, then increase count
        c = fgetc(file); // read next character from file
    }

    // count how many 'a's are in the file
    int freq = 0;
    for (size_t i = 0; i < count; ++i) if (ptr[i] == 'a') freq++;

    printf("Character 'a' appears %d times in the array - this should be 1142069\n", freq);

    // let the program crash if the frequency is not correct
    assert(freq == 1142069);

    free(ptr); // release the memory
}
