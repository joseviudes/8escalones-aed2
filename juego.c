#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "juego.h"

// para poner colores
#define RESET   "\x1b[0m"
#define ROJO    "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define AZUL    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define BLANCO  "\x1b[37m"

Cola cola;
Pregunta pregunta;


void mostrarEscalon(int actual, int total) {
    if (actual > total) return;

    printf("Escalon %d/%d superado!\n", actual, total);
    mostrarEscalon(actual + 1, total);
}

void jugar(Nodo* lista) {
	
	// seleccionar solo preguntas de temas DIFERENTES
    char temasUsados[20][50];
    int cantTemas = 0;
	
    if (lista == NULL) {
        printf("No se encontraron preguntas cargadas.\n");
        return;
    }

    inicializarCola(&cola);

    Nodo* aux = lista;
    while (aux != NULL && cantTemas < 8) {

        int i, repetido = 0;
        for (i = 0; i < cantTemas; i++) {
            if (strcmp(aux->dato.tema, temasUsados[i]) == 0) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            // guardamos el tema y encolamos la pregunta
            strcpy(temasUsados[cantTemas], aux->dato.tema);
            cantTemas++;
            encolar(&cola, aux->dato);
        }

        aux = aux->sig;
    }
    printf("DEBUG: cantTemas = %d\n", cantTemas);
    
    // lógica del juego
    int escalon = 1;
    int totalEscalones = 8;
    int vidas = 1;

    while (escalon <= totalEscalones && !colaVacia(&cola)) {

        pregunta = desencolar(&cola);

        printf(AZUL "\n===== ESCALON %d =====\n" RESET, escalon);
        printf("Tema: %s\n\n", pregunta.tema);
        printf("%s\n", pregunta.enunciado);
        printf("A) %s\n", pregunta.opcionA);
        printf("B) %s\n", pregunta.opcionB);
        printf("C) %s\n", pregunta.opcionC);
        printf("D) %s\n", pregunta.opcionD);

        char respuesta;
        printf("Respuesta: ");
        scanf(" %c", &respuesta);
        respuesta = toupper(respuesta);
        
        // para agregarle suspenso
        printf("\n...");
		Sleep(1000);  
		printf(" ...");
		Sleep(1000); 
		printf(" ...\n");
		Sleep(1000); 
        

        if (respuesta == pregunta.correcta) {
            printf(VERDE "Respuesta correcta!\n" RESET);
            escalon++;

        } else {
            printf(ROJO "Respuesta incorrecta! La correcta era: %c\n" RESET, pregunta.correcta);
            vidas--;

            if (vidas < 0) {
                printf(ROJO "\nPERDISTE TODAS LAS VIDAS. FIN DEL JUEGO.\n" RESET);
                return;
            } else {
                printf(AMARILLO  "Te queda 1 vida. Cuidado!\n" RESET);
            }
        }
    }

    if (escalon > totalEscalones) {
        printf("\n ¡GANASTE EL JUEGO! \n");
        mostrarEscalon(1, totalEscalones);
    }
}

