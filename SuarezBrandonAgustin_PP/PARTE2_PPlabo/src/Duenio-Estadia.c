/*
 * Duenio-Estadia.c
 *
 *  Created on: 15 oct. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Duenio.h"
#include "Duenio-Estadia.h"

void estadiaDuenio_hardCodear(sDuenio duenios[], int tamDuenio, sEstadiaDiaria estadias[])
{
	int i;

	int idEstadia[] = {100000, 100001, 100002, 100003, 100004};
	int ids[] = {30000, 30001, 30002, 30003, 30004};
	char nombre[][TAMNOMBRETRES] = {"Jorge", "Marcos", "Marta", "Maria", "Esteban"};
	int telefono[] = {43981258, 43921345, 23456732, 98762123, 76542123};
	int fechaDia[] = {2, 3, 4, 4, 4};
	int fechaMes[] = {3, 4, 4, 5, 6};
	int idPerros[] = {7000, 7002, 7000, 7001, 7002};
	int idDuenios[] = {30000, 30001, 30002, 30003, 30004};

	for(i = 0; i < tamDuenio; i++)
	{
		estadias[i].id = idEstadia[i];
		duenios[i].id = ids[i];
		strcpy(duenios[i].nombre, nombre[i]);
		duenios[i].telefono = telefono[i];
		estadias[i].fechaDia = fechaDia[i];
		estadias[i].fechaMes = fechaMes[i];
		estadias[i].idPerro = idPerros[i];
		estadias[i].idDuenio = idDuenios[i];
		if(i != 5)
		{
			estadias[i].estado = OCUPADO;
		}
	}
}
int estadiaDuenio_agregarUna(sEstadiaDiaria estadias[], int tam, int* id, sDuenio duenios[], int* idDuenio)
{
	int retorno = -1;
	int index = estadia_buscarEspacio(estadias, tam);
	int idIncrementada = *id;
	int idIncrementadaDos = *idDuenio;

	if(index != -1)
	{
		if(!estadiaDuenio_establecerEstadia(estadias, index, *id, duenios, *idDuenio))
		{
			printf("Se establecio la estadia.\n");
			idIncrementada++;
			idIncrementadaDos++;
			*id = idIncrementada;
			*idDuenio = idIncrementada;

		}
		else
		{
			printf("Se cancelo la carga de la estadia.\n");
		}
		retorno = 0;
	}
	else
	{
		printf("NO hay espacio disponible.\n");
	}
	return retorno;
}
int estadiaDuenio_borrarUna(sEstadiaDiaria estadias[], int tam, sDuenio duenios[])
{
	int retorno = -1;
	int id;
	int index;

	pedirEntero(&id, "Ingrese el ID de la estadia que desea cancelar: ", "ERROR - Ese ID no existe, reingrese: ", 100000, 100003);
	index = estadia_buscarPorId(estadias, tam, id);

	estadiaDuenio_mostrarModificacion(estadias, index, "\nDesea eliminar la siguiente estadia?: \n", duenios);
	if(index != -1)
	{
		if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar la baja de la estadia: \n") == 0)
		{
			estadias[index].estado = VACIO;
			printf("\nEstadia de %d dada de baja correctamente!\n", estadias[index].id);
		}
		else
		{
			printf("\nSe cancelo la baja de la estadia\n");
		}
		retorno = 0;

	}
	else
	{
		printf("\nERROR - Estadia no encontrada...\n");
	}

	return retorno;
}
void estadiaDuenio_mostrarModificacion(sEstadiaDiaria estadias[], int index, char* mensaje, sDuenio duenios[])
{
	printf("%s", mensaje);
	if(estadias[index].idDuenio == duenios[index].id)
	{
		printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Telefono", "ID del Perro", "Fecha");
		printf("%-10d - %-20s - %-20d - %-20d - %d/%d\n", estadias[index].id, duenios[index].nombre, duenios[index].telefono, estadias[index].idPerro, estadias[index].fechaDia, estadias[index].fechaMes);
	}
}
void estadiaDuenio_listarUna(sEstadiaDiaria estadias[] ,int tamEstadias, sDuenio duenios[], int tamDuenios)
{
	for(int i = 0; i < tamEstadias; i++)
	{
		for(int j = 0; j < tamDuenios; j++)
		{
			if(estadias[i].idDuenio == duenios[j].id)
			{
				printf("%-10d - %-20s - %-20d - %-20d - %d/%d\n",
						estadias[i].id, duenios[j].nombre, duenios[j].telefono, estadias[i].idPerro, estadias[i].fechaDia, estadias[i].fechaMes);
				break;
			}
		}
	}

}
void estadiaDuenio_listarVarias(sEstadiaDiaria estadias[], int tam, sDuenio duenios[])
{
	int i;

	printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Telefono", "ID del Perro", "Fecha");
	for(i = 0; i < tam; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			estadiaDuenio_listarUna(&estadias[i],TAMESTADIA, &duenios[i], TAMDUENIO);
		}

	}
}
int estadiaDuenio_establecerEstadia(sEstadiaDiaria estadias[], int i, int id, sDuenio duenios[], int idDuenio)
{
	int retorno = -1;

	estadias[i].id = id;
	estadias[i].idDuenio = idDuenio;
	duenios[i].id = idDuenio;
	pedirString(duenios[i].nombre, "Ingrese el nombre del dueño: ", "ERROR - reingrese el nombre correctamente: ", TAMNOMBRETRES);
	pedirEntero(&duenios[i].telefono, "Ingrese el telefono del dueño(Hasta 8 digitos): ", "ERROR - reingrese el numero correctamente(Hasta 8 digitos): ", 10000000, 99999999);
	pedirEntero(&estadias[i].idPerro, "Ingrese el ID del perro deseado: ", "ERROR - reingrese el ID correctamente: ",7000, 7002);
	pedirEntero(&estadias[i].fechaDia, "Ingrese el dia deseado (1 - 30): ", "ERROR - Ingrese un dia valido (1 - 30): ", 1, 30);
	pedirEntero(&estadias[i].fechaMes, "Ingrese el mes deseado (1 - 12): ", "ERROR - Ingrese un mes valido (1 - 12): ", 1 , 12);

	estadiaDuenio_mostrarModificacion(estadias, i, "Desea agregar la siguiente estadia?: \n", duenios);
	if(estadia_verificarConfirmacion("\nIngrese 'S' para confirmar la carga de la estadia: ") == 0)
	{
		estadias[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}
int estadiaDuenio_modificarUna(sEstadiaDiaria estadias[], int tam, sDuenio duenios[])
{
	int retorno = -1;
	int opcionSubMenu;
	int idIngresada;
	int index;

	pedirEntero(&idIngresada, "Ingrese el ID de la estadia a modificar: ", "ERROR - Esa ID no existe, reingrese: ", 100000, 100003);
	index = estadia_buscarPorId(estadias, tam, idIngresada);

	pedirEntero(&opcionSubMenu, "----------MODIFICAR----------\n"
								"1. Modificar telefono\n"
								"2. Modificar id del Perro\n"
								"---------------------------\n"
								"Ingrese la opcion deseada: ",
								"----------MODIFICAR----------\n"
								"1. Modificar telefono\n"
								"2. Modificar id del Perro\n"
								"---------------------------\n"
								"ERROR - reingrese la opcion deseada: ", 1, 2);
	switch(opcionSubMenu)
	{
		case 1 :
			if(index != -1)
			{
				estadiaDuenio_mostrarModificacion(estadias, index, "Desea modificar el telefono de la siguiente estadia?: \n", duenios);
				if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirEntero(&duenios[index].telefono, "Ingrese el nuevo numero del cliente: ", "ERROR - Ese no es un numero valido, reingrese: ",10000000 , 99999999);
					printf("Numero modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion del telefono...\n");
				}
			retorno = 0;
			}
			system("pause");
		break;
		case 2 :
			if(index != -1)
			{
				estadiaDuenio_mostrarModificacion(estadias, index, "Desea modificar el ID del perro de la siguiente estadia?: \n", duenios);
				if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
				{
					pedirEntero(&estadias[index].idPerro, "Ingrese el nuevo ID del perro nuevo: ", "ERROR - Ese ID de perro no existe, reingrese: ", 7000, 7002);
					printf("ID del perro modificado correctamente...\n");
				}
				else
				{
					printf("Se cancelo la modificacion del ID del perro...\n");
				}
			}
			system("pause");
		break;
	}
	return retorno;
}
void estadiaDuenio_ordenarEstadia(sEstadiaDiaria estadias[], int tam, sDuenio duenios[])
{
	int flagSwap;
	int i;
	sEstadiaDiaria auxEstadia;
	int nuevoLimite;

	do
	{
		nuevoLimite = tam -1;
		flagSwap = 0;
		for(i = 0; i < nuevoLimite; i++)
		{
			if(estadias[i].fechaDia < estadias[i+1].fechaDia && estadias[i].fechaMes < estadias[i+1].fechaMes)
			{
				auxEstadia = estadias[i];
				estadias[i] = estadias[i+1];
				estadias[i+1]= auxEstadia;

				flagSwap = 1;

			}
			else
			{
				if(estadias[i].fechaDia == estadias[i+1].fechaDia && estadias[i].fechaMes == estadias[i+1].fechaMes)
				{
					if(strcmp(duenios[i].nombre, duenios[i+1].nombre) == 1)
					{
						auxEstadia = estadias[i];
						estadias[i] = estadias[i+1];
						estadias[i+1] = auxEstadia;

					}

				}
			}
		}

	}while(flagSwap);
}


