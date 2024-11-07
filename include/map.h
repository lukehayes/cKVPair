#ifndef LDH_MAP_H
#define LDH_MAP_H

#include <stddef.h>

typedef struct Map Map;
typedef struct MapPair MapPair;

/**
 * Create a new instance of a Map.
 *
 * @param size_t intial_size.
 *
 * @return Map*.
 */
Map* MapCreate(size_t initial_size);

/**
 * Print a value using a key.
 *
 * @param Map* map.
 * @param char* key.
 *
 * @return void.
 */
void MapPrintPair(Map* map, char* key);


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
 * @return void.
 */
void MapInsert(Map* map, char* key, char* value);


/**
 * Insert a new value into the map using a MapPair reference inline:
 *
 * -----------------------------------------------
 * Should be used inline like this:
 *
 *      MapInsertPair(
 *          map,
 *          &(MapPair){.key = "Key", .value = "Value"}
 *      );
 * -----------------------------------------------
 *
 * @param Map* map.
 * @param MapPair* pair.
 *
 * @return void.
 */
void MapInsertPair(Map* map, MapPair* pair);


/**
 * Remove a value from the Map.
 *
 * @param Map* map.
 * @param const char* key.
 *
 * @return void.
 */
void MapRemove(Map* map, char* key);


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
 *
 * @return void.
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
