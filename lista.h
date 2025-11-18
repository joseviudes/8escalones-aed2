#ifndef LISTA_H
#define LISTA_H

typedef struct {
	int id;
	char enunciado[200];
	char opcionA[100];
	char opcionB[100];
	char opcionC[100];
	char opcionD[100];
	char correcta;
	char tema[50];
} Pregunta;

typedef struct Nodo {
	Pregunta dato;
	struct Nodo* sig;
} Nodo;

void insertarAlFinal(Nodo** lista, Pregunta p);
void liberarLista(Nodo** lista);

#endif
