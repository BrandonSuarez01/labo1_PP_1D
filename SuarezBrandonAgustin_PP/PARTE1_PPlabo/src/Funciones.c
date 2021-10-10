/*
 * Funciones.c
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Perros.h"
#include "Estadia.h"


int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	*enteroDevuelto = numeroIngresado;

	return 0;
}
void pedirString(char* nombre, char* primerMensaje, char* mensajeError, int max)
{
	char nombreSinValidar[100];
		int tam;

		printf("%s", primerMensaje);
		fflush(stdin);
		scanf("%[^\n]", nombreSinValidar);
		tam = strlen(nombreSinValidar);

		while(tam > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", nombreSinValidar);
			tam = strlen(nombreSinValidar);
		}

		strcpy(nombre, nombreSinValidar);
}
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max)
{
	float numeroIngresado;

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotanteDevuelto = numeroIngresado;

		return 0;
}
void pedirCaracter(char* caracter, char* mensaje)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", caracter);
}



