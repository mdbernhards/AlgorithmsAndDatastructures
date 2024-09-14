#include "merge_sort.h"
#include <stdio.h>

size_t g_compares = 0;

node_t *split(node_t *phead) {
    node_t *fast = phead->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next;
        fast = fast->next;
        phead = phead->next;
    }

    node_t *secondHalfStart = phead->next;
    phead->next = NULL;

    return secondHalfStart;
}

node_t *merge(node_t *a, node_t *b) 
{
    node_t sentinel = {.next = NULL};
    node_t *result = &sentinel;

    while (a != NULL && b != NULL) 
    {
        g_compares++;

        if (a->value < b->value) 
        {
            result->next = a;
            a = a->next;
        } 
        else 
        {
            result->next = b;
            b = b->next;
        }

        result = result->next;
    }
    
    if (a == NULL)
    {
        result->next = b;
    }
    else
    {
        result->next = a;
    }

    return sentinel.next;
}

node_t *merge_sort(node_t *first) 
{
    if (first->next == NULL)
    {
        return first;
    }

    node_t * next = split(first);

    first = merge_sort(first);
    next = merge_sort(next);

    first = merge(first, next);

    return first;
}

void list_sort(list_t *plist) {
    if (plist->head != NULL) plist->head = merge_sort(plist->head);
}
