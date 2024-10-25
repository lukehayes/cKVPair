#ifndef LDH_PARSER_H
#define LDH_PARSER_H

#include <stdlib.h>

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


#endif // !LDH_PARSER_H
