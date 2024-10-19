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

void ResetBuffer(char* buffer, size_t size)
{
    for (int i = 0; i <= size -1 ; i++)
    {
        buffer[i] = 0;
    }
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

        while(isalpha(*ptr))
        {
            p->key[memIndex] = *ptr;
            ptr++;
            memIndex++;
        }


        while (!isalnum(*ptr))
        {
            PC(ptr);
            ptr++;
        }

        currentChar = ptr;
        memIndex = 0;


        memset(buffer, 'x', bufSize);


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
