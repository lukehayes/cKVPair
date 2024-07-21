#include "io.h"

#include <ctype.h>
#include <string.h>

typedef struct KeyValPair
{
    char key[100];
    char value[100];

} KeyValPair;

typedef struct KeyValList
{
    KeyValPair pairs[10];
    size_t size;
}KeyValList;

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

    int charCount = 0;
    int seperatorCount = 0;
    int beforeEquals = true;


    KeyValList list;
    list.size = 0;

    // TODO This is working but needs a huge refactor!

    while(charCount <= buffer->size)
    {
        char* currentChar = buffer->data + charCount;

        KeyValPair p;
        p.key[99] = '\0';
        p.value[99] = '\0';

        if(*currentChar == '=')
        {
            beforeEquals = false;
        }


        if(beforeEquals)
        {
            if(*currentChar != '=')
            {
                strncat(p.key, currentChar, 1);
            }

        } else 
        {
            if(*currentChar != '=')
            {
                strncat(p.value, currentChar, 1);
            }
        }

        if(*currentChar == '\n')
        {

            list.pairs[list.size] = p;
            list.size += 1;
            beforeEquals = true;
            resetMemory(p.key, 100);
            resetMemory(p.value, 100);
        }
        charCount++;
    }

    for(int i = 0; i <= list.size -1; i++)
    {
        KeyValPair p = list.pairs[i];
        printf("%s = %s", p.key, p.value);
    }

    DestroyBufferData(buffer);

    return 0;
}
