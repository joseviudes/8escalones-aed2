/*acá vamos a CREAR el archivo txt de preguntas.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[50];

/*variables*/
FILE * archPreguntas;

tString texto, opcionA, opcionB, opcionC;
char correcta;
char continuar = 'S';

/*prototipos*/
void crearArchivoPreguntas();

int main(){
	crearArchivoPreguntas();
	return 0;
}

/*implementacion*/
void crearArchivoPreguntas(){
	
	archPreguntas = fopen("preguntas.txt", "w"); /*grabamos/creamos archivo*/
	
	if(archPreguntas == NULL){
		printf("No hay archivo.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("***Carga de Preguntas***\n");
	
	while(continuar == 'S' || continuar == 's'){
		
		printf("Ingrese la pregunta: \n");
		fflush(stdin);
		gets(texto);
		
		printf("Opcion A: \n");
		gets(opcionA);
		
		printf("Opcion B: \n");
		gets(opcionB);
		
		printf("Opcion C: \n");
		gets(opcionC);
		
		printf("Respuesta correcta: \n");
		scanf("%c", &correcta);
		
		/*linea de texto en el archivo:*/
		fprintf(archPreguntas, "%s;%s;%s;%s;%c\n", 
		texto, opcionA, opcionB, opcionC, correcta);
		
		printf("Seguir ingresando preguntas? (s (Si)- n (No) )\n");
		scanf(" %c", &continuar);
		fflush(stdin);
	}
	
	fclose(archPreguntas);
	
}
