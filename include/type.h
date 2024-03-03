#ifndef TYPE_H
#define TYPE_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum DataType { INT = 1, DOUBLE, CHAR, STRING, TUPLA, UNKNOWN } DataType;

#include "tupla.h"

#define TYPE(x) _Generic(x, \
    int: INT,               \
    double: DOUBLE,         \
    char: CHAR,             \
    char*: STRING,          \
    Tupla_t: TUPLA,          \
    Tupla_t*: TUPLA,       \
    default:0)


char* to_string_dataType(DataType type);

void* save_value(void* new_value, DataType type);

void print_value(void* value, DataType type);

#endif  // TYPE_H
