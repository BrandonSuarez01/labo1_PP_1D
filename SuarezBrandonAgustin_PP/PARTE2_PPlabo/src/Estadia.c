/*
 * Estadia.c
 *
 *  Created on: 7 oct. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Duenio-Estadia.h"

void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		estadias[i].estado = VACIO;
	}
}
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
	{
		if(estadias[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int estadia_buscarPorId(sEstadiaDiaria estadias[], int tam, int id)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
		{
			if(estadias[i].estado == OCUPADO && estadias[i].id == id)
			{
				index = i;
				break;
			}
		}
	return index;
}
int estadia_verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

return retorno;
}

