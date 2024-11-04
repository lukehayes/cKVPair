#include "map.h"


Map* MapCreate(size_t initial_size)
{
    Map* map = malloc(sizeof(Map));

    map->data     = malloc(sizeof(MapPair) * initial_size);
    map->capacity = initial_size;
    map->size     = 0;

    return map;
}

void MapInsert(Map* map, MapPair pair)
{
    MapPair* pairPtr = map->data;

    printf("Value Inserted: %s\n", (char*)pair.key.value);

    long hash = MapHash(pair.key.value);
    int modHash = hash % map->capacity;

    map->data[modHash] = pair;
    map->size++;

   pairPtr = &pair;
}

MapPair* MapGet(Map* map, char* key)
{
    printf("Trying to find val %s\n", key);

    long hash = MapHash(key);
    int modHash = hash % map->capacity;

    MapPair* pairs = &map->data[modHash];

    if (pairs->key.value) {
        /*printf("PTR %p --- Val %s\n", pairs, (char*)pairs->key.value);*/
        printf("String: '%s' found.\n", key);
    }else 
    {
        printf("String: '%s' Not found.\n", key);
    }

    return pairs;
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
