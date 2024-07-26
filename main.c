#include "kvpair.h"
#include "kvmap.h"

int main()
{
    KVMap* map = ldh_KVMapCreate(10);

    ldh_KVMapInsert(map, "I");
    ldh_KVMapInsert(map, "Am");
    ldh_KVMapInsert(map, "Excellent");

    KVPair* p = ldh_KVMapGetVal(map, "Am");

    ldh_KVMapRemove(map, "I");
    ldh_KVMapRemove(map, "Am");
    ldh_KVMapRemove(map, "Excellent");

    ldh_KVPairPrint(*p);


    //ldh_KVPairPrint(*ldh_KVMapGetVal(map, "Excellent"));

    ldh_KVMapPrint(map);

    ldh_KVMapDestroy(map);

    return 0;
}
