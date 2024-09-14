#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "hashmapfunctions.h"

size_t fnv1a_hash(const char *str) {
    // TODO (Activity 5): implement the FNV-1a hash function
    //  Make sure that the function returns the same hash for uppercase/lowercase versions of the same string

    const size_t FNV_PRIME = 0x00000100000001b3;
    const size_t FNV_OFFSET_BASIS = 0xcbf29ce484222325;

    size_t hash = FNV_OFFSET_BASIS;

    int i = 0;
    while (str[i] != '\0')
    {
        hash = ((tolower(str[i]) ^ hash) * FNV_PRIME);
        i++;
    }
    
    return hash;
}

bool str_equals(const char *s1, const char *s2) 
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (tolower(s1[i]) != tolower(s2[i]))
        {
            return false;
        }
        i++;
    }

    if(s1[i] == '\0' && s2[i] == '\0')
    {
        return true;
    }
    
    return false;
}

