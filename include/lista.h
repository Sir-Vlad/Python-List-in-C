#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

#include "nodo.h"

typedef struct lista Lista_t;

struct lista {
  // field list
  Node_t* head;
  Node_t* tail;
  size_t size;
  // function
  // size_t (*get_size)(Lista_t* self);
  // void (*toString)(Lista_t* self);
};

Lista_t* create_list();

void insert_nodo(Lista_t* head, void* value, DataType type);
void push(Lista_t* self, void* value, DataType type);
void pop(Lista_t* self);

bool delete_node(Lista_t* head, Node_t* node);

Node_t* find_value(const Lista_t* head, const void* value, DataType type);
void sort_list(Lista_t* lista);
bool is_empty(const Lista_t* head);
size_t get_size(Lista_t* self);

void print_list(Lista_t* self);
void print_list_inverse(Lista_t* self);
#endif  // LISTA_H
