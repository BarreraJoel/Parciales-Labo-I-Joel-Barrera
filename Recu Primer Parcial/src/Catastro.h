/*
 * Catastro.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#ifndef CATASTRO_H_
#define CATASTRO_H_

typedef struct{
	int idCatastro;
	char localidad[20];
	int manzana;
	int parcela;
}eCatastro;

/**
 * @brief Lista un catastro
 *
 * @param catastro Catastro a imprimir
 */
void eCatastro_listarUno(eCatastro catastro);

/**
 * @brief Lista el array de catastros
 *
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 1 [OK]
 */
int eCatastro_listarTodos(eCatastro* aCatastros,int limiteCatastros);

/**
 * @brief Ordena el array en base a las localidades
 *
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 1 [OK]
 */
int eCatastro_ordenar(eCatastro* aCatastros,int limiteCatastros);

#endif /* CATASTRO_H_ */
