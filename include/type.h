#ifndef TYPE_H
#define TYPE_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum DataType { INT, DOUBLE, CHAR, STRING, UNKNOWN } DataType;

DataType type(char* value);
char* to_string_dataType(DataType type);

#endif  // TYPE_H
