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
MapPair* MapCreatePair(const char* key, const char* val);

/**
 * Destroy a MapPair value.
 *
 * @param MapPair* pair.
 *
 * @return void.
 */
void MapDestroyPair(MapPair* pair);

/**
 * Print a value using a key.
 *
 * @param Map* map.
 * @param char* key.
 *
 * @return void.
 */
void MapPrintValue(Map* map, char* key);

/**
 * Print a value using a MapPair.
 *
 * @param Map* map.
 * @param MapPair* pair.
 *
 * @return void.
 */
void MapPrintPair(Map* map, MapPair* pair);

/**
 * Print every entry of the map.
 *
 * @param Map* map.
 *
 * @return void.
 */
void MapPrint(Map* map);

/**
 * Insert a new value into the map.
 *
 * @param Map* map.
 * @param const char* key.
 * @param const char* value.
 *
 * @return MapPair*.
 */
MapPair* MapInsert(Map* map, const char* key, const char* value);

/**
 * Remove a value from the Map.
 *
 * @param Map* map.
 * @param const char* key.
 *
 * @return MapPair*.
 */
void MapRemove(Map* map, const char* key);

/**
 * Retrieve a value from the map.
 *
 * @param Map* map.
 * @param const char* key.
 *
 * @return MapPair*.
 */
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
