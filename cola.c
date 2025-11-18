#include <stdio.h>
#include "cola.h"

void inicializarCola(Cola* cola) {
	cola->frente = NULL;
	cola->final = NULL;
}

int colaVacia(Cola* cola) {
	return (cola->frente == NULL);
}

void encolar(Cola* cola, Pregunta pregunta) {
	ColaNodo* nuevoNodo = (ColaNodo*) malloc(sizeof(ColaNodo));
	if (nuevoNodo == NULL) {
        printf("Error al reservar memoria.\n");
        return;;
    }
    
	nuevoNodo->dato = pregunta;
	nuevoNodo->sig = NULL;
	
	if (colaVacia(cola)) {
		cola->frente = nuevoNodo;
		cola->final = nuevoNodo;
	} else {
		cola->final->sig = nuevoNodo;
		cola->final = nuevoNodo;
	}
}

Pregunta desencolar(Cola* cola) {
    ColaNodo* aux = cola->frente;
    Pregunta pregunta = aux->dato;

    cola->frente = aux->sig;
    if (cola->frente == NULL) {   // si quedó vacía
        cola->final = NULL;
    }

    free(aux);
    return pregunta;
}
