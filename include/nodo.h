#ifndef NODO_H
#define NODO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "utils.h"

typedef struct Nodo Node_t;

struct Nodo {
  void* value;
  DataType type;
  Node_t* next;
  Node_t* prev;
};

// Operazioni sul nodo

Node_t* create_nodo(char* value, DataType type);
void print_nodo(const Node_t* nodo, char* terminator);

// Operazioni tra nodi

double add(Node_t* a, Node_t* b);
double minus(Node_t* a, Node_t* b);
double multiply(Node_t* a, Node_t* b);
double divide(Node_t* a, Node_t* b);
char* concat(Node_t* a, Node_t* b);

#endif  // NODO_H
