#include "io.h"
#include "str.h"
#include "kvpair.h"
#include <string.h>


void resetMemory(char* mem, size_t size)
{
    for(int i = 0; i <= size - 1; i++)
    {
        mem[i] = 0;
    }
}

int main()
{
    struct BufferData* buffer = ReadFileIntoBuffer("data.toml");

    KVPair* p = ldh_KVPairCreate("...", "A Value");

    printf("Key: %s, %lu Value: %s %lu\n", p->key->text, p->key->length, p->value->text, p->value->length);

    ldh_KVPairDestroy(p);

    return 0;
}
