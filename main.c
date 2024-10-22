#include "str.h"
#include "io.h"
#include <ctype.h>
#include <string.h>
#include "print.h"

bool IsNewLine(const char* c)
{
    return *c == '\n';
}

void NewLine()
{
    printf("\n");
}


bool IsValidChar(const char* c)
{
    return (!ispunct(*c) || !isspace(*c)) ? 1 : 0;
}

char* NextValidChar(char* c)
{
    char* ptr = c;

    while(!isalnum(ptr))
    {
        ptr++;
    }

    return ptr;
}

void ResetBuffer(char* buffer, size_t size)
{
    memset(buffer, '0', size);
    printf("Reset Buffer...\n");
}

char* ParseValue(char* c, char* property)
{

    char* ptr = c;


    int bufSize = 100;
    char buffer[bufSize];
    int memIndex = 0;

    while(isalnum(*ptr))
    {
        buffer[memIndex] = *ptr;
        memIndex++;
        ptr++;

        // Pointer already advanced so no need to ptr++ it.
        // It checks the next value in the list.
        // So add the NULL char.
        if (isspace(*ptr)) 
        {
            // Increased memIndex by one to make space for NULL char.
            memIndex++;

            buffer[memIndex] = '\0';
            property[memIndex] = '\0';
            
            if (iscntrl(buffer[memIndex])) 
            {
                memIndex--;
                memset(property, '0', memIndex);
                memcpy(property, buffer, sizeof(char) * (memIndex));
            }else 
            {
                memset(property, '0', memIndex);
                memcpy(property, buffer, sizeof(char) * memIndex);
            }


            break;
        }
    }

    PB(buffer);
    ResetBuffer(buffer, memIndex);
    return ptr;
}

void AdvancePtr(char* charPtr)
{

}

typedef struct Pair {
    char key[30];
    char value[30];
} Pair;


int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    char* currentChar = buffer->data;

    Pair p;

    while(*currentChar)
    {
        // Parse Key
        currentChar = ParseValue(currentChar, p.key);
        while ( ispunct(*currentChar) != 0 || isspace(*currentChar) != 0) 
        {
            printf("Moving to next valid char... %c\n", *currentChar);
            currentChar++;
        }

        // Parse Value
        currentChar = ParseValue(currentChar, p.value);

        currentChar++;
    }


    printf("K:%s V:%s\n", p.key, p.value);

    DestroyBufferData(buffer);

    //free(p->key);
    //free(p->value);
    //free(p);

    return 0;
}
