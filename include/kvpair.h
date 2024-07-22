#ifndef LDH_KVPAIR_H
#define LDH_KVPAIR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define KV_BUFFER_SIZE 100

typedef struct KVPair
{
    char* key;
    char* value;

} KVPair;

KVPair* ldh_KVPairCreate(char* key, char* value)
{
    KVPair* p = malloc(sizeof(KVPair));

    p->key = malloc(sizeof(char) * strlen(key) + 1);
    p->value = malloc(sizeof(char) * strlen(value) + 1);

    strncpy(p->key, key, strlen(key) + 1);
    strncpy(p->value, value, strlen(value) + 1);

    p->key[strlen(key) + 1] = '\0';
    p->value[strlen(value) + 1] = '\0';

    printf("Key: %s, Value: %s \n", p->key, p->value);


    return p;
}

void ldh_KVPairDestroy(KVPair* pair)
{
    free(pair->key);
    free(pair->value);
    free(pair);
}

#endif // DEBUG
