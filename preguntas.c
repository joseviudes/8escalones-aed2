#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "preguntas.h"

FILE *archPreguntas;

/*desarrollamos las funciones*/

/*abrimos el archivo txt*/
void abrirArchivoPreguntas(){
	
	archPreguntas = fopen("preguntas.txt", "r");
	if(archPreguntas == NULL){
		printf("No se pudo abrir archivo.\n");		
	}
}

/*leemos UNA pregunta del archivo*/
void leerPregunta(tPregunta * preguntas){
	
	fscanf(archPreguntas, "%[^;];%[^;];%[^;];%[^;];%c\n", 
	preguntas->texto, preguntas->opcionA, preguntas->opcionB, 
	preguntas->opcionC, &preguntas->correcta);
}

/*mostramos la pregunta*/
void mostrarPregunta(tPregunta preguntas){
	
	printf("\n%s\n\n", preguntas.texto);
	printf("A) %s\n", preguntas.opcionA);
	printf("B) %s\n", preguntas.opcionB);
	printf("C) %s\n", preguntas.opcionC);
}

int verificarRespuesta(tPregunta preguntas, char respuesta){
	
	respuesta = toupper(respuesta);
	
	if(respuesta == preguntas.correcta){
		printf("Respuesta correcta!\n");
		return 1;
	} else {
		return 0;
	}

}

/*para cerrar al finalizar*/
void cerrarArchivoPreguntas(){
	fclose(archPreguntas);
}
