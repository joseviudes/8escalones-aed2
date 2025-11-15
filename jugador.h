/*jugador.h*/

typedef char tString[30];

typedef struct {
    tString nombre;
    int escalon;
} tJugador;

/* Prototipos */
void inicializarJugador(tJugador*);
void mostrarJugador(tJugador);
void subirEscalon(tJugador*);

