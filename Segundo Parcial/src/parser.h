/*
 * parser.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#ifndef PARSER_H_
#define PARSER_H_

/**
 * @brief Carga los datos del archivo pasado como parametro
 *
 * @param pArchivo Puntero al archivo a leer
 * @param this LinkedList donde se almacenaran los datos leidos
 * @return Retorna (-1) Error: Parametros NULL
 *   	   		   ( 1) OK: Archivo cargado
 */
int parser_cargarDelArchivo(FILE* pArchivo,LinkedList* this);

/**
 * @brief Guarda la lista en un archivo de texto
 *
 * @param pArchivo Puntero al archivo a guardar
 * @param this LinkedList de donde se extraen los datos
 * @return Retorna (-1) Error: Parametros NULL
 *   	   		   ( 1) OK: Archivo guardado
 */
int parser_guardarAlArchivo(FILE* pArchivo,LinkedList* this);

#endif /* PARSER_H_ */
