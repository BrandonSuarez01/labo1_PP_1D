/*
 * Estadia.h
 *
 *  Created on: 7 oct. 2021
 *      Author: brans
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Funciones.h"

#define TAMESTADIA 10
#define TAMNOMBREDOS 51
#define VACIO 1
#define OCUPADO 0
/**
 * @struct
 * @brief es la estructura que permite cargar una estadia.
 *
 */
typedef struct
{
	int id;
	int idPerro;
	int fechaDia;
	int fechaMes;
	int estado;
	int idDuenio;

}sEstadiaDiaria;

/**
 * @fn void estadia_inicializarEstadia(sEstadiaDiaria[], int)
 * @brief inicializa el estado de las estadias en 0 para que no tengan basura.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 */
void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam);
/**
 * @fn int estadia_buscarEspacio(sEstadiaDiaria[], int)
 * @brief busca un espacio disponible en el array .
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 * @return retorna el espacio vacio del array que encontro o -1 si no hay espacio disponible.
 */
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam);
/**
 * @fn int estadia_buscarPorId(sEstadiaDiaria[], int, int)
 * @brief busca una estadia en base al ID vinculado a esta.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 * @param i se usa como variable de control y de posicion del array.
 * @return devuelve el index si se pudo encontrar, sino devulve -1.
 */
int estadia_buscarPorId(sEstadiaDiaria estadias[], int tam, int i);
/**
 * @fn int estadia_verificarConfirmacion(char*)
 * @brief permite preguntar al usuario si desea seguir adelante con la accion que este realizando.
 *
 * @param mensaje recibe un mensaje a mostrar dentro de la funcion.
 * @return devulve 0 si el usuario dio una respuesta positiva y -1 si fue negativa.
 */
int estadia_verificarConfirmacion(char* mensaje);
#endif /* ESTADIA_H_ */
