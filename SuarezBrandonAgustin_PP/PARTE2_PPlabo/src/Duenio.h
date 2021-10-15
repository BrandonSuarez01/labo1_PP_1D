/*
 * Dueño.h
 *
 *  Created on: 15 oct. 2021
 *      Author: brans
 */

#ifndef DUENIO_H_
#define DUENIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"

#define TAMNOMBRETRES 41
#define TAMDUENIO 10

typedef struct
{
	int id;
	char nombre[TAMNOMBRETRES];
	int telefono;
}sDuenio;

#endif /* DUENIO_H_ */
