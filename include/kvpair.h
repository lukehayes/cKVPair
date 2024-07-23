#ifndef LDH_KVPAIR_H
#define LDH_KVPAIR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

#define KV_BUFFER_SIZE 100

typedef struct KVPair
{
    Str* key;
    Str* value;


} KVPair;

KVPair* ldh_KVPairCreate(char* key, char* value)
{
    KVPair* p = malloc(sizeof(KVPair));

    p->key   = ldh_StrCreate(key);
    p->value = ldh_StrCreate(value);

    printf("Key: %s, Value: %s \n", p->key->text, p->key->text);

    return p;
}

void ldh_KVPairDestroy(KVPair* pair)
{
    ldh_StrDestroy(pair->key);
    ldh_StrDestroy(pair->value);
    free(pair);
}

#endif // DEBUG
