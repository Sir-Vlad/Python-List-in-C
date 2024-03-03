#include "type.h"

/**
 * @brief Find a char into string
 *
 * @param str
 * @param c
 * @return int
 */
int find_chr(const char* str, char c) {
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
__attribute__((deprecated, unused)) DataType type(char* value) {
    char* input = (char*) value;
    int is_int = 0, is_double = 0, is_char = 0, is_string = 0;
    int check_point = find_chr(input, '.');

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
            memcpy(result = (char*) malloc(sizeof("INT")), "INT", sizeof("INT"));
            break;
        case DOUBLE:
            memcpy(result = (char*) malloc(sizeof("DOUBLE")), "DOUBLE", sizeof("DOUBLE"));
            break;
        case CHAR:
            memcpy(result = (char*) malloc(sizeof("CHAR")), "CHAR", sizeof("CHAR"));
            break;
        case STRING:
            memcpy(result = (char*) malloc(sizeof("STRING")), "STRING", sizeof("STRING"));
            break;
        case TUPLA:
            memcpy(result = (char*) malloc(sizeof("TUPLA")), "TUPLA", sizeof("TUPLA"));
            break;
        default:
            memcpy(result = (char*) malloc(sizeof("UNKNOWN")), "UNKNOWN", sizeof("UNKNOWN"));
            break;
    }
    return result;
}

/**
 * @brief
 * @param value
 * @param new_value
 * @param type
 * @return il valore allocato con tipo giusto
 */
void* save_value(void* new_value, DataType type) {
    if (new_value == NULL){
        return NULL;
    }
    void* value;
    char* endptr;
    switch (type) {
        case INT:
            value = (int*) malloc(sizeof(int));
            *(int*) value = (int) strtol(new_value, &endptr, 10);
            if (value == endptr) {
                return NULL;
            }
            break;
        case DOUBLE:
            value = (double*) malloc(sizeof(double));
            *(double*) value = strtof(new_value, &endptr);
            if (value == endptr) {
                return NULL;
            }
            break;
        case CHAR:
            value = (char*) malloc(sizeof(char));
            *(char*) value = *(char*) (new_value);
            break;
        case STRING:
            value = (char*) malloc(sizeof(char) * strlen((char*) new_value) + 1);
            memcpy(value, new_value, strlen((char*) new_value) + 1);
            break;
        case TUPLA:
            value = (Tupla_t*) malloc(sizeof(Tupla_t));
            *(Tupla_t*) value = *(Tupla_t*) (new_value);
            break;
        default:
            return NULL;
    }
    return value;
}

void print_value(void* value, DataType type) {
    switch (type) {
        case INT:
            printf("%d", *(int*) value);
            break;
        case DOUBLE:
            printf("%g", *(double*) (value));
            break;
        case CHAR:
            printf("%c", *(char*) (value));
            break;
        case STRING:
            printf("%s", (char*) (value));
            break;
        case TUPLA:
            print_tupla(value, "");
        default:
            break;
    }
}
