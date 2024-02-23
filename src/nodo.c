#include "nodo.h"

Node_t* create_nodo(char* value, DataType type) {
    Node_t* newNode = (Node_t*) malloc(sizeof(Node_t));
    if (newNode == NULL) {
        perror("Errore nell'allocazione del nuovo nodo");
        return NULL;
    }
    newNode->type = type;
    newNode->next = NULL;
    newNode->prev = NULL;

    // TODO: controllare che le stringhe numeriche non contengono altri caratteri
    //- es. 123 -> true, 12.3->true, 12.3p -> false, i78 -> false
    char* endptr;
    switch (type) {
        case INT:newNode->value = (int*) malloc(sizeof(int));
            *(int*) newNode->value = (int) strtol(value, &endptr, 10);
            if (value == endptr) {
                perror("Errore di salvataggio del valore del nodo");
                return NULL;
            }
            break;
        case DOUBLE:newNode->value = (double*) malloc(sizeof(double));
            *(double*) newNode->value = strtof(value, &endptr);
            if (value == endptr) {
                perror("Errore di salvataggio del valore del nodo");
                return NULL;
            }
            break;
        case CHAR:newNode->value = (char*) malloc(sizeof(char));
            *(char*) newNode->value = *(char*) (value);
            break;
        case STRING:newNode->value = (char*) malloc(sizeof(char) * strlen((char*) value) + 1);
            memcpy(newNode->value, value, strlen((char*) value) + 1);
            break;
        default:break;
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

    switch (nodo->type) {
        case INT:printf("%d", *(int*) nodo->value);
            break;
        case DOUBLE:printf("%g", *(double*) (nodo->value));
            break;
        case CHAR:printf("%c", *(char*) (nodo->value));
            break;
        case STRING:printf("%s", (char*) (nodo->value));
            break;
        default:break;
    }
    printf("%s", terminator);
}

// --- OPERAZIONI TRA NODI ---

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

    if (a->type == INT && b->type == INT) {
        sum = *(int*) a->value + *(int*) b->value;
    } else if (a->type == DOUBLE && b->type == DOUBLE) {
        sum = *(double*) a->value + *(double*) b->value;
    } else if (a->type == DOUBLE && b->type == INT) {
        sum = *(double*) a->value + *(int*) b->value;
    } else if (a->type == INT && b->type == DOUBLE) {
        sum = *(int*) a->value + *(double*) b->value;
    } else {
        perror("Errore la somma non può essere eseguita.\n");
    }
    return sum;
}

double minus(Node_t* a, Node_t* b) {
    double result = 0;
    if (a == NULL || b == NULL) {
        perror("Errore la sottrazione è nulla.\n");
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
    } else {
        fprintf(stderr, "Errore la sottrazione non può essere eseguita.\n");
    }
    return result;
}

double multiply(Node_t* a, Node_t* b) {
    double result = 0;
    if (a == NULL || b == NULL) {
        perror("Errore la sottrazione è nulla.\n");
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
    } else {
        fprintf(stderr, "Errore la sottrazione non può essere eseguita.\n");
    }
    return result;
}

double divide(Node_t* a, Node_t* b) {
    double result;
    if (a == NULL || b == NULL) {
        perror("Errore la sottrazione è nulla.\n");
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
    } else if ((a->type == CHAR || a->type == STRING) &&
               (b->type == CHAR || b->type == STRING)) {
        sprintf(result, "%s %s", (char*) a->value, (char*) b->value);
        return result;
    }

    perror("Errore la concatenazione non può essere eseguita.\n");
    return NULL;
}