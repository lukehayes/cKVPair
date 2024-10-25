#include "str.h"
#include "io.h"
#include <ctype.h>
#include <stdlib.h>
#include "print.h"
#include "parser.h"

#define DerefTypedValk

int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    char* currentChar = buffer->data;

    Value val[8];

    while(*currentChar)
    {
        // Parse Key
        currentChar = ParseValue(currentChar, &val[0]);

        currentChar = AdvancePtr(currentChar);
        // Parse Value
        currentChar = ParseValue(currentChar, &val[1]);


        printf("Key %s | Val %s \n", val[0].value, val[1].value);

        currentChar++;
    }



    /*printf("K:%s V:%s T:%lu\n", k.value, ((int*)v.value), atol(v.value) + 99 * 5 + 1);*/

    DestroyBufferData(buffer);

    //free(p->key);
    //free(p->value);
    //free(p);

    return 0;
}
