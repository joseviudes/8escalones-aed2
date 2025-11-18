#ifndef COLA_H
#define COLA_H

#include "lista.h"

typedef struct ColaNodo {
	Pregunta dato;
	struct ColaNodo* sig;
} ColaNodo;

typedef struct {
	ColaNodo* frente;
	ColaNodo* final;
} Cola;

void inicializarCola(Cola* cola);
int colaVacia(Cola* cola);
void encolar(Cola* cola, Pregunta pregunta);
Pregunta desencolar(Cola* c);

#endif
