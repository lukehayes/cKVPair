#ifndef LDH_PARSER_H
#define LDH_PARSER_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "print.h"

typedef enum ValueType
{
    STRING,
    INT

} ValueType;

typedef struct Value {
    void* value;
    size_t length;
    ValueType type;
} Value;


Value* ValueCreate(char* s)
{

    printf("%s\n",s);
    size_t length = strlen(s) + 1;
    Value* v =  malloc(sizeof(Value));

    v->value = malloc(sizeof(char) * length);
    strcpy(v->value, s);

    v->length = length;
    v->type   = STRING;

    return v;
}



/**
* Parse the a single key or value from a string.
*
* @param Value* val.
* @param sizt_t memIndex.
* @param char*  buffer.
*/
void ParseValueType(Value* val, int memIndex, char* buffer)
{
    // Increased memIndex by one to make space for NULL char.
    //memIndex++;
    //buffer[memIndex - 1] = '\0';
    memIndex++;
    val->length = memIndex;

    // Add basic type information about the value here.
    // The type can either be STRING or INT at the moment/
    if (isalpha(*buffer))
    {
        val->type = STRING;
    }

    if (isdigit(*buffer))
    {
        val->type = INT;
    }

    // Allocate the space for the value here and add it to the buffer
    switch (val->type) {
        case STRING:
            val->value = (char*)malloc(sizeof(char) * val->length);
            memset(val->value, '\0', val->length);
            memcpy(val->value, buffer, sizeof(char) * val->length-1);
            break;

        case INT:
            val->length = memIndex;
            val->value = (int*)malloc(sizeof(int) * val->length);
            memset(val->value, '\0', val->length);
            memcpy(val->value, buffer, sizeof(int) * val->length-1);

            break;
        default:
    }
}

/**
 * Advace the current pointer to the next valid char.
 * @param char* charPtr.
 * @return char*
 */
char* AdvancePtr(char* charPtr)
{
    while ( ispunct(*charPtr) != 0 || isspace(*charPtr) != 0)
    {
        /*printf("Moving to next valid char... %c\n", *charPtr);*/
        charPtr++;
    }

    return charPtr;
}

/**
* Parse a string for key value pairs.
*
* @param char* c.
* @param Value* val.
*/
char* ParseValue(char* ptr, Value* val)
{
    int  memIndex = 0;
    int  bufSize  = 20;
    char buffer[bufSize];

    while(isalnum(*ptr))
    {
        buffer[memIndex] = *ptr;
        memIndex++;
        ptr++;

        // Pointer already advanced so no need to ptr++ it.
        //
        // If we have reached a space then we have moved past
        // a valid value. Now we add the data parsed up
        // until this point into a buffer.
        if (isspace(*ptr))
        {
            ParseValueType(val, memIndex, buffer);
            break;
        }
    }

    //ResetBuffer(buffer, memIndex);
    return ptr;
}

#endif // !LDH_PARSER_H
