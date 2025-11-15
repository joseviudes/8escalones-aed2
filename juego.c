/*juego.c*/

#include <stdio.h>
#include "preguntas.h"
#include "jugador.h"

/*prototipo*/
void jugar();

/*implementacion*/

void jugar() {

    tJugador jugador;
    tPregunta pregunta;
    char respuesta;

    abrirArchivoPreguntas();

    printf("===== BIENVENIDO A LOS 8 ESCALONES =====\n");
    inicializarJugador(&jugador);

    printf("\nComencemos!\n");

    while (jugador.escalon <= 8 && !feof(archPreguntas)) {

        leerPregunta(&pregunta);
        mostrarPregunta(pregunta);

        printf("\nIngrese su respuesta: ");
        scanf(" %c", &respuesta);

        if (verificarRespuesta(pregunta, respuesta)) {

            subirEscalon(&jugador);
            printf("Subiste al escalon %d!\n", jugador.escalon);

            if (jugador.escalon > 8) {
                printf("\nFELICITACIONES %s! GANASTE EL JUEGO!\n", jugador.nombre);
                break;
            }

        } else {

            printf("\nRespuesta incorrecta...\n");
            printf("Perdiste, %s. Llegaste hasta el escalon %d.\n",
                   jugador.nombre, jugador.escalon);
            break;
        }
    }

    cerrarArchivoPreguntas();
}

