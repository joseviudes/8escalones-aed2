#ifndef LISTA_H
#define LISTA_H

#include "preguntas.h"

typedef struct nodo {
    tPregunta dato;
    struct nodo* sig;
} tNodo;

void insertarAlFinal(tNodo** lista, tPregunta dato);
void liberarLista(tNodo** lista);

#endif
