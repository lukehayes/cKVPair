#ifndef LDH_KVPAIR_H
#define LDH_KVPAIR_H

#include <stdlib.h>
#include <stdio.h>
#include "str.h"

#define KV_BUFFER_SIZE 100

typedef struct KVPair
{
    Str* key;
    Str* value;

} KVPair;

/**
 * Create a new Key/Value pair.
 *
 * @param char* key    The key of the pair.
 * @param char* key    The value of the pair.
 *
 * @return KVPair* p   A new Key/Value pair.
 *
 **/
KVPair* ldh_KVPairCreate(char* key, char* value)
{
    KVPair* p = malloc(sizeof(KVPair));

    p->key   = ldh_StrCreate(key);
    p->value = ldh_StrCreate(value);

    return p;
}

/**
 * Print a Key/Value pair to stdout.
 *
 * @param KVPair* p   The key/value pair to print.
 **/
void ldh_KVPairPrint(KVPair p)
{
    printf("Pair - Key:%s Value:%s\n", p.key->text, p.value->text);
}

/**
 * Destroy a Key/Value pair.
 *
 * @param KVPair* p    A new Key/Value pair.
 **/
void ldh_KVPairDestroy(KVPair* pair)
{
    ldh_StrDestroy(pair->key);
    ldh_StrDestroy(pair->value);
    free(pair);
}

#endif // DEBUG
