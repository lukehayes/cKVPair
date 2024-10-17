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

int main()
{
    BufferData* buffer = ReadFileIntoBuffer("data.txt");

    int bufSize = 31;
    int keyCounter = 0;
    char keyBuffer[bufSize];

    int valCounter = 0;
    char valBuffer[bufSize];

    char* c = buffer->data;
    int charCount = 0;
    int lineCount = 0;
    char* current = c;
    char* lookAhead = c + 1;
    char* charPtr;

    while(charCount < strlen(buffer->data) - 1)
    {
        current = c;
        lookAhead = c + 1;
        bool parsing = true;
        static int counter = 0;
    
        while(parsing)
        {
            keyBuffer[keyCounter] = *(lookAhead-1);
            keyCounter++;
            charPtr++;

            if (ispunct(*lookAhead) || isspace(*lookAhead)) 
            {
                parsing = false;
            }

            lookAhead++;
        }

        c++;
        charCount++;
    }
    
    printf("CHAR PTR %c", charPtr);
    PB(keyBuffer);

    printf("Lines: %i \n", lineCount);

    DestroyBufferData(buffer);

    return 0;
}
