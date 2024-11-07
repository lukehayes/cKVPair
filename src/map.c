#include "map.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int MapHashPair(Map* map, char* str)
{
    long hash = MapHash(str);
    int modHash = hash % map->capacity;
    return modHash;
}

Map* MapCreate(size_t initial_size)
{
    Map* map = malloc(sizeof(Map));

    map->data     = malloc(sizeof(MapPair) * initial_size);
    map->capacity = initial_size;
    map->size     = 0;

    return map;
}


MapPair* MapGet(Map* map, char* key)
{
    int modHash = MapHashPair(map, key);
    MapPair* pair = &map->data[modHash];

    return pair;
}


void MapInsert(Map* map, char* key, char* value)
{
    int modHash = MapHashPair(map, key);

    MapPair pair = {.key = (char*)key, .value = (char*)value};
    memcpy(&map->data[modHash], &pair, sizeof(MapPair));

    map->size++;
}

void MapInsertPair(Map* map, MapPair* pair)
{
    MapInsert(map, pair->key, pair->value);
}


void MapRemove(Map* map, char* key)
{
    // TODO This function does not work at all.

    int modHash = MapHashPair(map, key);
    MapPair* pair = &map->data[modHash];

    MapPrintPair(map, pair);

    if (pair) {
        /*printf("Value Found for key:%s -> %s\n", (char*)key, (char*)pair->value);*/
        free(pair->key);
        /*pair->key = NULL;*/
        free(pair->value);
        pair->value = NULL;

        memset(pair, 0, sizeof(MapPair) + 1);
    }
}


void MapDestroy(Map* map)
{
    free(map->data);
    map->data = NULL;

    free(map);
    map = NULL;
}


MapPair* MapCreatePair(const char* key, const char* val)
{
    MapPair* p = malloc(sizeof(MapPair));
    p->key   = malloc(sizeof(char) * strlen(key) + 1);
    strcpy(p->key, key);

    p->value   = malloc(sizeof(char) * strlen(val) + 1);
    strcpy(p->value, val);

    return p;
}


void MapDestroyPair(MapPair* pair)
{
    free(pair->key);
    pair->key = NULL;

    free(pair->value);
    pair->value = NULL;

    free(pair);
    pair= NULL;
}


void MapPrintValue(Map* map, char* key)
{
    MapPair* pair = MapGet(map, key);

    if (pair) {
        printf("key[%s]: %s\n", key, (char*)pair->value);
    }else
    {
        printf("key[%s]: NULL\n", key);
    }
}


void MapPrintPair(Map* map, MapPair* pair)
{
    MapPrintValue(map, pair->key);
}


void MapPrint(Map* map)
{
    for (int i = 0; i <= map->capacity -1; ++i)
    {
        MapPair* pair = &map->data[i];

        if (pair)
        {
            printf("%i: %s -> %s\n", i, (char*)pair->key, (char*)pair->value);
        }
    }
}



long
MapHash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

