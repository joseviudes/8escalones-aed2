#define MAX_TEXTO 100
#define MAX_OPCION 50
typedef char tString[50];

typedef struct {
    tString texto;
    tString opcionA;
    tString opcionB;
    tString opcionC;
    char correcta; /* 'A', 'B' o 'C' */
} tPregunta;

/* Prototipos */
void abrirArchivoPreguntas();
void leerPregunta(tPregunta*); /*leer un archivo txt con las preguntas*/
void mostrarPregunta(tPregunta);
int verificarRespuesta(tPregunta, char);
void cerrarArchivoPreguntas();


