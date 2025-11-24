#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preguntas.h"
#include "lista.h"

FILE *archPreguntas;
tPregunta pregunta;


void generarArchivoPreguntas(){

    archPreguntas = fopen("preguntas.dat", "wb");
    if (archPreguntas == NULL) {
        printf("Error al crear archivo preguntas.dat\n");
        exit(EXIT_FAILURE);
    }

    /* 1 — GEOGRAFIA */
    pregunta.id = 1;
    strcpy(pregunta.tema, "Geografia");
    strcpy(pregunta.enunciado, "Cual es la capital de Corrientes?");
    strcpy(pregunta.opcionA, "Ciudad de Corrientes");
    strcpy(pregunta.opcionB, "Ituzaingo");
    strcpy(pregunta.opcionC, "Goya");
    strcpy(pregunta.opcionD, "Esquina");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 2 — MATEMATICA */
    pregunta.id = 2;
    strcpy(pregunta.tema, "Matematica");
    strcpy(pregunta.enunciado, "Cuanto es 7 * 8?");
    strcpy(pregunta.opcionA, "63");
    strcpy(pregunta.opcionB, "56");
    strcpy(pregunta.opcionC, "72");
    strcpy(pregunta.opcionD, "49");
    pregunta.correcta = 'B';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 3 — HISTORIA */
    pregunta.id = 3;
    strcpy(pregunta.tema, "Historia");
    strcpy(pregunta.enunciado, "Quien fue el primer presidente argentino?");
    strcpy(pregunta.opcionA, "Bernardino Rivadavia");
    strcpy(pregunta.opcionB, "San Martín");
    strcpy(pregunta.opcionC, "Belgrano");
    strcpy(pregunta.opcionD, "Urquiza");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 4 — CIENCIA */
	pregunta.id = 4;
	strcpy(pregunta.tema, "Ciencia");
	strcpy(pregunta.enunciado, "Que estrella esta mas cerca de la Tierra?");
	strcpy(pregunta.opcionA, "El Sol");
	strcpy(pregunta.opcionB, "La Luna");
	strcpy(pregunta.opcionC, "Sirio");
	strcpy(pregunta.opcionD, "Venus");
	pregunta.correcta = 'A';
	fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);


    /* 5 — DEPORTES */
    pregunta.id = 5;
    strcpy(pregunta.tema, "Deportes");
    strcpy(pregunta.enunciado, "Cuantos jugadores tiene un equipo de futbol?");
    strcpy(pregunta.opcionA, "9");
    strcpy(pregunta.opcionB, "10");
    strcpy(pregunta.opcionC, "11");
    strcpy(pregunta.opcionD, "12");
    pregunta.correcta = 'C';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 6 — LITERATURA */
    pregunta.id = 6;
    strcpy(pregunta.tema, "Literatura");
    strcpy(pregunta.enunciado, "Quien escribio 'Don Quijote'?");
    strcpy(pregunta.opcionA, "Cervantes");
    strcpy(pregunta.opcionB, "Borges");
    strcpy(pregunta.opcionC, "Shakespeare");
    strcpy(pregunta.opcionD, "Lope de Vega");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 7 — MUSICA */
    pregunta.id = 7;
    strcpy(pregunta.tema, "Musica");
    strcpy(pregunta.enunciado, "Donde nació Carlos Gardel?");
    strcpy(pregunta.opcionA, "Touluse");
    strcpy(pregunta.opcionB, "Buenos Aires");
    strcpy(pregunta.opcionC, "Paris");
    strcpy(pregunta.opcionD, "Santa Fe");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 8 — CINE */
    pregunta.id = 8;
    strcpy(pregunta.tema, "Cine");
    strcpy(pregunta.enunciado, "Quien dirigio la pelicula Titanic?");
    strcpy(pregunta.opcionA, "Spielberg");
    strcpy(pregunta.opcionB, "Cameron");
    strcpy(pregunta.opcionC, "Nolan");
    strcpy(pregunta.opcionD, "Scorsese");
    pregunta.correcta = 'B';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 9 — BIOLOGIA */
    pregunta.id = 9;
    strcpy(pregunta.tema, "Biologia");
    strcpy(pregunta.enunciado, "Donde ocurre la fotosintesis?");
    strcpy(pregunta.opcionA, "Cloroplastos");
    strcpy(pregunta.opcionB, "Mitocondrias");
    strcpy(pregunta.opcionC, "Ribosomas");
    strcpy(pregunta.opcionD, "Nucleo");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    /* 10 — TECNOLOGIA */
    pregunta.id = 10;
    strcpy(pregunta.tema, "Tecnologia");
    strcpy(pregunta.enunciado, "Quien fundo Microsoft?");
    strcpy(pregunta.opcionA, "Steve Jobs");
    strcpy(pregunta.opcionB, "Jeff Bezos");
    strcpy(pregunta.opcionC, "Elon Musk");
    strcpy(pregunta.opcionD, "Bill Gates");
    pregunta.correcta = 'D';
    fwrite(&pregunta, sizeof(tPregunta), 1, archPreguntas);

    fclose(archPreguntas);
}

void cargarPreguntasDesdeArchivo(tNodo **lista) {

    archPreguntas = fopen("preguntas.dat", "rb");

    if (archPreguntas == NULL) {
        printf("Error al abrir archivo\n");
        return;
    }

    while (fread(&pregunta, sizeof(tPregunta), 1, archPreguntas) == 1) {
        insertarAlFinal(lista, pregunta);
    }

    fclose(archPreguntas);
}

