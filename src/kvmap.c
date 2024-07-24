#include "kvmap.h"

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

unsigned long
ldh_Hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
