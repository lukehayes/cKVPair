#include "kvmap.h"

#include <stdio.h>
#include <stdlib.h>

KVMap* ldh_KVMapCreate(size_t capacity)
{
    KVMap* map = malloc(sizeof(KVMap));
    map->capacity = capacity;
    map->size = 0;

    map->list = malloc(sizeof(KVMap) * capacity);
    return map;
}

void ldh_KVMapDestroy(KVMap* map)
{
    free(map->list);
    free(map);
}

bool ldh_KVMapInsert(KVMap* map, char* val)
{
    unsigned long hashIndex = ldh_Hash(val);
    size_t hashMod = hashIndex % map->capacity;

    if(map->list[hashMod] == NULL)
    {
        printf("Insert: str: %s hash:%lu mod:%lu \n", val, hashIndex, (hashIndex % map->capacity ));
        map->list[hashMod] = val;
        map->size++;
        return true;
    }else
    {
        printf("No insert possible for value \"%s\" at position %lu.\n", val, hashMod);
        return false;
    }
}

const char* ldh_KVMapGetVal(KVMap* map, char* value)
{
    unsigned long hashMod = ldh_Hash((unsigned char*)value) % map->capacity;
    char* hashValue = map->list[hashMod];

    if(hashValue != NULL && hashValue == value)
    {
        return hashValue;
    }else 
    {
        return "NULL";
    }
}

void ldh_KVMapPrint(KVMap* map)
{
    printf("\n");
    printf(">| Capacity: %lu Size:%lu\n", map->capacity, map->size);
    for(int i = 0; i <= map->capacity - 1; i++)
    {
        if(map->list[i] == NULL)
        {
            printf(">| ...\n");
        }else 
        {
            printf(">| %s\n", map->list[i]);
        }
    }
}

unsigned long
ldh_Hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
