#include "type.h"

/**
 * @brief Find a char into string
 *
 * @param str
 * @param c
 * @return int
 */
int __find_chr(const char* str, char c) {
  do {
    if (*str == c) return 1;
  } while (*str++);
  return 0;
}

/**
 * @brief Determines what type is input
 *
 * @param value input with type unknown
 * @return DataType the data type of value
 */
DataType type(char* value) {
  char* input = (char*)value;
  int is_int = 0, is_double = 0, is_char = 0, is_string = 0;
  int check_point = __find_chr(input, '.');

  // check if the variable is an integer
  for (int i = 0; input[i] != '\0'; i++) {
    if (isdigit(input[i]) || check_point)
      is_int = 1;
    else {
      is_int = 0;
      break;
    }
  }

  // check if it's a float or double
  if (is_int && check_point) is_double = 1;

  // check if it's a char
  if (strlen(input) == 1) is_char = 1;

  // check if  it's a string
  if (strlen(input) > 1) is_string = 1;

  if (is_double) return DOUBLE;
  if (is_int) return INT;
  if (is_char) return CHAR;
  if (is_string) return STRING;

  return UNKNOWN;
}

/**
 * @brief Convert DataType into string. If the datatype is not recognized,
 * returns "Unknown"
 *
 * @param type
 * @return char*
 */
char* to_string_dataType(DataType type) {
  char* result;
  switch (type) {
    case INT:
      memcpy(result = (char*)malloc(sizeof("INT")), "INT", sizeof("INT"));
      break;
    case DOUBLE:
      memcpy(result = (char*)malloc(sizeof("DOUBLE")), "DOUBLE",
             sizeof("DOUBLE"));
      break;
    case CHAR:
      memcpy(result = (char*)malloc(sizeof("CHAR")), "CHAR", sizeof("CHAR"));
      break;
    case STRING:
      memcpy(result = (char*)malloc(sizeof("STRING")), "STRING",
             sizeof("STRING"));
      break;
    default:
      memcpy(result = (char*)malloc(sizeof("UNKNOWN")), "UNKNOWN",
             sizeof("UNKNOWN"));
      break;
  }
}
