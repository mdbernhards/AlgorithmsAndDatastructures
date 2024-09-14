//
// Created by rgr24 on 21/03/2023.
//
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include "set.h"

size_t g_comparisons = 0;

size_t set_index_of(const set_t * set, double value) 
{
    size_t lo = 0, hi = set->count;

    while (lo != hi)
    {
        int mid = (hi + lo) / 2;
        g_comparisons++;
        if (set->cmp_fun(set->data[mid], value) == 0)
        {
            return mid;
        }
        else if (set->cmp_fun(set->data[mid], value) == -1)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    return hi;
}

void set_add(set_t * set, double value) 
{
    if (!ensure_capacity(set)) 
    {
        return;
    }

    size_t insertIndex = set_index_of(set, value), temp1, temp2;

    if (set->cmp_fun(set->data[insertIndex], value) == 0) 
    {
        return;
    }

    temp2 = set->data[insertIndex];
    set->data[insertIndex] = value;

    for (size_t i = insertIndex; i < set->count ; i++)
    {
        temp1 = temp2;
        temp2 = set->data[i + 1];
        set->data[i + 1] = temp1;
    }

    set->data[insertIndex] = value;
    set->count++;
}

void set_remove(set_t * set, double value) 
{
    size_t removeIndex = set_index_of(set, value);

    if (set->cmp_fun(set->data[removeIndex], value) != 0)
    {
        return;
    }

    for (size_t i = removeIndex; i < set->count; i++)
    {
        set->data[i] = set->data[i + 1];
    }

    set->count--;
}

bool set_contains(const set_t * set, double value) 
{
    size_t containsIndex = set_index_of(set, value);

    if (set->cmp_fun(set->data[containsIndex], value) == 0)
    {
        return true;
    }

    return false;
}

set_t * set_create(size_t init_cap, compare_fun_t cmp_fun) {
    return set_init((set_t*) malloc(sizeof(set_t)), init_cap, cmp_fun);
}

set_t * set_init(set_t * set, size_t init_cap, compare_fun_t cmp_fun) {
    if (set != NULL) {
        set->cmp_fun = cmp_fun;
        set->data = (double*) malloc(sizeof(double) * init_cap);
        set->count = 0;
        set->capacity = set->data != NULL ? init_cap : 0;
    }
    return set;
}

