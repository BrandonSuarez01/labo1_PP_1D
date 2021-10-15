/*
Suarez Brandon:
Se necesita gestionar una guardería de perros, la cual cuidará a un perrito por día. Para eso se
deberá desarrollar lo siguiente:

ENTIDADES:

Perro:
● id
● nombre (máximo 21 caracteres)
● raza (máximo 21 caracteres)
● edad

EstadiaDiaria:

● id (comienza en 100000, autoincremental)
● nombreDuenio (cadena de caracteres) Validar
● telefonoContacto (sólo números) Validar
● idPerro (debe existir) Validar
● fecha (Validar día, mes y año)

DATOS PREVIOS:

El array de perros será hardcodeado.
Perros
1) 7000, Lobo, Sharpei, 2
2) 7001, Sheila, Golden, 12
3) 7002, Reina, Galgo, 13

MENÚ DE OPCIONES:

1. RESERVAR ESTADIA
2. MODIFICAR ESTADIA: Se ingresará el id, permitiendo en un submenú modificar:
● El teléfono de contacto
● El perro
3. CANCELAR ESTADÍA: Se ingresará el id de la estadía y se realizará una baja lógica.
4. LISTAR ESTADÍAS: Hacer un listado de las estadías ordenadas por fecha (las más
nuevas irán primero). Ante igualdad de fechas, se ordenará por el nombre del dueño.
5. LISTAR PERROS
6. Promedio de edad de los perros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Duenio.h"
#include "Perros.h"
#include "Estadia.h"
#include "Estadia-Perros.h"
#include "Duenio-Estadia.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu = 0;
	int idDuenio = 30005;
	int idEstadia = 100005;
	int contadorEstadias = 5;
	float promedio = 0;

	sPerro perros[TAMPERROS];
	sEstadiaDiaria estadias[TAMESTADIA];
	sDuenio duenios[TAMDUENIO];

	estadia_inicializarEstadia(estadias, TAMESTADIA);
	perros_hardCodear(perros, TAMPERROS);
	estadiaDuenio_hardCodear(duenios, TAMDUENIO, estadias);

	do
	{
		pedirEntero(&opcionMenu, "------------------Menu------------------\n"
									"1. RESERVAR ESTADIA.\n"
									"2. MODIFICAR ESTADIA.\n"
									"3. CANCELAR ESTADIA.\n"
									"4. LISTAR ESTADIAS.\n"
									"5. LISTAR PERROS.\n"
									"6. Promedio de edad de los perros.\n"
									"7. Perro con mas estadias reservadas.\n"
									"8. Salir.\n"
								"-----------------------------------------\n"
									"Ingrese la opcion deseada: ",
									"------------------Menu------------------\n"
									"1. RESERVAR ESTADIA.\n"
									"2. MODIFICAR ESTADIA.\n"
									"3. CANCELAR ESTADIA.\n"
									"4. LISTAR ESTADIAS.\n"
									"5. LISTAR PERROS.\n"
									"6. Promedio de edad de los perros.\n"
									"7. Perro con mas estadias reservadas.\n"
									"8. Salir.\n"
								"-----------------------------------------\n"
									"ERROR - Reingrese una opcion valida: ", 1, 7);

		switch(opcionMenu)
		{
			case 1 :
				if(estadiaDuenio_agregarUna(estadias, TAMESTADIA, &idEstadia, duenios, &idDuenio) == 0)
				{
					contadorEstadias++;
				}
				system("pause");
			break;
			case 2 :
				if(contadorEstadias > 0)
				{
					estadiaDuenio_modificarUna(estadias, TAMESTADIA, duenios);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia.\n");
				}
			break;
			case 3 :
				if(contadorEstadias > 0)
				{
					estadiaDuenio_borrarUna(estadias, TAMESTADIA, duenios);
					contadorEstadias--;
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia.\n");
				}
				system("pause");
			break;
			case 4 :
				if(contadorEstadias > 0)
				{
					estadiaDuenio_ordenarEstadia(estadias, TAMESTADIA, duenios);
					printf("Ordenando estadias...");
					system("pause");
					estadiaDuenio_listarUna(estadias, TAMESTADIA, duenios, TAMDUENIO);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia.\n");
				}

			break;
			case 5 :
				perros_listar(perros, TAMPERROS);
				system("pause");
			break;
			case 6 :
				promedio = perros_promediarEdad(perros, TAMPERROS);
				perros_mostrarPromedio(promedio);
			break;
			case 7 :
				estadiaPerro_masEstadiasReservadas(estadias, perros, TAMESTADIA, TAMPERROS);
			break;
		}


	}while(opcionMenu != 9);

	return EXIT_SUCCESS;
}
