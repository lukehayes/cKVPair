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
 * A hashing function - all credit goes to: http://www.cse.yorku.ca/~oz/hash.html
 *
 * @param unsigned char* str    The string to be hash.
 *
 * @return unsigned long        The hashed value.
 */
unsigned long
ldh_Hash(unsigned char *str);

#endif // !LDH_KVMAP_H
