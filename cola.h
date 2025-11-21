#ifndef COLA_H
#define COLA_H

#include "preguntas.h"

typedef struct colaNodo {
    tPregunta dato;
    struct colaNodo* sig;
} tColaNodo;

typedef struct {
    tColaNodo* frente;
    tColaNodo* final;
} tCola;

void inicializarCola(tCola* cola);
int colaVacia(tCola* cola);
void encolar(tCola* cola, tPregunta pregunta);
tPregunta desencolar(tCola* cola);

#endif
