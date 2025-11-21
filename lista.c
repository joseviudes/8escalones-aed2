#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertarAlFinal(tNodo** lista, tPregunta pregunta) {

    tNodo* nuevoNodo = (tNodo*) malloc(sizeof(tNodo));  
    nuevoNodo->dato = pregunta;
    nuevoNodo->sig = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        tNodo* aux = *lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
    }
}

void liberarLista(tNodo** lista) {

    tNodo* aux;

    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}
