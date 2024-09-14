//
// Created by rgr24 on 17/02/2023.
//

#include "list.h"
#include <stdlib.h>

node_t *node_init(node_t *ptr, int value) {
    if (ptr != NULL) {
        ptr->next = NULL;
        ptr->value = value;
    }
    return ptr;
}

node_t *node_create(int value) {
    return node_init((node_t *) malloc(sizeof(node_t)), value);
}

list_t *list_init(list_t *plist) {
    if (plist != NULL) plist->head = NULL;
    return plist;
}

void list_destroy(list_t *plist) {
    if (plist == NULL || plist->head == NULL)
    {
        return;
    }
    struct node *ptr = plist->head;
    struct node *nextPtr = plist->head->next;
    while(ptr != NULL)
    {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
}

void list_prepend(list_t *plist, int value) {
    node_t *node = node_create(value);
    if (node != NULL) {
        node->next = plist->head;
        plist->head = node;
    }
}

void list_append(list_t *plist, int value) {
    struct node *node = node_create(value);
    if (node == NULL || plist == NULL) 
    {
        return;
    }

    if (plist->head == NULL) 
    {
        plist->head = node;
        return;
    }

    node_t *current = plist->head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;
}

const node_t * list_at(const list_t *plist, size_t index) {
    struct node *ptr = plist->head;
    for (size_t i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

bool list_remove_first(list_t *plist) {
    node_t *head = plist->head;
    if (head != NULL) plist->head = plist->head->next;
    free(head);
    return head != NULL;
}

bool list_remove_last(list_t *plist) {
    if (plist == NULL || plist->head == NULL)
    {
        return false;
    }

    struct node *ptr = plist->head;
    node_t *ptr2 = ptr->next;
    while(ptr->next != NULL)
    {
        ptr2 = ptr;
        ptr = ptr->next;
    }

    if (ptr2 != NULL) 
    {
        ptr2->next = NULL;
        free(ptr);
    } 
    else 
    {
        free(ptr);
        plist->head = NULL;
    }
    
    return true;
}
