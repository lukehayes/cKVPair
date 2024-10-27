#include "io.h"
#include "parser.h"

int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    char* currentChar = buffer->data;

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

    Value val[8];

    while(*currentChar)
    {
        // Parse Key
        currentChar = ParseValue(currentChar, &val[0]);

        currentChar = AdvancePtr(currentChar);
        // Parse Value
        currentChar = ParseValue(currentChar, &val[1]);

        printf("K:%s      V:%lu \n", (char*)val[0].value, atol(val[1].value));

        currentChar++;
    }

    DestroyBufferData(buffer);

    //free(p->key);
    //free(p->value);
    //free(p);

    return 0;
}
