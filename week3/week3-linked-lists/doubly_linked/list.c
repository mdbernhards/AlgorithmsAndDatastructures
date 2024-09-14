//
// Created by rgr24 on 17/02/2023.
//

#include "list.h"
#include <stdlib.h>

node_t *node_init(node_t *ptr, int value) {
    if (ptr != NULL) {
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->value = value;
    }
    return ptr;
}

node_t *node_create(int value) {
    return node_init( (node_t*) malloc(sizeof(node_t)), value);
}

list_t *list_init(list_t *plist) {
    if (plist != NULL) plist->head = plist->tail = NULL;
    return plist;
}

void list_prepend(list_t *plist, int value) {
    node_t * node = node_create(value);
    if (node != NULL) {
        // current head comes after node
        node->next = plist->head;

        // let the current head point back to the node
        if (plist->head != NULL) plist->head->prev = node;

        // update current head
        plist->head = node;

        // if the list was empty, then now it has a tail
        if (plist->tail == NULL) plist->tail = node;
    }
}

void list_append(list_t *plist, int value) {
    node_t *node = node_create(value);
    if (node != NULL) {
        if(plist->tail == NULL)
        {
            plist->tail = node;
            plist->head = node;
        }
        else
        {
            node->prev = plist->tail;
            plist->tail->next = node;
            plist->tail = node;
        }
    }
}

void list_remove(list_t *plist, node_t *pnode) {
    if (plist == NULL || plist->head == NULL || pnode == NULL)
    {
        return;
    }
     if (pnode == plist->head) 
     {
        plist->head = pnode->next;
    }

    if (pnode == plist->tail) 
    {
        plist->tail = pnode->prev;
    }

    if (pnode->prev != NULL) 
    {
        pnode->prev->next = pnode->next;
    }
    if (pnode->next != NULL) 
    {
        pnode->next->prev = pnode->prev;
    }

    free(pnode);
}

void list_insert_before(list_t *plist, node_t *pnode, int value) {
    node_t *node = node_create(value);

    if (plist == NULL || pnode == NULL || node == NULL) 
    {
        return;
    }

    node->prev = pnode->prev;
    node->next = pnode;
    if(pnode->prev != NULL)
    {
        pnode->prev->next = node;
    }

    pnode->prev = node;
}