#ifndef LDH_MAP_H
#define LDH_MAP_H

#include "kvpair.h"
#include "parser.h"

typedef struct MapPair
{
    Value key;
    Value value;
} MapPair;

typedef struct Map
{
    MapPair* data;
    size_t capacity;
    size_t size;
} Map;

/**
 * Create a new instance of a Map.
 *
 * @param size_t intial_size.
 *
 * @return Map.
 */
Map* MapCreate(size_t initial_size);


void MapInsert(Map* map, MapPair pair);

MapPair* MapGet(Map* map, char* key);



/**
 * Destroy the Map and all of its data.
 *
 * @param Map* map.
 */
void MapDestroy(Map* map);

/**
 * A hashing function - all credit goes to: http://www.cse.yorku.ca/~oz/hash.html
 *
 * @param unsigned char* str    The string to be hash.
 *
 * @return long        The hashed value.
 */
long
MapHash(char *str);

#endif // !LDH_KVMAP_H
