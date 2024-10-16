#include "str.h"
#include "io.h"
#include <ctype.h>

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

    int bufSize = 30;
    int keyCounter = 0;
    char keyBuffer[bufSize];

    int valCounter = 0;
    char valBuffer[bufSize];

    char* c = buffer->data;
    int fileCounter = 0;
    int lineCount = 0;

    PB(buffer->data);

    printf("a Punct or Space? %i\n", NotPunctOrSpace("a"));
    printf("= Punct or Space? %i\n", NotPunctOrSpace("="));
    printf("space Punct or Space? %i\n", NotPunctOrSpace(" "));

    while(*c != EOF)
    {
        char* currentChar = c;

        // Get Key
        while (isalpha(*currentChar) && NotPunctOrSpace(currentChar))
        {
            keyBuffer[keyCounter] = *currentChar;

            keyCounter++;
            currentChar++;
        }

        c = currentChar;
        keyCounter = 0;



        // Get Value


        // Count Lines
        if(IsNewLine(c))
        {
            lineCount++;
            printf("Reached EndLine \n");
        }

        c++;
    }

    printf("Lines: %i \n", lineCount);

    DestroyBufferData(buffer);

    return 0;
}
