#include "str.h"
#include "io.h"
#include <ctype.h>
#include <string.h>
#include "print.h"

typedef struct Value {
    void* value;
    size_t length;
} Value;

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
    /*printf("Reset Buffer...\n");*/
}

char* ParseValue(char* c, Value* property)
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

            buffer[memIndex - 1] = '\0';
            /*property[memIndex - 1] = '\0';*/

            
            if (iscntrl(buffer[memIndex])) 
            {
                memIndex--;
                
                PS("Control");


                property->value = malloc(sizeof(char) * memIndex);
                memset(property->value, '0', memIndex);
                memcpy(property->value, buffer, sizeof(char) * memIndex);
                property->length = memIndex;
                property->value[property->length] = '\0';
                /*property.value = '\0';*/
                /*property[memIndex - 1] = '\0';*/

            }else 
            {
                /*memset(property, '0', memIndex);*/
                /*memcpy(property, buffer, sizeof(char) * memIndex);*/
            }
            break;
        }
    }

    PB(buffer);
    ResetBuffer(buffer, memIndex);
    return ptr;
}

char* AdvancePtr(char* charPtr)
{
    while ( ispunct(*charPtr) != 0 || isspace(*charPtr) != 0)
    {
        /*printf("Moving to next valid char... %c\n", *charPtr);*/
        charPtr++;
    }

    return charPtr;
}



int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    char* currentChar = buffer->data;

    Value k;
    Value v;

    while(*currentChar)
    {
        // Parse Key
        currentChar = ParseValue(currentChar, &k);

        currentChar = AdvancePtr(currentChar);
        // Parse Value
        /*currentChar = ParseValue(currentChar, p.value);*/

        currentChar++;
    }


    printf("K:%s V:%s\n", (char*)k.value, v.value);

    free(k.value);

    DestroyBufferData(buffer);

    //free(p->key);
    //free(p->value);
    //free(p);

    return 0;
}
