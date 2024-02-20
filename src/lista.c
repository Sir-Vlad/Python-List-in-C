#include "lista.h"

#include "utils.h"

/**
 * @brief Create a list object
 *
 * @return Lista_t*
 */
Lista_t* create_list() {
    Lista_t* lista = (Lista_t*) malloc(sizeof(Lista_t));
    if (lista == NULL) {
        perror("Errore di allocazione della lista");
        return NULL;
    }
    lista->head = NULL;
    lista->size = 0;
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
    size_t size = lista->size;
    Node_t** arr = (Node_t**) malloc(size * sizeof(Node_t*));
    Node_t* tmp = lista->head;
    for (size_t i = 0; i < size; i++) {
        arr[i] = tmp;
        tmp = tmp->next;
    }
    return arr;
}

/**
 * @brief Converto il campo del nodo in stringa
 *
 * @param fieldValue
 * @param fieldType
 * @return char*
 */
char* convertFieldToString(Node_t* fieldValue, DataType fieldType) {
    char* a = (char*) malloc(fieldValue->type != STRING ? sizeof(fieldValue->value) + 1 :
                             sizeof(char*) * strlen(fieldValue->value) + 1);
    switch (fieldValue->type) {
        case INT: sprintf(a, "%d", *(int*) fieldValue->value);
            break;
        case DOUBLE: sprintf(a, "%f", *(double*) fieldValue->value);
            break;
        case CHAR: sprintf(a, "%c", *(char*) fieldValue->value);
            break;
        case STRING: memcpy(a, fieldValue->value, strlen(fieldValue->value));
            break;
        default: fprintf(stderr, "Error type not found\n");
            return NULL;
    }
    return a;
}

/**
 * @brief
 *
 * @param a
 * @param b
 * @return int
 * a<b => -1
 * a=b => 0
 * a>b => 1
 */
int cmpNodes(const void* a, const void* b) {
    Node_t* nodeA = *((Node_t**) a);
    Node_t* nodeB = *((Node_t**) b);
    if (nodeA->type == INT && nodeB->type == INT) {
        return (*(int*) nodeA->value - *(int*) nodeB->value);
    } else if ((nodeA->type == INT || nodeA->type == DOUBLE) &&
               (nodeB->type == INT || nodeB->type == DOUBLE)) {
        double dA = nodeA->type == DOUBLE ? *(double*) nodeA->value : *(int*) nodeA->value;
        double dB = nodeB->type == DOUBLE ? *(double*) nodeB->value : *(int*) nodeB->value;
        return dA < dB ? -1 : (dA > dB ? 1 : 0);
    } else if (nodeA->type == STRING && nodeB->type == STRING) {
        return strcmp((char*) nodeA->value, (char*) nodeB->value);
    } else if (nodeA->type == CHAR && nodeB->type == CHAR) {
        return (*(char*) nodeA->value - *(char*) nodeB->value);
    } else if ((nodeA->type == CHAR || nodeA->type == STRING) &&
               (nodeB->type == CHAR || nodeB->type == STRING)) {

        return (nodeA->type == CHAR && nodeB->type == STRING) ? -1 : (nodeA->type == STRING &&
                                                                      nodeB->type == CHAR) ? 1 : 0;
    } else {
        return ((nodeA->type == DOUBLE || nodeA->type == INT) &&
                (nodeB->type == STRING || nodeB->type == CHAR))
               ? -1
               : ((nodeA->type == STRING && nodeB->type == STRING) ? 0 : 1);
    }
}

/**
 * @brief Ordina un array
 *
 * @param arr
 * @param size
 * @todo Charge the algorithm of sort
 */
void sortArr(Node_t** arr, size_t size) {
    qsort(arr, size, sizeof(Node_t*), cmpNodes);
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
        if (i != 0)
            current->prev = arr[i - 1];
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
 * @param self
 */
void sort_list(Lista_t* self) {
    Node_t** arr = convertListToArr(self);
    sortArr(arr, self->size);
    rebuildList(self, arr);
    free(arr);
}

/**
 * @brief
 *
 * @param self
 * @param node
 * @return true
 * @return false
 */
bool delete_node(Lista_t* self, Node_t* node) {
    if (node == NULL || self->head == NULL)
        return false;

    if (node == self->head) {
        self->head = node->next;
    } else if (node == self->tail) {
        self->tail = node->prev;
        node->prev->next = node->next;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node->value);
    free(node);
    self->size--;
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
    char* endptr;
    for (Node_t* current = self->head; current != NULL; current = current->next) {
        switch (type) {
            case INT:
                if (*(int*) current->value == strtol(value, &endptr, 10))
                    return current;
                break;
            case DOUBLE:
                if (*(double*) current->value == strtof(value, &endptr))
                    return current;
                break;
            case CHAR:
                if (*(char*) current->value == *(char*) value)
                    return current;
                break;
            case STRING:
                if (!strcmp((char*) current->value, (char*) value))
                    return current;
                break;
            case UNKNOWN:return NULL;
        }
    }
    return NULL;
}

/**
 * @brief controlla se la lista è vuota oppure no
 *
 * @param self
 * @return true
 * @return false
 */
bool is_empty(const Lista_t* self) {
    return self->head == NULL;
}

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
void print_list(const Lista_t* self) {
    printf("[");
    for (Node_t* tmp = self->head; tmp != NULL; tmp = tmp->next) {
        print_nodo(tmp, " ");
    }
    printf("\b]\n");
}

/**
 * @brief Print type element of list
 *
 * @param self
 */
void print_list_type(const Lista_t* self) {
    printf("[");
    for (Node_t* tmp = self->head; tmp != NULL; tmp = tmp->next) {
        printf("%s ", to_string_dataType(tmp->type));
    }
    printf("\b]\n");
}

/**
 * @brief Print list inverse
 *
 * @param self
 */
void print_list_inverse(const Lista_t* self) {
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
size_t get_size(const Lista_t* self) {
    return self->size;
}
