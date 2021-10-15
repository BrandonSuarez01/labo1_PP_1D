/*
 * Perros.h
 *
 *  Created on: 7 oct. 2021
 *      Author: brans
 */

#ifndef PERROS_H_
#define PERROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Funciones.h"

#define TAMNOMBRE 21
#define TAMPERROS 3
/**
 * @struct
 * @brief es la estructura que contiene los datos de un perro.
 *
 */
typedef struct
{
	int id;
	char nombre[TAMNOMBRE];
	char raza [TAMNOMBRE];
	int edad;
}sPerro;
/**
 * @fn void perros_hardCodear(sPerro[], int)
 * @brief hardcodea los perros dandole valor a las estructuras.
 *
 * @param perros permite el acceso al array de perros.
 * @param tam establece las iteraciones que realizara la funcion.
 */
void perros_hardCodear(sPerro perros[], int tam);
/**
 * @fn void perros_listar(sPerro[], int)
 * @brief lista los perros hardcodeados anteriormente.
 *
 * @param perros permite el acceso al array de perros.
 * @param tam establece las iteraciones que realizara la funcion.
 */
void perros_listar(sPerro perros[], int tam);
/**
 * @fn float perros_promediarEdad(sPerro[], int)
 * @brief calcula el promedio de la edad de todos los perros.
 *
 * @param perros permite el acceso al array de perros.
 * @param tam establece las iteraciones que realizara la funcion.
 * @return devulve el promedio obtenido.
 */
float perros_promediarEdad(sPerro perros[], int tam);
/**
 * @fn void perros_mostrarPromedio(float)
 * @brief muestra el promedio que recibe por parametro
 *
 * @param promedio es el promedio a mostrar por la funcion.
 */
void perros_mostrarPromedio(float promedio);
#endif /* PERROS_H_ */
