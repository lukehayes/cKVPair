#include "map.h"
#include <string.h>

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

MapPair* MapCreateValue(const char* key, const char* val)
{
    MapPair* p = malloc(sizeof(MapPair));
    p->key   = malloc(sizeof(char) * strlen(key) + 1);
    strcpy(p->key, key);

    p->value   = malloc(sizeof(char) * strlen(val) + 1);
    strcpy(p->value, val);

    return p;
}

void MapDestroyValue(MapPair* pair)
{
    free(pair->key);
    free(pair->value);
    free(pair);
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


MapPair* MapInsert(Map* map, const char* key, const char* value)
{
    MapPair* pair = MapCreateValue(key, value);

    int modHash = MapHashPair(map, key);

    MapPair* data = &map->data[modHash];

    printf("Insert ModHash %i\n", modHash);

    memmove(data,pair, sizeof(MapPair));


    /*map->data[modHash] = *data;*/
    map->size++;

    return pair;

}

MapPair* MapGet(Map* map, char* key)
{
    int modHash = MapHashPair(map, key);
    MapPair* pair = &map->data[modHash];
    printf("Get ModHash %i\n", modHash);

    /*printf("Data at modHash:%i,key %s\n", modHash, (char*)map->data[modHash].key);*/
    /*printf("Data at modHash:%i, val %s\n", modHash, (char*)map->data[modHash].value);*/
    /*printf("\n");*/

    return pair->key ? pair : NULL;
}

void MapDestroy(Map* map)
{
    free(map->data);
    map->data = NULL;

    free(map);
    map = NULL;
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

