/*
 * Controller.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

/**
 * @brief Carga un archivo mediante una direccion pasada como parametro
 *
 * @param path Direccion del archivo a cargar
 * @param this LinkedList donde se cargaran los datos
 * @return (-1) Error: Lista NULL o path NULL
 * 		   ( 1) OK
 */
int controller_cargarArchivo(char* path, LinkedList* this);

/**
 * @brief Imprime la LinkedList
 *
 * @param this LinkedList a imprimir
 * @return (-1) Error: Lista NULL
 * 		   ( 1) OK
 */
int controller_imprimirLista(LinkedList* this);

/**
 * @brief Asigna los precios totales de los servicios
 *
 * @param this LinkedList a la cual se le asignaran los valores totales
 * @return (-1) Error: Lista NULL
 * 		   ( 1) OK
 */
int controller_asignarTotales(LinkedList* this);

/**
 * @brief Filtra una lista en base a condiciones
 *
 * @param this LinkedList que se filtrara
 * @return (-1) Error: Lista NULL
 * 		   ( 1) OK
 */
int controller_filtrar(LinkedList* this);

/**
 * @brief Ordena la lista alfabeticamente y de forma ascendente
 *
 * @param this LinkedList a ordenar
 * @return (-1) Error: Lista NULL
 * 		   ( 1) OK
 */
int controller_ordenarServicios(LinkedList* this);

/**
 * @brief Guarda los datos de la LinkedList en un archivo
 *
 * @param path Direccion del archivo donde se guardaran los datos
 * @param this LinkedList donde se guardaran los datos
 * @return (-1) Error: Lista NULL o path NULL
 * 		   ( 1) OK
 */
int controller_guardarArchivo(char* path, LinkedList* this);

#endif /* CONTROLLER_H_ */
