#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertarAlFinal(Nodo** lista, Pregunta pregunta) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->dato = pregunta;
    nuevoNodo->sig = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Nodo* aux = *lista;
        while (aux->sig != NULL) {  // recorre hasta el último
            aux = aux->sig;
        }
        aux->sig = nuevoNodo; // ENLAZA AL FINAL
    }
}

void liberarLista(Nodo** lista) {
	Nodo* aux;
	
	while(*lista != NULL) {
		aux = *lista;
		*lista = (*lista)->sig;
		free(aux);
	}
}
