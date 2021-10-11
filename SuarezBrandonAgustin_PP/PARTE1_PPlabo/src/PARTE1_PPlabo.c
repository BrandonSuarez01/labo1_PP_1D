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
#include "Perros.h"
#include "Estadia.h"
#include "Estadia-Perros.h"

;
int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu = 0;
	int idEstadia = 100000;
	int contadorEstadias = 0;
	float promedio = 0;

	sPerro perros[TAMPERROS];
	sEstadiaDiaria estadias[TAMESTADIA];

	estadia_inicializarEstadia(estadias, TAMESTADIA);
	perros_hardCodear(perros, TAMPERROS);
	estadiaPerros_menuOpciones(estadias, opcionMenu, &idEstadia, perros, &contadorEstadias, promedio);

	return EXIT_SUCCESS;
}
