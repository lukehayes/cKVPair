#ifndef LDH_MAP_H
#define LDH_MAP_H

#include "kvpair.h"

typedef struct Map
{
    KVPair** list;
    size_t capacity;
    size_t size;
} Map;


/**
 * Create a Map instance.
 *
 * @param size_t capacity    The initial size of the map.
 *
 * @return Map*
 */
Map* ldh_MapCreate(size_t capacity);

/**
 * Free the Map from memory.
 *
 * @param Map* map    The pointer to be freed.
 */
void ldh_MapDestroy(Map* map);

/**
 * Insert a value into the map.
 *
 * @param Map* map         The map to be inserted into.
 * @param const char* val    The value to be added.
 *
 * @return bool    True is value was inserted, false otherwise.
 */
bool ldh_MapInsert(Map* map, char* val);

/**
 * Insert a value into the map.
 *
 * @param Map* map         The map to be inserted into.
 * @param const char* value    The value to be added.
 *
 * @return bool    True is value was inserted, false otherwise.
 */
bool ldh_MapRemove(Map* map, char* value);

/**
 * Retrieve a value from the map.
 *
 * @param Map* map         The map to be inserted into.
 * @param const char* val    The value to be get.
 *
 * @return bool    True is value was inserted, false otherwise.
 */
KVPair* ldh_MapGetVal(Map* map, char* value);


/**
 * Pretty print a Map.
 *
 * @param Map* map         The map to be printed.
 */
void ldh_MapPrint(Map* map);

/**
 * A hashing function - all credit goes to: http://www.cse.yorku.ca/~oz/hash.html
 *
 * @param unsigned char* str    The string to be hash.
 *
 * @return long        The hashed value.
 */
long
ldh_Hash(char *str);

#endif // !LDH_KVMAP_H
