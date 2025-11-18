#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "preguntas.h"

FILE* archivo;
Pregunta pregunta;

void generarArchivoPreguntas() {
    FILE* arch = fopen("preguntas.dat", "wb");
    if (!arch) return;

    // 1 — GEOGRAFIA
    pregunta.id=1;
    strcpy(pregunta.tema, "Geografia");
    strcpy(pregunta.enunciado, "Cual es la capital de Francia?");
    strcpy(pregunta.opcionA, "Berlin");
    strcpy(pregunta.opcionB, "Roma");
    strcpy(pregunta.opcionC, "Madrid");
    strcpy(pregunta.opcionD, "Paris");
    pregunta.correcta = 'D';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 2 — MATEMATICA
    pregunta.id=2;
    strcpy(pregunta.tema, "Matematica");
    strcpy(pregunta.enunciado, "Cuanto es 7 * 8?");
    strcpy(pregunta.opcionA, "63");
    strcpy(pregunta.opcionB, "56");
    strcpy(pregunta.opcionC, "72");
    strcpy(pregunta.opcionD, "49");
    pregunta.correcta = 'B';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 3 — HISTORIA
    pregunta.id=3;
    strcpy(pregunta.tema, "Historia");
    strcpy(pregunta.enunciado, "En que anio cayo el muro de Berlin?");
    strcpy(pregunta.opcionA, "1987");
    strcpy(pregunta.opcionB, "1989");
    strcpy(pregunta.opcionC, "1975");
    strcpy(pregunta.opcionD, "1991");
    pregunta.correcta = 'B';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 4 — CIENCIA
    pregunta.id=4;
    strcpy(pregunta.tema, "Ciencia");
    strcpy(pregunta.enunciado, "Quien propuso la teoria de la relatividad?");
    strcpy(pregunta.opcionA, "Einstein");
    strcpy(pregunta.opcionB, "Newton");
    strcpy(pregunta.opcionC, "Curie");
    strcpy(pregunta.opcionD, "Tesla");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 5 — DEPORTES
    pregunta.id=5;
    strcpy(pregunta.tema, "Deportes");
    strcpy(pregunta.enunciado, "Cuantos jugadores tiene un equipo de futbol?");
    strcpy(pregunta.opcionA, "9");
    strcpy(pregunta.opcionB, "10");
    strcpy(pregunta.opcionC, "11");
    strcpy(pregunta.opcionD, "12");
    pregunta.correcta = 'C';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 6 — LITERATURA
    pregunta.id=6;
    strcpy(pregunta.tema, "Literatura");
    strcpy(pregunta.enunciado, "Quien escribio 'Don Quijote'?");
    strcpy(pregunta.opcionA, "Cervantes");
    strcpy(pregunta.opcionB, "Borges");
    strcpy(pregunta.opcionC, "Shakespeare");
    strcpy(pregunta.opcionD, "Lope de Vega");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 7 — MUSICA
    pregunta.id=7;
    strcpy(pregunta.tema, "Musica");
    strcpy(pregunta.enunciado, "De que pais era Mozart?");
    strcpy(pregunta.opcionA, "Austria");
    strcpy(pregunta.opcionB, "Alemania");
    strcpy(pregunta.opcionC, "Francia");
    strcpy(pregunta.opcionD, "Polonia");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 8 — CINE
    pregunta.id=8;
    strcpy(pregunta.tema, "Cine");
    strcpy(pregunta.enunciado, "Quien dirigio la pelicula Titanic?");
    strcpy(pregunta.opcionA, "Spielberg");
    strcpy(pregunta.opcionB, "Cameron");
    strcpy(pregunta.opcionC, "Nolan");
    strcpy(pregunta.opcionD, "Scorsese");
    pregunta.correcta = 'B';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    // 9 — BIOLOGIA
    pregunta.id=9;
    strcpy(pregunta.tema, "Biologia");
    strcpy(pregunta.enunciado, "Donde ocurre la fotosintesis?");
    strcpy(pregunta.opcionA, "Cloroplastos");
    strcpy(pregunta.opcionB, "Mitocondrias");
    strcpy(pregunta.opcionC, "Ribosomas");
    strcpy(pregunta.opcionD, "Nucleo");
    pregunta.correcta = 'A';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);


    // 10 — TECNOLOGIA
    pregunta.id=10;
    strcpy(pregunta.tema, "Tecnologia");
    strcpy(pregunta.enunciado, "Quien fundo Microsoft?");
    strcpy(pregunta.opcionA, "Steve Jobs");
    strcpy(pregunta.opcionB, "Jeff Bezos");
    strcpy(pregunta.opcionC, "Elon Musk");
    strcpy(pregunta.opcionD, "Bill Gates");
    pregunta.correcta = 'D';
    fwrite(&pregunta, sizeof(Pregunta), 1, arch);

    fclose(arch);
}

void cargarPreguntasDesdeArchivo(Nodo** lista) {
	archivo = fopen("preguntas.dat", "rb");
	if (archivo == NULL) {
		printf("Error al abrir el archivo");
		return;
	}
	
	while(fread(&pregunta, sizeof(Pregunta), 1, archivo) == 1) {
		insertarAlFinal(lista, pregunta);
	}
	
	fclose(archivo);
}

