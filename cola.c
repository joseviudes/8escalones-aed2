#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void inicializarCola(tCola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

int colaVacia(tCola* cola) {
    return cola->frente == NULL;
}

void encolar(tCola* cola, tPregunta pregunta) {

    tColaNodo* nuevo = (tColaNodo*) malloc(sizeof(tColaNodo));
    nuevo->dato = pregunta;
    nuevo->sig = NULL;

    if (cola->final == NULL) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->sig = nuevo;
        cola->final = nuevo;
    }
}

tPregunta desencolar(tCola* cola) {

    tColaNodo* aux = cola->frente;
    tPregunta p = aux->dato;

    cola->frente = aux->sig;

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    free(aux);

    return p;
}
eturn pregunta;
}
