/*
 * Informes.h
 *
 *  Created on: 18 jun. 2022
 *      Author: Joel Barrera
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Vivienda.h"
#include "Catastro.h"
#include "Censista.h"

/**
 * @brief
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @param aCensistas Puntero al array de censistas
 * @param limiteCensistas Largo del array de censistas
 */
void Informes_informar(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros,eCensista* aCensistas, int limiteCensistas);

/**
 * @brief Informa todos los datos de las viviendas en base a un tipo de vivienda
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @param aCensistas Puntero al array de censistas
 * @param limiteCensistas Largo del array de censistas
 */
void Informes_PorTipoDeVivienda(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas);

/**
 * @brief Informa todos los datos de las viviendas en base a una localidad
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @param aCensistas Puntero al array de censistas
 * @param limiteCensistas Largo del array de censistas
 */
void Informes_PorLocalidad(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas);

/**
 * @brief Informa la cantidad de viviendas censadas en la localidad de Avellaneda
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 */
void Informes_CantidadAvellaneda(eVivienda* aViviendas,int limiteViviendas);

/**
 * @brief Informa todos los datos de las viviendas censadas en base a un censista
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param aCatastros Puntero a un array de catastros
 * @param limiteCatastros Largo del array de catastros
 * @param aCensistas Puntero al array de censistas
 * @param limiteCensistas Largo del array de censistas
 */
void Informes_PorCensista(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas);

/**
 * @brief Informa la cantidad de viviendas tipo casa que fueron censadas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 */
void Informes_CantidadTipoCasa(eVivienda* aViviendas,int limiteViviendas);

/**
 * @brief Informa la cantidad de viviendas tipo departamenteo ubicado en la localidad de Lanus
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 */
void Informes_CantidadDeptosLanus(eVivienda* aViviendas,int limiteViviendas);

#endif /* INFORMES_H_ */
