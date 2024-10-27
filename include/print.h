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

void PF(float f)
{
    printf("Float: %f \n", f);
}

void PD(double d)
{
    printf("Double: %f \n", d);
}

void PB(char* buf)
{
    printf("Buf: %s \n", buf);
}

void PS(const char* s)
{
    printf("Str: %s\n", s);
}

void PSI(const char* s, int i)
{
    printf("Str: %s Int: %i\n", s, i);
}

void PSS(const char* s, const char* ss)
{
    printf("Str: %s Str: %s\n", s, ss);
}

void PSC(const char* s, const char c)
{
    printf("Str: %s Char: %c\n", s, c);
}

#endif
