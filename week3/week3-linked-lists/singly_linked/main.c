#include <stdio.h>
#include <malloc.h>
#include "list.h"
#include "test_list.h"

/// Prints the values stored in the given sequence of nodes
/// TODO: implement (Activity 2)
/// \param first the first node in the sequence
void print_nodes(const node_t *first) {
    while (first != 0)
    {
        printf("%d, ", first->value);
        first = first->next;
    }
        printf("\n");
}

int main(void) {
    // see list.h for the definition of the node_t structure
    node_t first = {.value = 1,
            .next = &(node_t) {.value = 2,
                    .next = &(node_t) {.value = 3,
                            .next = &(node_t) {.value = 4,
                                    .next = NULL}}}};

    // TODO - activity 1: use arrow operator instead of pointer dereferences
    printf("first: %d\n", first.value);
    printf("second: %d\n", (first.next)->value);
    printf("third: %d\n", ((first.next)->next)->value);
    printf("fourth: %d\n", (((first.next)->next)->next)->value);

    // TODO - activity 2: print the values using the print_nodes function
    print_nodes(&first);                // expected output: 1, 2, 3, 4
    print_nodes(first.next->next);  // expected output: 3, 4

    list_t list;
    list.head = node_create(2);		// pointer to first node
    list.head->next = node_create(3);	// create and add second node
    list.head->next->next = node_create(7);	// create and add third node
    list.head->next->next->next = node_create(42);	// add a final node

    // TODO: the following call must deallocate the nodes of list -- use an address sanitizer to check this!
    list_destroy(&list);	// deallocate all memory    (Activity 3)


    // implement the functions list_append, list_at, list_remove_first, and list_remove_last
    // in the source file list.c
    // uncomment the functions listed below to test your implementations
    test_list_append(); // Activity 4
    test_list_at(); // Activity 6
    test_list_remove_last();    // Activity 8

    // NOTE: for activities 9, 10, and 11, see the week3-doubly-linked-lists project
    return 0;
}
