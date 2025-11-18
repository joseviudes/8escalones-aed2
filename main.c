#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "preguntas.h"
#include "juego.h"

void mostrarMenu();
void mostrarReglas();
void ejecutarMenu();

int main () {

	ejecutarMenu();	

	return 0;
}



void mostrarMenu() {
	
	printf("\n=============================\n");
    printf("       LOS 8 ESCALONES     \n");
    printf("=============================\n");
    printf("1) Jugar\n");
    printf("2) Ver reglas\n");
    printf("3) Generar archivo preguntas.dat\n");
    printf("4) Salir\n");
    printf("Seleccione una opcion: ");
	
}

void mostrarReglas() {
	
	printf("\n====== REGLAS DEL JUEGO ======\n");
    printf("- Avanzas 8 escalones respondiendo preguntas.\n");
    printf("- Cada escalon tiene una pregunta de un tema distinto.\n");
    printf("- Las preguntas tienen 4 opciones posibles (A, B, C y D).\n");
    printf("- Solo tenes 1 vida. Si te equivocas dos veces, perdes.\n");
    printf("- Si llegas al escalon 8, ganas el juego.\n");
    printf("===============================\n");
	
}

void ejecutarMenu() {

    int opcion;
    Nodo* listaPreguntas = NULL;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                listaPreguntas = NULL;
                cargarPreguntasDesdeArchivo(&listaPreguntas);
                jugar(listaPreguntas);
                liberarLista(&listaPreguntas);
                break;

            case 2:
                mostrarReglas();
                break;

            case 3:
                generarArchivoPreguntas();
                printf("\nArchivo preguntas.dat generado correctamente.\n");
                break;

            case 4:
                printf("\nSaliendo del juego...\n");
                break;

            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 4);
}
