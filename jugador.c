/*jugador.c*/

#include <stdio.h>
#include <string.h>
#include "jugador.h"

void inicializarJugador(tJugador *jugador) {

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(jugador->nombre);

    jugador->escalon = 1;   /* arranca en escalón 1 */
}

void mostrarJugador(tJugador jugador) {
	
    printf("\nJugador: %s\n", jugador.nombre);
    printf("Escalón actual: %d\n", jugador.escalon);
}

void subirEscalon(tJugador *jugador) {
    jugador->escalon + 1;
} /*lo invocamos cuando el jugador responda correctamente*/


