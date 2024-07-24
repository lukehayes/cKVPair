#include "io.h"
#include "kvpair.h"
#include "kvmap.h"
#include <stdio.h>


int main()
{
    KVPair* p = ldh_KVPairCreate("Hello", "A Value");

    KVMap* map = ldh_KVMapCreate(10);

    ldh_KVMapDestroy(map);
    ldh_KVPairDestroy(p);

    return 0;
}
