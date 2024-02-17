#include "nodo.h"

Node_t* create_nodo(void* value, DataType type) {
  Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
  if (newNode == NULL) {
    printf("Errore nell'allocazione del nuovo nodo");
    return NULL;
  }
  newNode->type = type;
  newNode->next = NULL;
  newNode->prev = NULL;

  // TODO: controllare che le stringhe numeriche non contengono altri caratteri
  //- es. 123 -> true, 12.3->true, 12.3p -> false, i78 -> false
  char value_trim[strlen(value)];
  switch (type) {
    case INT:
      newNode->value = (int*)malloc(sizeof(int));
      *(int*)newNode->value = atoi(value);
      break;
    case DOUBLE:
      newNode->value = (double*)malloc(sizeof(double));
      *(double*)newNode->value = atof(value);
      break;
    case CHAR:
      newNode->value = (char*)malloc(sizeof(char));
      *(char*)newNode->value = *(char*)(value);
      break;
    case STRING:
      newNode->value = (char*)malloc(sizeof(char) * strlen((char*)value) + 1);
      memcpy(newNode->value, value, strlen((char*)value) + 1);
      break;
    default:
      break;
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
    memcpy(terminator = (char*)malloc(sizeof("\n")), "\n", sizeof("\n"));
  }

  if (nodo == NULL) {
    printf("NULL%s", terminator);
    return;
  };

  switch (nodo->type) {
    case INT:
      printf("%d", *(int*)nodo->value);
      break;
    case DOUBLE:
      printf("%g", *(double*)(nodo->value));
      break;
    case CHAR:
      printf("%c", *(char*)(nodo->value));
      break;
    case STRING:
      printf("%s", (char*)(nodo->value));
      break;
    default:
      break;
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
    fprintf(stderr, "Errore la somma è nulla.\n");
  } else if (a->type == INT && b->type == INT) {
    sum = *(int*)a->value + *(int*)b->value;
  } else if (a->type == DOUBLE && b->type == DOUBLE) {
    sum = *(double*)a->value + *(double*)b->value;
  } else if (a->type == DOUBLE && b->type == INT) {
    sum = *(double*)a->value + *(int*)b->value;
  } else if (a->type == INT && b->type == DOUBLE) {
    sum = *(int*)a->value + *(double*)b->value;
  } else {
    fprintf(stderr, "Errore la somma non può essere eseguita.\n");
  }
  return sum;
}

double minus(Node_t* a, Node_t* b) {
  double result = 0;
  if (a == NULL || b == NULL) {
    fprintf(stderr, "Errore la sottrazione è nulla.\n");
  } else if (a->type == INT && b->type == INT) {
    result = *(int*)a->value - *(int*)b->value;
  } else if (a->type == DOUBLE && b->type == DOUBLE) {
    result = *(double*)a->value - *(double*)b->value;
  } else if (a->type == DOUBLE && b->type == INT) {
    result = *(double*)a->value - *(int*)b->value;
  } else if (a->type == INT && b->type == DOUBLE) {
    result = *(int*)a->value - *(double*)b->value;
  } else {
    fprintf(stderr, "Errore la sottrazione non può essere eseguita.\n");
  }
  return result;
}

double multiply(Node_t* a, Node_t* b) {
  double result = 0;
  if (a == NULL || b == NULL) {
    fprintf(stderr, "Errore la sottrazione è nulla.\n");
  } else if (a->type == INT && b->type == INT) {
    result = *(int*)a->value * *(int*)b->value;
  } else if (a->type == DOUBLE && b->type == DOUBLE) {
    result = *(double*)a->value * *(double*)b->value;
  } else if (a->type == DOUBLE && b->type == INT) {
    result = *(double*)a->value * *(int*)b->value;
  } else if (a->type == INT && b->type == DOUBLE) {
    result = *(int*)a->value * *(double*)b->value;
  } else {
    fprintf(stderr, "Errore la sottrazione non può essere eseguita.\n");
  }
  return result;
}

double divide(Node_t* a, Node_t* b) {
  double result = 0;
  if (a == NULL || b == NULL) {
    fprintf(stderr, "Errore la sottrazione è nulla.\n");
  } else if ((a->type == INT || a->type == DOUBLE) &&
             (b->type == INT || b->type == DOUBLE)) {
    int a_v = (*(int*)a->value);
    int b_v = (*(int*)b->value);
    if (b_v == 0) {
      fprintf(stderr, "Errore divisione per 0\n");
      return 0.0;
    }
    result = (double)a_v / (double)b_v;
    return result;
  }
  fprintf(stderr, "Errore la divisione non può essere eseguita.\n");
  return 0.0;
};

char* concat(Node_t* a, Node_t* b) {
  char* result = (char*)malloc(sizeof(a->value) + sizeof(b->value) + 2);
  if (a == NULL || b == NULL) {
    fprintf(stderr, "Errore la sottrazione è nulla.\n");
  } else if ((a->type == CHAR || a->type == STRING) &&
             (b->type == CHAR || b->type == STRING)) {
    sprintf(result, "%s %s", (char*)a->value, (char*)b->value);
  }
  fprintf(stderr, "Errore la sottrazione non può essere eseguita.\n");
  return result;
};