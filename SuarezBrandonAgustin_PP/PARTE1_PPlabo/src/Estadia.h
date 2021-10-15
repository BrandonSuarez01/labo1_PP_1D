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

#define TAMESTADIA 3
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
	char nombreDuenio[TAMNOMBREDOS];
	int telefonoContacto;
	int idPerro;
	int fechaDia;
	int fechaMes;
	int estado;

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
 * @fn int estadia_agregarUna(sEstadiaDiaria[], int, int*)
 * @brief permite agregar una estadia en base a una confirmacion y aumenta automaticamnte el valor del id.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 * @param id este recibe la variable global de idEstadia para autoincrementarla.
 * @return devuelve el valor 0 si se pudo realizar correctamente la carga de la estadia o -1 si hubo un error o no hay espacio.
 */
int estadia_agregarUna(sEstadiaDiaria estadias[], int tam, int* id);
/**
 * @fn int estadia_establecerEstadia(sEstadiaDiaria*, int, int)
 * @brief establece los valores de las estructuras en el array de estadias.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param i recibe el index de el array a cargar.
 * @param id recibe por referencia el idEstadia.
 * @return devuelve 0 si se confirmo la carga y -1 si se cancelo.
 */
int estadia_establecerEstadia(sEstadiaDiaria* estadias, int i, int id);
/**
 * @fn void estadia_ordenarEstadia(sEstadiaDiaria[], int)
 * @brief se encarga de ordenar la estadia en base a la fecha o nombre.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 */
void estadia_ordenarEstadia(sEstadiaDiaria estadias[], int tam);
/**
 * @fn void estadia_listarUna(sEstadiaDiaria*)
 * @brief muestra una estadia del array.
 *
 * @param estadias permite acceder a el array de estadias.
 */
void estadia_listarUna(sEstadiaDiaria* estadias);
/**
 * @fn void estadia_listarVarias(sEstadiaDiaria[], int)
 * @brief llama a la funcion listar una y muestra todo el array.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 */
void estadia_listarVarias(sEstadiaDiaria estadias[], int tam);
/**
 * @fn int estadia_borrarUna(sEstadiaDiaria[], int)
 * @brief permite borrar una estadia ingresada a travez del ID.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 * @return devuelve 0 si se pudo eliminar la estadia y -1 si hubo algun error o se cancelo.
 */
int estadia_borrarUna(sEstadiaDiaria estadias[], int tam);
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
/**
 * @fn void estadia_mostrarModificacion(sEstadiaDiaria[], int, char*)
 * @brief le muestra al usuario la estadia a modificar.
 *
 * @param estadias permite acceder a el array de estadias.
 * @param index recibe el index de la estadia a modicar.
 * @param mensaje recibe un mensaje para mostrar dentro de la funcion.
 */
void estadia_mostrarModificacion(sEstadiaDiaria estadias[], int index, char* mensaje);
/**
 * @fn int estadia_modificarUna(sEstadiaDiaria[], int)
 * @brief permite modificar varios parametros de una estructura (idPerro y telefonoContacto).
 *
 * @param estadias permite acceder a el array de estadias.
 * @param tam pasa el tamaño de las iteraciones que debe realizar la funcion.
 * @return devuelve 0 si se pudo modicar o -1 si no se pudo o se cancelo.
 */
int estadia_modificarUna(sEstadiaDiaria estadias[], int tam);

#endif /* ESTADIA_H_ */
