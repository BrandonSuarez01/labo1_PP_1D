/*
 * Duenio-Estadia.h
 *
 *  Created on: 15 oct. 2021
 *      Author: brans
 */

#ifndef DUENIO_ESTADIA_H_
#define DUENIO_ESTADIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Duenio.h"


int estadiaDuenio_agregarUna(sEstadiaDiaria estadias[], int tam, int* id, sDuenio duenios[], int* idDuenio);
void estadiaDuenio_hardCodear(sDuenio duenios[], int tamDuenio, sEstadiaDiaria estadias[]);
void estadiaDuenio_mostrarModificacion(sEstadiaDiaria estadias[], int index, char* mensaje, sDuenio duenios[]);
void estadiaDuenio_listarUna(sEstadiaDiaria estadias[],int tamEstadias, sDuenio duenios[], int tamDuenios);
int estadiaDuenio_modificarUna(sEstadiaDiaria estadias[], int tam, sDuenio duenios[]);
int estadiaDuenio_establecerEstadia(sEstadiaDiaria* estadias, int i, int id, sDuenio duenios[], int idDuenio);
void estadiaDuenio_listarVarias(sEstadiaDiaria estadias[], int tam, sDuenio duenios[]);
int estadiaDuenio_borrarUna(sEstadiaDiaria estadias[], int tam, sDuenio duenios[]);
void estadiaDuenio_ordenarEstadia(sEstadiaDiaria estadias[], int tam, sDuenio duenios[]);

#endif /* DUENIO_ESTADIA_H_ */
