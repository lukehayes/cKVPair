#include "io.h"
#include "parser.h"
#include "map.h"
#include "str.h"

int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    char* currentChar = buffer->data;

    Map* map = MapCreate(100);

    MapPair p1;
    p1.key.value   = ValueCreate("Hello");
    p1.value.value = NULL;

    printf("Value Pre Inserted: %s\n", (char*)p1.key.value);

    /*MapPair p2;*/
    /*p2.key.value   = ValueCreate("I am wealth");*/
    /*p2.value.value = NULL;*/

    /*MapInsert(map, p1);*/
    /*MapInsert(map, p2);*/

    /*MapPair* res = MapGet(map, "Hello");*/
    /*res = MapGet(map, "abc");*/


    /*free(p1.key.value);*/
    /*free(p2.key.value);*/

    MapDestroy(map);

    /**
    * Example API
    *
    * Map map = MapCreate("data.txt");
    *
    * int n = MapGetValue("speed") -> should return an integer like 100
    * bool MapHasValue("speed") -> check if a value exists inside the map
    *
    * MapDestroy(map); -> Destroy the map and all of its values.
    */

    /*Value val[8];*/

    /*while(*currentChar)*/
    /*{*/
        /*// Parse Key*/
        /*currentChar = ParseValue(currentChar, &val[0]);*/

        /*currentChar = AdvancePtr(currentChar);*/
        /*// Parse Value*/
        /*currentChar = ParseValue(currentChar, &val[1]);*/

        /*printf("K:%s      V:%lu \n", (char*)val[0].value, atol(val[1].value));*/

        /*free(val[0].value);*/
        /*free(val[1].value);*/

        /*currentChar++;*/
    /*}*/

    DestroyBufferData(buffer);

    //free(p->key);
    //free(p->value);
    //free(p);

    return 0;
}
