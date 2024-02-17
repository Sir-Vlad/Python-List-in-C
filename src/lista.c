#include "lista.h"

#include "utils.h"

/**
 * @brief Create a list object
 *
 * @return Lista_t*
 */
Lista_t* create_list() {
  Lista_t* lista = (Lista_t*)malloc(sizeof(Lista_t));
  if (lista == NULL) {
    perror("Errore di allocazione della lista");
  }
  lista->head = NULL;
  lista->size = 0;
  // lista->get_size = &get_size;
  // lista->toString = &print_list;
  return lista;
}

/**
 * @brief Insert a new nodo in the list
 *
 * @param head  The address of the first element of the list
 * @param value content of the node to insert
 * @param type  data type of the value
 */
void insert_nodo(Lista_t* head, void* value, DataType type) {
  Node_t* nodo = create_nodo(value, type);
  if (head->head == NULL) {
    head->head = nodo;
    head->tail = nodo;
  } else {
    Node_t* tmp = head->head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = nodo;
    nodo->prev = tmp;
    head->tail = nodo;
  }
  head->size++;
}

/**
 * @brief Converte una lista in un array
 *
 * @param lista
 * @return Node_t**
 */
Node_t** convertListToArr(Lista_t* lista) {
  int size = lista->size;
  Node_t** arr = (Node_t**)malloc(size * sizeof(Node_t*));
  Node_t* tmp = lista->head;
  for (size_t i = 0; i < size; i++) {
    arr[i] = tmp;
    tmp = tmp->next;
  }
  return arr;
}

/**
 * @brief Ordina un'array
 *
 * @param arr
 * @param size
 */
void sortArr(Node_t** arr, int size) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = i + 1; j < size; j++) {
      if (arr[i]->type == INT && arr[j]->type == INT) {
        if (*(int*)arr[i]->value > *(int*)arr[j]->value) {
          Node_t* tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        };
      } else if (arr[i]->type == DOUBLE && arr[j]->type == DOUBLE) {
        if (*(double*)arr[i]->value > *(double*)arr[j]->value) {
          Node_t* tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      } else if (arr[i]->type == DOUBLE && arr[j]->type == INT) {
        if (*(double*)arr[i]->value > *(int*)arr[j]->value) {
          Node_t* tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      } else if (arr[i]->type == INT && arr[j]->type == DOUBLE) {
        if (*(int*)arr[i]->value > *(double*)arr[j]->value) {
          Node_t* tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
  }
}

/**
 * @brief Converte un array in una lista
 *
 * @param lista
 * @param arr
 */
void rebuildList(Lista_t* lista, Node_t** arr) {
  Node_t* newHead = arr[0];
  newHead->prev = NULL;
  newHead->next = arr[1];

  Node_t* current = newHead;
  for (size_t i = 0; i < lista->size - 1; i++) {
    current->next = arr[i + 1];
    if (i != 0) current->prev = arr[i - 1];
    current = current->next;
  }
  current->next = NULL;
  current->prev = arr[lista->size - 2];

  lista->head = newHead;
  lista->tail = arr[lista->size - 1];
}

/**
 * @brief Sorts the list in lexicographic order using a custom comparison
 * function.
 *
 * @param head
 */
void sort_list(Lista_t* lista) {
  Node_t** arr = convertListToArr(lista);
  sortArr(arr, lista->size);
  rebuildList(lista, arr);
  free(arr);
}

/**
 * @brief
 *
 * @param head
 * @param node
 * @return true
 * @return false
 */
bool delete_node(Lista_t* head, Node_t* node) {
  if (node == NULL || head->head == NULL) return false;

  if (node == head->head) {
    head->head = node->next;
  } else if (node == head->tail) {
    head->tail = node->prev;
    node->prev->next = node->next;
  } else {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  free(node->value);
  free(node);
  head->size--;
  return true;
}

/**
 * @brief Cerca il value di tipo type nella lista se lo trova restituisce il
 * nodo stesso, altrimenti restituisce NULL
 *
 * @param self
 * @param value
 * @param type
 * @return Nodo_t*
 */
Node_t* find_value(const Lista_t* self, const void* value, DataType type) {
  for (Node_t* current = self->head; current != NULL; current = current->next) {
    switch (type) {
      case INT:
        if (*(int*)current->value == atoi(value)) return current;
        break;
      case DOUBLE:
        if (*(int*)current->value == atof(value)) return current;
        break;
      case CHAR:
        if (*(char*)current->value == *(char*)value) return current;
        break;
      case STRING:
        if (!strcmp((char*)current->value, (char*)value)) return current;
        break;
      case UNKNOWN:
        return NULL;
    }
  }
}

/**
 * @brief controlla se la lista è vuota oppure no
 *
 * @param head
 * @return true
 * @return false
 */
bool is_empty(const Lista_t* head) { return head->head == NULL; }

/**
 * @brief Aggiunge in coda
 *
 * @param self
 * @param value
 * @param type
 */
void push(Lista_t* self, void* value, DataType type) {
  if (is_empty(self)) {
    return;
  }
  Node_t* tmp = create_nodo(value, type);
  self->tail->next = tmp;
  tmp->prev = self->tail;
  self->tail = tmp;
  self->size++;
}

/**
 * @brief Elimina in coda
 *
 * @param self
 */
void pop(Lista_t* self) {
  if (is_empty(self)) {
    return;
  }
  Node_t* tmp = self->tail;
  self->tail = self->tail->prev;
  self->tail->next = NULL;
  free(tmp->value);
  free(tmp);
  self->size--;
}

/**
 * @brief Print list
 *
 * @param self
 */
void print_list(Lista_t* self) {
  printf("[");
  for (Node_t* tmp = self->head; tmp != NULL; tmp = tmp->next) {
    print_nodo(tmp, " ");
  }
  printf("\b]\n");
}

/**
 * @brief Print list inverse
 *
 * @param self
 */
void print_list_inverse(Lista_t* self) {
  printf("[");
  for (Node_t* tmp = self->tail; tmp != NULL; tmp = tmp->prev) {
    print_nodo(tmp, " ");
  }
  printf("\b]\n");
}

/**
 * @brief Get the size object
 *
 * @param self
 * @return size_t
 */
size_t get_size(Lista_t* self) { return self->size; }
