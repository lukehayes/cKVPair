#include "str.h"
#include "io.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool IsNewLine(const char* c)
{
    return *c == '\n';
}

void NewLine()
{
    printf("\n");
}

void PC(char* c)
{
    printf("Char: %c \n", *c);
}

void PB(char* buf)
{
    printf("Buf: %s \n", buf);
}

bool NotPunctOrSpace(const char* c)
{
    return (!ispunct(*c) || !isspace(*c)) ? 1 : 0;
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
    printf("Reseting...\n");
    memset(buffer, '0', size);

    /*for (int i = 0; i <= size -1 ; i++)*/
    /*{*/
        /*buffer[i] = 0;*/
    /*}*/
}


typedef struct Pair {
    char* key;
    char* value;
} Pair;


int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    int bufSize = 100;
    int keyCounter = 1;
    char* keyBuffer;
    char* currentChar = buffer->data;
    int lineCount = 0;

    Pair* p  = malloc(sizeof(Pair));
    p->key   = malloc(sizeof(char) * bufSize);
    p->value = malloc(sizeof(char) * bufSize);

    while(*currentChar)
    {
        char* ptr = currentChar;
        static int memIndex = 0;
        char buffer[bufSize];


        if (isalnum(*ptr))
        {
            printf("Parsing key...\n");

            // Parse Key
            // Key can only be alpha so no need to check for alpha nums
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
                    buffer[memIndex] = '\0';
                    memcpy(p->key, buffer, sizeof(char) * memIndex);
                    break;
                }
            }

            while ( ispunct(*ptr) != 0 || isspace(*ptr) != 0) 
            {
                printf("Moving to next valid char... %c\n", *ptr);
                ptr++;
            }

            printf("Setting current char to %c\n", *ptr);

            ResetBuffer(buffer, bufSize);
            memIndex = 0;


            // Parse Value
            printf("Parsing key...\n");

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
                    buffer[memIndex] = '\0';
                    memcpy(p->value, buffer, sizeof(char) * memIndex);
                    break;
                }
            }
            
            // Set the current char to 1 before the valid one.
            currentChar = ptr;
        }


        printf("NOW CURR CHAR to %c\n", *currentChar);
        printf("NOW  PTR to %c\n", *ptr );


        // Done finding key, now move onto value.

        if (IsNewLine(currentChar)) {
            lineCount++;
        }

        currentChar++;
    }


    printf("K:%s V:%s \n", p->key, p->value);

    printf("Lines: %i \n", lineCount);
    DestroyBufferData(buffer);

    free(p->key);
    free(p->value);
    free(p);

    return 0;
}
