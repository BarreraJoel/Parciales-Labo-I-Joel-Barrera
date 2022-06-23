/*
 * Vivienda.h
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include "Catastro.h"

#define MAX_CALLE 25
#define MAX_DESCRIPCION 20

typedef struct{
	int tipoVivienda;
	char descripcion[MAX_DESCRIPCION];
}tipoVivienda;

typedef struct{
	int idVivienda;
	char calle[MAX_CALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int idCatastro;
	int isEmpty;
}eVivienda;

/**
 * @brief Inicializa el array de viviendas en LIBRE[0]
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 0 [OK]
 */
int eVivienda_inicializarArray(eVivienda* aViviendas, int limite);

/**
 * @brief Busca la primera posicion libre del array y retorna su indice
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido - sin espacio] - Indice [OK]
 */
int eVivienda_getIndiceEspacioLibre(eVivienda* aViviendas, int limite);

/**
 * @brief Busca la posicion de la vivienda mediante un id ingresado y retorna el indice
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @param idBuscado ID ingresado
 * @return Retorna -1 [Puntero NULL - Largo no valido - ID no encontrado] - Indice [OK]
 */
int eVivienda_getIndicePorId(eVivienda* aViviendas, int limite, int idBuscado);

/**
 * @brief Da de alta a una vivienda dentro del array de viviendas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @param id Puntero a int que contiene el valor de ID
 * @return Retorna -1 [Puntero NULL - Largo no valido - Alta no completada] - 0 [OK]
 */
int eVivienda_alta(eVivienda* aViviendas, int limite, int* id);

/**
 * @brief Modifica un campo seleccionado de la vivienda
 *
 * @param pVivienda Puntero a estructura de tipo eVivienda
 * @param opcionModificar Opcion ingresada a modificar
 * @return Retorna -1 [Puntero NULL - Opcion no valida - Modificacion no completada] - 0 [OK]
 */
int eVivienda_modificarUno(eVivienda* pVivienda, int opcionModificar);

/**
 * @brief Permite el ingreso del ID de la vivienda y el campo a modificar
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @param contAltas Contador de altas que determina el maximo de ID
 * @return Retorna -1 [Punteros NULL - Largos no validos - Modificacion no completada] - 0 [OK]
 */
int eVivienda_modificar(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos,eCatastro* aCatastros, int limiteCatastros, int contAltas);

/**
 * @brief Da de baja una vivienda del array mediante un ID ingresado
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @param contAltas Contador de altas que determina el maximo de ID
 * @return Retorna -1 [Punteros NULL - Largos no validos - Baja no completada] - 0 [OK]
 */
int eVivienda_baja(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos,eCatastro* aCatastros, int limiteCatastros, int contAltas);

/**
 * @brief Ordena el array en base al nombre y la cantidad de personas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array de viviendas
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 0 [OK]
 */
int eVivienda_ordenador(eVivienda* aViviendas, int limite);

/**
 * @brief Lista una vivienda del array
 *
 * @param vivienda Vivienda a mostrar
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 */
void eVivienda_listarUno(eVivienda vivienda, tipoVivienda* aTipos, int limiteTipos, eCatastro* aCatastros,int limiteCatastros);

/**
 * @brief Lista el array de viviendas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @return Retorna -1 [Punteros NULL - Largos no validos] - 0 [OK]
 */
int eVivienda_listarTodos(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, eCatastro* aCatastros,int limiteCatastros);


#endif /* VIVIENDA_H_ */









