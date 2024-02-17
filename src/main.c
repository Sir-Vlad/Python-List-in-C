#include <assert.h>
#include <stdio.h>

#include "lista.h"

int main(int argc, char const* argv[]) {
  void *input, *input2;
  input = "5.6";
  //   input2 = "e2.3";

  //   Nodo_t* head = create_nodo(input, type(input));
  //   Nodo_t* head2 = create_nodo(input2, type(input2));
  //   print_nodo(head);
  //   printf("%f\n", add(head, head2));

  Lista_t* lista = create_list();
  void* elemento;
  //   int* res = random_array(10, 0, 10);
  int res[] = {5, 6, 3, 7, 2, 1, 4, 10, 8, 9};
  for (size_t i = 0; i < 10; i++) {
    elemento = (char*)malloc(sizeof(char) * 50);
    sprintf((char*)elemento, "%i", res[i]);
    insert_nodo(lista, elemento, type(elemento));
    elemento = NULL;
  }
  insert_nodo(lista, input, type(input));
  print_list(lista);

  printf("Array ordinato:\n");
  sort_list(lista);
  print_list(lista);
  // print_list_inverse(lista);

  //   void* input3;
  //   input3 = "a";
  //   insert_nodo(lista, input3, type(input3));

  //   printf("Len lista: %ld\n", get_size(lista));

  //   Nodo_t* el = find_value(lista, "11", INT);
  //   printf("Il nodo è: ");
  //   print_nodo(el, NULL);
  //   print_list(lista);

  //   delete_node(lista, el);

  //   printf("\nLista dopo eliminazione:\n");
  //   print_list(lista);
  //   printf("SIZE: %ld\n", get_size(lista));

  //   printf("\nLista inversa:\n");
  //   print_list_inverse(lista);

  //   printf("\nPush:\n");
  //   push(lista, "più", STRING);
  //   print_list(lista);
  //   print_list_inverse(lista);
  //   printf("SIZE: %ld\n", get_size(lista));

  //   printf("\nPop:\n");
  //   pop(lista);
  //   print_list(lista);
  //   print_list_inverse(lista);
  //   printf("SIZE: %ld\n", get_size(lista));

  //   void *value1, *value2;
  //   value1 = "ciao";
  //   value2 = "hello hello";

  //   Nodo_t* nodo1 = create_nodo(value1, type(value1));
  //   Nodo_t* nodo2 = create_nodo(value2, type(value2));

  //   printf("Somma: %f\n", add(nodo1, nodo2));
  //   printf("Sottrazione: %f\n", minus(nodo1, nodo2));
  //   printf("Moltiplicazione: %f\n", multiply(nodo1, nodo2));
  //   printf("Divisione: %f\n", divide(nodo1, nodo2));

  //   printf("\nConcatenazione: %s\n", concat(nodo1, nodo2));

  return 0;
}

void test() {
  void* input;
  DataType data_type;

  // Esempio di utilizzo della funzione
  input = "123";
  data_type = type(input);
  printf("Il tipo di valore di '%s' è: %s\n", (char*)input,
         to_string_dataType(data_type));

  input = "3.14";
  data_type = type(input);
  printf("Il tipo di valore di '%s' è: %s\n", (char*)input,
         to_string_dataType(data_type));

  input = "a";
  data_type = type(input);
  printf("Il tipo di valore di '%s' è: %s\n", (char*)input,
         to_string_dataType(data_type));

  input = "Ciao mondo!";
  data_type = type(input);
  printf("Il tipo di valore di '%s' è: %s\n", (char*)input,
         to_string_dataType(data_type));
}