#include "kvmap.h"

#include <stdio.h>
#include <stdlib.h>

KVMap* ldh_KVMapCreate(size_t capacity)
{
    KVMap* map = malloc(sizeof(KVMap));
    map->capacity = capacity;
    map->size = 0;

    map->list = malloc(sizeof(KVPair) * capacity);
    return map;
}

void ldh_KVMapDestroy(KVMap* map)
{
    for(int i = 0; i <= map->capacity - 1; i++)
    {
        KVPair* p = map->list[i];

        // Only delete p if is isn't NULL.
        if(p)
        {
            printf("Destroying Pair key %s value %s \n", p->key->text, p->value->text );
            ldh_KVPairDestroy(map->list[i]);
        }
    }

    free(map->list);
    free(map);
}

bool ldh_KVMapInsert(KVMap* map, char* value)
{
    long hashIndex = ldh_Hash(value);
    printf("Val: %s \n", value);
    size_t hashMod = hashIndex % map->capacity;


    // TODO Need to find a way to deal with collisions.

    if(map->list[hashMod] == NULL)
    {
        printf("Insert: str: %s hash:%lu mod:%lu \n", value, hashIndex, (hashIndex % map->capacity ));
        map->list[hashMod] = ldh_KVPairCreate(value, "TESTVAL");
        map->size++;
        return true;
    }else
    {
        printf("No insert possible for value \"%s\" at position %lu.\n", value, hashMod);
        return false;
    }
}

KVPair* ldh_KVMapGetVal(KVMap* map, char* value)
{
    unsigned long hashMod = ldh_Hash(value) % map->capacity;
    KVPair* hashValue = map->list[hashMod];

    if(hashValue != NULL && *hashValue->key->text == *value)
    {
        return hashValue;
    }else 
    {
        return NULL;
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
