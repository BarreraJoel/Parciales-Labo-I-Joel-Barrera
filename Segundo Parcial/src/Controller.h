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
 * @brief
 *
 * @param path
 * @param this
 * @return
 */
int controller_cargarArchivo(char* path, LinkedList* this);

/**
 * @brief
 *
 * @param this
 * @return
 */
int controller_imprimirLista(LinkedList* this);

/**
 * @brief
 *
 * @param this
 * @return
 */
int controller_asignarTotales(LinkedList* this);

/**
 * @brief
 *
 * @param this
 * @return
 */
int controller_filtrar(LinkedList* this);

/**
 * @brief
 *
 * @param this
 * @return
 */
int controller_ordenarServicios(LinkedList* this);

/**
 * @brief
 *
 * @param path
 * @param this
 * @return
 */
int controller_guardarArchivo(char* path, LinkedList* this);

#endif /* CONTROLLER_H_ */
