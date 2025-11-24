#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "juego.h"
#include "jugador.h"
#include "cola.h"
#include "lista.h"

// Colores
#define RESET   "\x1b[0m"
#define ROJO    "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define AZUL    "\x1b[34m"

// Cola de preguntas
tCola cola;      
tPregunta pregunta;

void mostrarEscalon(int actual, int total) {
    if (actual > total) return;

    printf("Escalon %d/%d superado!\n", actual, total);
    mostrarEscalon(actual + 1, total);
}

void jugar(tNodo* lista) {

	/*inicialiamos Jugador*/
    tJugador jugador;
    inicializarJugador(&jugador);

	/*filtramos los Temas*/
    char temasUsados[20][50];
    int cantTemas = 0;

    if (lista == NULL) {
        printf("No se encontraron preguntas cargadas.\n");
        return;
    }

    inicializarCola(&cola);

    tNodo* aux = lista; 

    while (aux != NULL && cantTemas < 8) {

        int repetido = 0;
        
        int i;
		for (i = 0; i < cantTemas; i++) {
            if (strcmp(aux->dato.tema, temasUsados[i]) == 0) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            strcpy(temasUsados[cantTemas], aux->dato.tema);
            cantTemas++;
            encolar(&cola, aux->dato);
        }

        aux = aux->sig;
    }

   	/*arranca el JUEGO*/

    int totalEscalones = 8;

    while (jugador.escalon <= totalEscalones && !colaVacia(&cola)) {

        pregunta = desencolar(&cola);

        printf(AZUL "\n===== ESCALON %d =====\n" RESET, jugador.escalon);
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

        // Suspenso
        printf("\n...");
        Sleep(1000);
        printf(" ...");
        Sleep(1000);
        printf(" ...\n");
        Sleep(1000);

        if (respuesta == pregunta.correcta) {
            printf(VERDE "Respuesta correcta!\n" RESET);
            subirEscalon(&jugador);    
        } 
        else {
            printf(ROJO "Incorrecta! La correcta era: %c\n" RESET, pregunta.correcta);
            perderVidas(&jugador);  

            if (jugador.vidas < 0) {
                printf(ROJO "\nPERDISTE. FIN DEL JUEGO.\n" RESET);
                return;
            }
        }
    }

    if (jugador.escalon > totalEscalones) {
        printf(VERDE "\n¡GANASTE EL JUEGO!\n" RESET);
        mostrarEscalon(1, totalEscalones);
    }
}




