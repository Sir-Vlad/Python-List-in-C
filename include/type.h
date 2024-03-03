#ifndef TYPE_H
#define TYPE_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum DataType { INT = 1, DOUBLE, CHAR, STRING, UNKNOWN } DataType;

#define TYPE(x) _Generic(x, \
    int: INT,               \
    double: DOUBLE,         \
    char: CHAR,             \
    char*: STRING,            \
    default:0)

char* to_string_dataType(DataType type);

#endif  // TYPE_H
