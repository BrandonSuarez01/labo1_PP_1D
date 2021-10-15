/*
 * Estadia-Perros.h
 *
 *  Created on: 10 oct. 2021
 *      Author: brans
 */

#ifndef ESTADIA_PERROS_H_
#define ESTADIA_PERROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Estadia.h"

/**
 * @fn void estadiaPerros_menuOpciones(sEstadiaDiaria[], int, int*, sPerro[], int*, float)
 * @brief recibe los parametros globales del main y permite acceder a las funciones del programa de forma ordenada.
 *
 * @param estadias permite el acceso al array de estadias.
 * @param opcionMenu recibe la varible global del mismo nombre.
 * @param idEstadia recibe por referencia la variable global de la id con sus modificaciones.
 * @param perros permite el acceso al array de perros.
 * @param contadorEstadias recibe por referencia la varible global con el mismo nombre con las modificaciones que reciba.
 * @param promedio recibe el promedio de la funcion perros_promediarEdad.
 */
void estadiaPerros_menuOpciones(sEstadiaDiaria estadias[],  int opcionMenu, int *idEstadia, sPerro perros[], int* contadorEstadias, float promedio);

#endif /* ESTADIA_PERROS_H_ */
