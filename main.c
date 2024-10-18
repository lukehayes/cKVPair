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


char* NextValidChar(char* c)
{
    char* ptr = c;

    while(!isalnum(ptr))
    {
        ptr++;
    }

    return ptr;
}


typedef struct Pair {
    char* key;
    char* value;
} Pair;


int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    int keyCounter = 1;
    char* keyBuffer;
    char* currentChar = buffer->data;
    int lineCount = 0;

    Pair* p  = malloc(sizeof(Pair));
    p->key   = malloc(sizeof(char) * keyCounter);
    p->value = malloc(sizeof(char) * keyCounter);

    while(*currentChar)
    {
        char* ptr = currentChar;
        static int memIndex = 1;

        if (isalpha(*ptr))  {

            char* nextChar = ptr++;

            p->key = realloc(p->key, sizeof(char) * memIndex);
            p->key[memIndex] = *currentChar;

            /*printf("Index %i %c\n", memIndex, p->key[memIndex] );*/
            memIndex++;

            if (!isalpha(*(ptr++))) {
                p->key[memIndex+1] = '\0';
            }
        }

        if (IsNewLine(currentChar)) 
        {
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
