#include "io.h"
#include "parser.h"
#include "map.h"
#include "str.h"

int main()
{
    /*BufferData* buffer = ReadFileIntoBuffer("data.txt");*/

    /*char* currentChar = buffer->data;*/

    Map* map = MapCreate(20);

    MapPair* p1 = MapInsert(map, "luck", "333");
    MapPair* p2 = MapInsert(map, "wealth", "so much wealth!");
    MapPair* p3 = MapInsert(map, "abc", "letters");

    MapPair* a = MapGet(map, "luck");
    MapPair* b = MapGet(map, "abc"); // This is NULL so will segfault.
    MapPair* c = MapGet(map, "wealth");

    /*MapPrintValue(map, "luck");*/
    /*MapPrintValue(map, "abc");*/
    /*MapPrintValue(map, "wealth");*/
    MapPrintPair(map, a);
    MapPrintPair(map, b);
    MapPrintPair(map, c);

    MapDestroyValue(p1);
    MapDestroyValue(p2);
    MapDestroy(map);


    /*MapPair p2;*/
    /*p2.key.value   = ValueCreate("I am wealth");*/
    /*p2.value.value = NULL;*/

    /*MapInsert(map, p1);*/
    /*MapInsert(map, p2);*/

    /*MapPair* res = MapGet(map, "Hello");*/
    /*res = MapGet(map, "abc");*/


    /*free(p1.key.value);*/
    /*free(p2.key.value);*/

    /*MapDestroy(map);*/

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

    /*DestroyBufferData(buffer);*/

    //free(p->key);
    //free(p->value);
    //free(p);

    return 0;
}
