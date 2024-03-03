#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"
#include "tupla.h"

void test_list();

int main(void) {
//    Tupla_t* tupla = create_tupla();
//    insert_element(tupla, "7", INT);
//    insert_element(tupla, "hello", STRING);
//
//    Lista_t* lista = create_list();
//    void** value = (void **)&tupla;
//    insert_nodo(lista, value, TYPE(tupla));
//    insert_nodo(lista, value, TUPLA);
//    char* str = "7";
//    void** value2 = (void**) &str;
//    insert_nodo(lista, value2, TYPE(7));
//    //insert_nodo(lista, value, INT);
//
//    print_list(lista);
//    print_list_type(lista);

    test_list();
    //print_tupla(tupla, NULL);
    return 0;
}


__attribute__((unused)) void test_list() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));
    unsigned int dimensione = 1000000000;
    int* array = (int*) malloc(sizeof(int) * dimensione);
    if (array == NULL) {
        abort();
    }
    // Crea un array di flag per tenere traccia dei numeri già utilizzati
    int* flag = (int*) calloc(dimensione, sizeof(int));
    if (flag == NULL) {
        abort();
    }

    // Genera un numero casuale e controlla se è già presente nell'array
    // Se non è presente, lo inserisce nell'array e setta il flag a 1
    for (int i = 0; i < dimensione; i++) {
        unsigned int numero;
        do {
            numero = rand() % dimensione;
        } while (flag[numero]);
        array[i] = (int) numero;
        flag[numero] = 1;
    }
    free(flag);

    Lista_t* lista = create_list();
    printf("Creazione lista\n");
    clock_t start = clock();
    for (int i = 0; i < dimensione; ++i) {
        char* el = (char*) malloc(sizeof(char));
        sprintf(el, "%d", array[i]);
        push(lista, el, TYPE(i));
        free(el);
    }
    printf("Tempo di creazione: %lf\n", (double) (clock() - start) / CLOCKS_PER_SEC);
    free(array);

    printf("Ordinamento\n");
    start = clock();
    sort_list(lista, NULL);
    printf("Tempo di ordinamento: %lf\n", (double) (clock() - start) / CLOCKS_PER_SEC);
}