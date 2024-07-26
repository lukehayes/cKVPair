#include "kvpair.h"
#include "map.h"

int main()
{
    Map* map = ldh_MapCreate(2);

    ldh_MapInsert(map, "health");

    ldh_MapPrint(map);

    ldh_MapDestroy(map);

    return 0;
}
