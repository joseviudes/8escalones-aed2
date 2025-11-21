#ifndef PREGUNTAS_H
#define PREGUNTAS_H

typedef char tString[100];

typedef struct tPregunta {
    int id;
    tString tema;
    tString opcionA;
    tString opcionB;
    tString opcionC;
    tString opcionD;
    tString enunciado;
    char correcta;
} tPregunta;

#endif


