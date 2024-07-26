#ifndef LDH_KVMAP_H
#define LDH_KVMAP_H

#include "kvpair.h"

typedef struct KVMap
{
    KVPair** list;
    size_t capacity;
    size_t size;
} KVMap;


/**
 * Create a KVMap instance.
 *
 * @param size_t capacity    The initial size of the map.
 *
 * @return KVMap*
 */
KVMap* ldh_KVMapCreate(size_t capacity);

/**
 * Free the KVMap from memory.
 *
 * @param KVMap* map    The pointer to be freed.
 */
void ldh_KVMapDestroy(KVMap* map);

/**
 * Insert a value into the map.
 *
 * @param KVMap* map         The map to be inserted into.
 * @param const char* val    The value to be added.
 *
 * @return bool    True is value was inserted, false otherwise.
 */
bool ldh_KVMapInsert(KVMap* map, char* val);

/**
 * Insert a value into the map.
 *
 * @param KVMap* map         The map to be inserted into.
 * @param const char* value    The value to be added.
 *
 * @return bool    True is value was inserted, false otherwise.
 */
bool ldh_KVMapRemove(KVMap* map, char* value);

/**
 * Retrieve a value from the map.
 *
 * @param KVMap* map         The map to be inserted into.
 * @param const char* val    The value to be get.
 *
 * @return bool    True is value was inserted, false otherwise.
 */
KVPair* ldh_KVMapGetVal(KVMap* map, char* value);


/**
 * Pretty print a KVMap.
 *
 * @param KVMap* map         The map to be printed.
 */
void ldh_KVMapPrint(KVMap* map);

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
