//
// Created by maty on 26/02/24.
//
#include "tupla.h"

/**
 * @brief
 * @return
 */
Tupla_t* create_tupla() {
    Tupla_t* tupla = (Tupla_t*) malloc(sizeof(Tupla_t));
    if (tupla == NULL) {
        perror("Errore nella creazione della tupla\n");
        return NULL;
    }
    tupla->values = NULL;
    tupla->size = 0;
    return tupla;
}

/**
 * @brief
 * @param tupla
 * @param value
 * @param type
 */
void insert_element(Tupla_t* tupla, void* value, DataType type) {
    // creo il nuovo elemento
    Element_t* tmp = (Element_t*) malloc(sizeof(Element_t));
    if (tmp == NULL) {
        perror("Errore nella creazione del nuovo elemento della tupla\n");
        return;
    }
    // inizializzo i valori del nuovo elemento
    tmp->type = type;
    tmp->value = save_value(value, type);
    if (tmp->value == NULL) {
        perror("Errore nella creazione del nuovo elemento della tupla\n");
        free(tmp);
        return;
    }

    // se l'array dei valori non è stato inizializzato
    if (tupla->values == NULL) {
        // creo l'array
        tupla->values = (const Element_t**) (Element_t**) malloc(sizeof(Element_t*));
        if (tupla->values == NULL) {
            perror("Errore nella creazione della tupla\n");
            free(tmp);
            return;
        }
        // assegno l'elemento all'array
        tupla->values[0] = tmp;
    } else {
        // aggiungo una nuova posizione all'array e assegno il puntatore a una variabile di comodo
        Element_t** buffer = (Element_t**) realloc(tupla->values,
                                                   (tupla->size + 1) * sizeof(Element_t*));
        if (buffer == NULL) {
            perror("Errore nell'aggiungere il nuovo elemento\n");
            free(tmp);
            return;
        }
        // se la variabile di comodo non è NULL, la assegno alla lista dei valori
        tupla->values = (const Element_t**) buffer;
        tupla->values[tupla->size] = tmp;
    }
    tupla->size++;
}

void print_tupla(Tupla_t* tupla, char* terminator) {
    if (terminator == NULL){
        terminator = "\n";
    }

    printf("(");
    for (size_t i = 0; i < tupla->size; ++i) {
        Element_t* tmp = (Element_t*) tupla->values[i];
        print_value(tmp->value, tmp->type);
        printf(tupla->size != 1 ? " " : "");
    }
    printf(tupla->size == 1 ? ")%s" : "\b)%s", terminator);
}

__attribute__((unused)) void print_type_tupla(Tupla_t* tupla) {
    for (int i = 0; i < tupla->size; ++i) {
        printf("%s ", to_string_dataType(tupla->values[i]->type));
    }
}

void delete_tupla(Tupla_t** tupla) {
    if(tupla==NULL){
        return;
    }

    for (int i = 0; i < (*tupla)->size; ++i) {
        free((*tupla)->values[i]->value);
    }
    free((*tupla)->values);
    free(*tupla);
    *tupla = NULL;
}
