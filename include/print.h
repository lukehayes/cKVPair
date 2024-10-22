#ifndef LDH_PRINT_H
#define LDH_PRINT_H


#include <stdio.h>


// Helper functions for printing.

void PC(char* c)
{
    printf("Char: %c \n", *c);
}

void PI(int i)
{
    printf("Int: %i \n", i);
}

void PB(char* buf)
{
    printf("Buf: %s \n", buf);
}

void PS(const char* s)
{
    printf("Str: %s\n", s);
}

#endif
