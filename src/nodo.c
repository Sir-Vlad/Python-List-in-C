#include "nodo.h"

Node_t* create_nodo(void* value, DataType type) {
    Node_t* newNode = (Node_t*) malloc(sizeof(Node_t));
    if (newNode == NULL) {
        perror("Errore nell'allocazione del nuovo nodo");
        return NULL;
    }
    newNode->type = type;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->value = save_value(value, type);
    if (newNode->value == NULL){
        perror("Errore nella creazione del nodo\n");
        free(newNode);
        return NULL;
    }
    return newNode;
}

/**
 * @brief Print node based on type
 *
 * @param nodo
 * @param terminator
 */
void print_nodo(const Node_t* nodo, char* terminator) {
    if (terminator == NULL) {
        memcpy(terminator = (char*) malloc(sizeof("\n")), "\n", sizeof("\n"));
    }

    if (nodo == NULL) {
        printf("NULL%s", terminator);
        return;
    }

    print_value(nodo->value, nodo->type);
    printf("%s", terminator);
}

// --- OPERAZIONI TRA NODI ---

bool isNotNumber(Node_t* node) {
    return node->type != INT && node->type != DOUBLE;
}

/**
 * @brief Somma il value di due nodi
 *
 * @param a
 * @param b
 * @return double
 */
double add(Node_t* a, Node_t* b) {
    double sum = 0;
    if (a == NULL || b == NULL) {
        perror("Errore la somma è nulla.\n");
        return 0.0;
    }

    if (isNotNumber(a) || isNotNumber(b)) {
        perror("La somma non può essere eseguita perché i valori non sono tipi numerici\n");
        return 0.0;
    }

    if (a->type == INT && b->type == INT) {
        sum = *(int*) a->value + *(int*) b->value;
    } else if (a->type == DOUBLE && b->type == DOUBLE) {
        sum = *(double*) a->value + *(double*) b->value;
    } else if (a->type == DOUBLE && b->type == INT) {
        sum = *(double*) a->value + *(int*) b->value;
    } else if (a->type == INT && b->type == DOUBLE) {
        sum = *(int*) a->value + *(double*) b->value;
    }
    return sum;
}

double minus(Node_t* a, Node_t* b) {
    double result = 0;
    if (a == NULL || b == NULL) {
        perror("Errore la sottrazione è nulla.\n");
        return 0.0;
    }
    if (isNotNumber(a) || isNotNumber(b)) {
        perror("La divisione non può essere eseguita perché i valori non sono tipi numerici\n");
        return 0.0;
    }

    if (a->type == INT && b->type == INT) {
        result = *(int*) a->value - *(int*) b->value;
    } else if (a->type == DOUBLE && b->type == DOUBLE) {
        result = *(double*) a->value - *(double*) b->value;
    } else if (a->type == DOUBLE && b->type == INT) {
        result = *(double*) a->value - *(int*) b->value;
    } else if (a->type == INT && b->type == DOUBLE) {
        result = *(int*) a->value - *(double*) b->value;
    }
    return result;
}

double multiply(Node_t* a, Node_t* b) {
    double result = 0;
    if (a == NULL || b == NULL) {
        perror("Errore la sottrazione è nulla.\n");
        return 0.0;
    }
    if (isNotNumber(a) || isNotNumber(b)) {
        perror("La somma non può essere eseguita perché i valori non sono tipi numerici\n");
        return 0.0;
    }

    if (a->type == INT && b->type == INT) {
        result = *(int*) a->value * *(int*) b->value;
    } else if (a->type == DOUBLE && b->type == DOUBLE) {
        result = *(double*) a->value * *(double*) b->value;
    } else if (a->type == DOUBLE && b->type == INT) {
        result = *(double*) a->value * *(int*) b->value;
    } else if (a->type == INT && b->type == DOUBLE) {
        result = *(int*) a->value * *(double*) b->value;
    }
    return result;
}

double divide(Node_t* a, Node_t* b) {
    double result;
    if (a == NULL || b == NULL) {
        perror("Errore la sottrazione è nulla.\n");
        return 0.0;
    }
    if (isNotNumber(a) || isNotNumber(b)) {
        perror("La divisione non può essere eseguita perché i valori non sono tipi numerici\n");
        return 0.0;
    }

    if ((a->type == INT || a->type == DOUBLE) &&
        (b->type == INT || b->type == DOUBLE)) {
        double a_v = a->type == INT ? (*(int*) a->value) : (*(double*) a->value);
        double b_v = b->type == INT ? (*(int*) b->value) : (*(double*) b->value);
        if (b_v == 0) {
            perror("Errore divisione per 0\n");
            return 0.0;
        }
        result = a_v / b_v;
        return result;
    }
    perror("Errore la divisione non può essere eseguita.\n");
    return 0.0;
}

char* concat(Node_t* a, Node_t* b) {
    char* result = (char*) malloc(sizeof(a->value) + sizeof(b->value) + 2);
    if (a == NULL || b == NULL) {
        perror("Errore uno dei due valori sono nulli.\n");
        return NULL;
    }

    if ((a->type != CHAR && a->type != STRING) || ((b->type != CHAR && b->type != STRING))) {
        perror("Errore la concatenazione non può essere eseguita perché i valori non sono di tipo"
               " testo"
               ".\n");
        return NULL;
    }

    sprintf(result, "%s %s", (char*) a->value, (char*) b->value);
    return result;
}