#ifndef LDH_MAP_H
#define LDH_MAP_H

#include "kvpair.h"
#include "parser.h"

typedef struct MapPair
{
    void* key;
    void* value;
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

/**
 * Create a single value to be inserted into the map.
 *
 * @param const char* key.
 * @param const char* value.
 *
 * @return MapPair*.
 */
MapPair* MapCreateValue(const char* key, const char* val);

/**
 * Destroy a MapPair value.
 *
 * @param MapPair* pair.
 *
 * @return void.
 */
void MapDestroyValue(MapPair* pair);

void MapPrintValue(Map* map, char* key);

void MapPrintPair(Map* map, MapPair* pair);

/**
 * Insert a new value into the map.
 *
 * @param Map* map.
 * @param const char* key.
 * @param const char* value.
 *
 * @return void.
 */
MapPair* MapInsert(Map* map, const char* key, const char* value);

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
