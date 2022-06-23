/*
 * parser.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Servicios.h"

int parser_cargarDelArchivo(FILE* pArchivo,LinkedList* this)
{
	int retorno = -1;
	char idAux[10];
	char descripcionAux[25];
	char tipoAux[5];
	char precioUniAux[10];
	char cantidadAux[10];
	char totalAux[10];
	eServicio* pElemento = NULL;

	if(pArchivo != NULL && this != NULL)
	{
		fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,descripcionAux,tipoAux,precioUniAux,cantidadAux,totalAux);

		do
		{
			if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,descripcionAux,tipoAux,precioUniAux,cantidadAux,totalAux) == 6)
			{
				pElemento = Servicio_newServicioParametros(idAux,descripcionAux,tipoAux,precioUniAux,cantidadAux,totalAux);
				if(pElemento != NULL)
				{
					ll_add(this, pElemento);
				}
			}
		}while(!feof(pArchivo));
		retorno = 1;
	}
	free(pElemento);

	return retorno;
}

int parser_guardarAlArchivo(FILE* pArchivo,LinkedList* this)
{
	int retorno = -1;
	int id;
	char descripcion[25];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
	int i;
	eServicio* pElemento = NULL;

	if(pArchivo != NULL && this != NULL)
	{
		for(i = 0; i < ll_len(this);i++)
		{
			pElemento = ll_get(this, i);
			if(pElemento != NULL)
			{
				if( Servicio_getId(pElemento, &id) == 0 &&
					Servicio_getDescripcion(pElemento, descripcion) == 0 &&
					Servicio_getTipo(pElemento, &tipo) == 0 &&
					Servicio_getPrecioUnitario(pElemento, &precioUnitario) == 0 &&
					Servicio_getCantidad(pElemento, &cantidad) == 0 &&
					Servicio_getTotalServicio(pElemento, &totalServicio) == 0)
				{
					fprintf(pArchivo,"%d,%s,%d,%.2f,%d,%.2f\n",id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
				}
			}
		}
		retorno = 1;
	}
	free(pElemento);

	return retorno;
}

