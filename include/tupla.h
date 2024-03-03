//
// Created by maty on 26/02/24.
//

#ifndef TUPLA_H
#define TUPLA_H

#include <stdio.h>

#include "type.h"

typedef struct element {
    void* value;
    DataType type;
} Element_t;

typedef struct tupla {
    const Element_t** values;
    size_t size;
} Tupla_t;


Tupla_t* create_tupla();

void insert_element(Tupla_t* tupla, void* value, DataType type);

void delete_tupla(Tupla_t** tupla);

void print_tupla(Tupla_t* tupla, char* terminator);

__attribute__((unused)) void print_type_tupla(Tupla_t* tupla);

#endif //TUPLA_H
