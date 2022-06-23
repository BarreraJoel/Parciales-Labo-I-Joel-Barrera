/*
 * Controller.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Servicios.h"
#include "input-UTN.h"
#include "Controller.h"

int controller_cargarArchivo(char* path,LinkedList* this)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path != NULL && this != NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			retorno = parser_cargarDelArchivo(pArchivo,this);
		}
	}
	fclose(pArchivo);

	return retorno;
}

int controller_imprimirLista(LinkedList* this)
{
	int retorno = -1;
	int i;

	if(this != NULL)
	{
		printf("\n-------------------------------------------------------------------------------------------\n");
		printf("********************************** LISTADO DE SERVICIOS   *********************************");
		printf("\n-------------------------------------------------------------------------------------------\n");
		printf(" ID        DESCRIPCION              TIPO      PRECIO UNITARIO   CANTIDAD    TOTAL SERVICIO");
		printf("\n-------------------------------------------------------------------------------------------\n");
		for(i = 0; i < ll_len(this);i++)
		{
			Servicio_imprimirUno(ll_get(this, i));
		}
		retorno = 1;
	}

	return retorno;
}

int controller_asignarTotales(LinkedList* this)
{
	int retorno = -1;
	void (*pFunc)(void* element);

	if(this != NULL)
	{
		pFunc = Servicio_calcularTotal;
		ll_map(this, pFunc);
		retorno = 1;
	}

	return retorno;
}

int controller_filtrar(LinkedList* this)
{
	int retorno = -1;
	int opcionFiltrar;
	int(*pFunc)(void* element);
	LinkedList* listaFiltrada = ll_newLinkedList();

	if(this != NULL)
	{
		if(utn_getNumeroEntero(&opcionFiltrar, "\n*** OPCIONES DE FILTRADO ***"
											"\n1.MINORISTA"
											"\n2.MAYORISTA"
											"\n3.EXPORTAR"
											"\nIngrese un tipo para filtrar: ","\nLa opcion ingresada no es valida\n",1,3,3) == 1)
		{
			switch(opcionFiltrar)
			{
				case 1:
					pFunc = Servicio_filtrarPorTipoMinorista;
					listaFiltrada = ll_filter(this, pFunc);
					break;
				case 2:
					pFunc = Servicio_filtrarPorTipoMayorista;
					listaFiltrada = ll_filter(this, pFunc);
					break;
				case 3:
					pFunc = Servicio_filtrarPorTipoExportar;
					listaFiltrada = ll_filter(this, pFunc);
					break;
			}
			if(listaFiltrada != NULL && controller_guardarArchivo("dataFiltrada.csv", listaFiltrada) == 1)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int controller_ordenarServicios(LinkedList* this)
{
	int retorno = -1;
	int (*pFunc)(void*,void*);

	if(this != NULL)
	{
		pFunc = Servicio_compararDescripcion;
		retorno = ll_sort(this, pFunc, 1);
	}

	return retorno;
}

int controller_guardarArchivo(char* path, LinkedList* this)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path != NULL && this != NULL)
	{
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL)
		{
			retorno = parser_guardarAlArchivo(pArchivo,this);
		}
	}
	fclose(pArchivo);

	return retorno;
}

