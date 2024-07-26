#include "map.h"
#include "kvpair.h"

#include <stdio.h>
#include <stdlib.h>

Map* ldh_MapCreate(size_t capacity)
{
    Map* map = malloc(sizeof(Map));
    map->capacity = capacity;
    map->size = 0;

    map->list = malloc(sizeof(KVPair) * capacity);
    return map;
}

void ldh_MapDestroy(Map* map)
{
    for(int i = 0; i <= map->capacity - 1; i++)
    {
        KVPair* p = map->list[i];

        // Only delete p if is isn't NULL.
        if(p)
        {
            ldh_KVPairDestroy(map->list[i]);
        }
    }

    free(map->list);
    free(map);
}

bool ldh_MapRemove(Map* map, char* value)
{
    long hashIndex = ldh_Hash(value);
    size_t hashMod = hashIndex % map->capacity;

    KVPair* mapValue = map->list[hashMod];

    if (mapValue)
    {
        /* *mapValue = NULL; */
        map->size--;
        ldh_KVPairDestroy(mapValue);
        return true;
    }else
    {
        return false;
    }
}

bool ldh_MapInsert(Map* map, char* value)
{
    long hashIndex = ldh_Hash(value);
    size_t hashMod = hashIndex % map->capacity;

    // TODO Need to find a way to deal with collisions.

    if(map->list[hashMod] == NULL)
    {
        map->list[hashMod] = ldh_KVPairCreate(value, "TESTVAL");
        map->size++;
        return true;
    }else
    {
        printf("No insert possible for value \"%s\" at position %lu.\n", value, hashMod);
        return false;
    }
}

KVPair* ldh_MapGetVal(Map* map, char* value)
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

void ldh_MapPrint(Map* map)
{
    printf("\n");
    printf(">| Capacity: %lu Size:%lu\n", map->capacity, map->size);

    for(int i = 0; i <= map->capacity - 1; i++)
    {
        KVPair* pair = map->list[i];

        if(pair == NULL)
        {
            printf(">| ...\n");
        }else 
        {
            printf(">| %s | %s\n", pair->key->text, pair->value->text);
        }
    }
}

long
ldh_Hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
