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


/**
 * The parser uses an internal temporary buffer, this function resets it.
 *
 * @param char* buffer.
 * @param size_t size.
 */
void ResetBuffer(char* buffer, size_t size)
{
    memset(buffer, '0', size);
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
            val->value = (char*)malloc(sizeof(char) * memIndex);
            memset(val->value, '0', memIndex);
            memcpy(val->value, buffer, sizeof(char) * memIndex);

            val->length = memIndex;
            char* k = (char*)val->value;

            k[val->length] = '\0';

            break;

        case INT:
            val->value = (int*)malloc(sizeof(int) * memIndex);
            memset(val->value, '0', memIndex);
            memcpy(val->value, buffer, sizeof(int) * memIndex);

            val->length = memIndex;
            int* v = (int*)val->value;

            v[val->length] = '\0';

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
    int bufSize = 10;
    char buffer[bufSize];
    int memIndex = 0;

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
            // Increased memIndex by one to make space for NULL char.
            memIndex++;

            buffer[memIndex - 1] = '\0';

            ParseValueType(val, memIndex, buffer);

            break;
        }
    }

    ResetBuffer(buffer, memIndex);
    return ptr;
}

#endif // !LDH_PARSER_H
