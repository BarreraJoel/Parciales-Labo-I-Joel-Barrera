/*
 * Servicios.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"

eServicio* Servicio_newServicio(void)
{
	eServicio* pNuevoElemento = NULL;

	pNuevoElemento = (eServicio*)malloc(sizeof(eServicio));

	return pNuevoElemento;
}

eServicio* Servicio_newServicioParametros(char* idStr,char* descripcion,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
	eServicio* pNuevoElemento = NULL;

	if(idStr != NULL && descripcion != NULL && tipoStr != NULL && precioUnitarioStr != NULL && cantidadStr != NULL && totalServicioStr != NULL)
	{
		pNuevoElemento = Servicio_newServicio();
		if(pNuevoElemento != NULL)
		{
			if( Servicio_setId(pNuevoElemento,atoi(idStr)) != 0 ||
				Servicio_setDescripcion(pNuevoElemento,descripcion) != 0 ||
				Servicio_setTipo(pNuevoElemento,atoi(tipoStr)) != 0 ||
				Servicio_setPrecioUnitario(pNuevoElemento,atof(precioUnitarioStr)) != 0 ||
				Servicio_setCantidad(pNuevoElemento,atoi(cantidadStr)) != 0 ||
				Servicio_setTotalServicio(pNuevoElemento,atof(totalServicioStr)) != 0)
			{
				free(pNuevoElemento);
				pNuevoElemento = NULL;
			}
		}
	}

	return pNuevoElemento;
}

void Servicio_imprimirUno(eServicio* pElemento)
{
	int idAux;
	char descripcion[25];
	int tipoServicio;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	if(pElemento != NULL)
	{
		if( Servicio_getId(pElemento, &idAux) == 0 &&
			Servicio_getDescripcion(pElemento, descripcion) == 0 &&
			Servicio_getTipo(pElemento, &tipoServicio) == 0 &&
			Servicio_getPrecioUnitario(pElemento, &precioUnitario) == 0 &&
			Servicio_getCantidad(pElemento, &cantidad) == 0 &&
			Servicio_getTotalServicio(pElemento, &totalServicio) == 0)
		{
			printf("\n %-8d  %-26s %-10d   %-8.2f   %8d   %13.2f",idAux,descripcion,tipoServicio,precioUnitario,cantidad,totalServicio);

		}
	}
}

void Servicio_calcularTotal(void* element)
{
	int auxCantidad;
	float auxPrecio;
	float calculoTotal;

	if(element != NULL)
	{
		if( Servicio_getCantidad(element, &auxCantidad) == 0 &&
			Servicio_getPrecioUnitario(element, &auxPrecio) == 0)
		{
			calculoTotal = (float)auxCantidad * auxPrecio ;
			Servicio_setTotalServicio(element, calculoTotal);
		}
	}
}

int Servicio_filtrarPorTipoMinorista(void* element)
{
	int retorno = -1;
	int auxTipo;

	if(element != NULL)
	{
		retorno = 0;
		if(Servicio_getTipo(element, &auxTipo) == 0 && auxTipo == 1)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int Servicio_filtrarPorTipoMayorista(void* element)
{
	int retorno = -1;
	int auxTipo;

	if(element != NULL)
	{
		retorno = 0;
		if(Servicio_getTipo(element, &auxTipo) == 0 && auxTipo == 2)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int Servicio_filtrarPorTipoExportar(void* element)
{
	int retorno = -1;
	int auxTipo;

	if(element != NULL)
	{
		retorno = 0;
		if(Servicio_getTipo(element, &auxTipo) == 0 && auxTipo == 3)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int Servicio_compararDescripcion(void* pElementoUno, void* pElementoDos)
{
	int retorno = -1;
	char auxDesc[25];
	char auxDescDos[25];

	if(pElementoUno != NULL && pElementoDos != NULL)
	{
		if( Servicio_getDescripcion((eServicio*)pElementoUno,auxDesc) == 0 &&
			Servicio_getDescripcion((eServicio*)pElementoDos,auxDescDos) == 0)
		{
			retorno = strcmp(auxDesc,auxDescDos);
		}
	}

	return retorno;
}

int Servicio_setId(eServicio* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->idServicio = id;
		retorno = 0;
	}
	return retorno;
}

int Servicio_getId(eServicio* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idServicio;
		retorno = 0;
	}
	return retorno;
}

int Servicio_setDescripcion(eServicio* this, char* descripcion)
{
	int retorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;
}

int Servicio_getDescripcion(eServicio* this, char* descripcion)
{
	int retorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}
	return retorno;
}

int Servicio_setTipo(eServicio* this,int tipoServicio)
{
	int retorno = -1;

	if(this != NULL && tipoServicio > 0 && tipoServicio <= 3)
	{
		this->tipoServicio = tipoServicio;
		retorno = 0;
	}
	return retorno;
}

int Servicio_getTipo(eServicio* this,int* tipoServicio)
{
	int retorno = -1;

	if(this != NULL && tipoServicio != NULL)
	{
		*tipoServicio = this->tipoServicio;
		retorno = 0;
	}
	return retorno;
}

int Servicio_setPrecioUnitario(eServicio* this, float precioUnitario)
{
	int retorno = -1;

	if(this != NULL && precioUnitario > 0)
	{
		this->precioUnitario = precioUnitario;
		retorno = 0;
	}
	return retorno;
}

int Servicio_getPrecioUnitario(eServicio* this, float* precioUnitario)
{
	int retorno = -1;

	if(this != NULL && precioUnitario != NULL)
	{
		*precioUnitario = this->precioUnitario;
		retorno = 0;
	}
	return retorno;
}

int Servicio_setCantidad(eServicio* this,int cantidad)
{
	int retorno = -1;

	if(this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		retorno = 0;
	}
	return retorno;
}

int Servicio_getCantidad(eServicio* this,int* cantidad)
{
	int retorno = -1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 0;
	}
	return retorno;
}

int Servicio_setTotalServicio(eServicio* this,float totalServicio)
{
	int retorno = -1;

	if(this != NULL && totalServicio >= 0)
	{
		this->totalServicio = totalServicio;
		retorno = 0;
	}
	return retorno;
}

int Servicio_getTotalServicio(eServicio* this,float* totalServicio)
{
	int retorno = -1;

	if(this != NULL && totalServicio != NULL)
	{
		*totalServicio = this->totalServicio;
		retorno = 0;
	}
	return retorno;
}


