/*
 * Estadia-Perros.c
 *
 *  Created on: 10 oct. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Duenio.h"
#include "Perros.h"
#include "Estadia.h"
#include "Duenio-Estadia.h"


void estadiaPerro_masEstadiasReservadas(sEstadiaDiaria estadias[], sPerro perros[],int tamEstadias, int tamPerros)
{
	int i;
	int j;
	int contadorLobo = 0;
	int contadorSheila = 0;
	int contadorReina = 0;
	int idComparacion = 0;

	idComparacion = (*estadias).idPerro;

	for(i = 0; i < tamEstadias; i++)
	{
		for(j = 0; j > tamPerros; j++)
		{
			if(estadias[i].estado == OCUPADO && estadias[i].idPerro == perros[j].id)
			{
				switch(idComparacion)
				{
					case 7000 :
						contadorLobo++;
					break;
					case 7001 :
						contadorSheila++;
					break;
					case 7002 :
						contadorReina++;
					break;
				}
			}
		}

	}
	if(contadorLobo > contadorSheila && contadorLobo > contadorReina)
	{
		printf("El perrito con mayores estadias es 'Lobo' con ID: 7000.\n");

	}
	else
	{
		if(contadorSheila > contadorReina)
		{
			printf("El perrito con mayores estadias es 'Sheila' con ID: 7001.\n");

		}
		else
		{
			printf("El perrito con mayores estadias es 'Reina' con ID: 7002.\n");

		}
	}
}


