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

    Pair* p = malloc(sizeof(Pair));
    p->key = malloc(sizeof(char) * keyCounter);
    p->value = malloc(sizeof(char) * keyCounter);


    while(*currentChar)
    {
        char* nextChar = currentChar + 1;

        if(isspace(*nextChar) || ispunct(*nextChar)) {
            p->key[keyCounter] = *currentChar;
            p->key[keyCounter + 1] = '\0';
            break;
        }else {
            p->key = realloc(p->key, sizeof(char) * keyCounter + 1);
            p->key[keyCounter] = *currentChar;
            keyCounter++;
        }

        while(!isalnum(*currentChar))
        {
            PC(currentChar);
            currentChar++;
        }

        if (IsNewLine(currentChar)){
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
