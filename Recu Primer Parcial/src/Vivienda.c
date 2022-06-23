/*
 * Vivienda.c
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Vivienda.h"
#include "input-UTN.h"
#include "Censista.h"

#define LIBRE 0
#define OCUPADO 1

void eVivienda_listarUno(eVivienda vivienda, tipoVivienda* aTipos, int limiteTipos, eCatastro* aCatastros,int limiteCatastros)
{
	int i;
	int j;

	if(aTipos != NULL && limiteTipos > 0 && aCatastros != NULL && limiteCatastros)
	{
		for(i = 0; i < limiteTipos; i++)
		{
			for(j = 0; j < limiteCatastros; j++)
			{
				if(vivienda.isEmpty == OCUPADO )
				{
					if(vivienda.tipoVivienda == (*(aTipos+i)).tipoVivienda)
					{
						if(vivienda.idCatastro == (*(aCatastros+j)).idCatastro)
						{
							printf("%-8d  %-25s %d %15d     %15s  %10d   %19s\n",vivienda.idVivienda,vivienda.calle,vivienda.cantidadPersonas,vivienda.cantidadHabitaciones,(*(aTipos+i)).descripcion,vivienda.legajoCensista,(*(aCatastros+i)).localidad);
						}
					}
				}
			}
		}
	}
}

int eVivienda_listarTodos(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, eCatastro* aCatastros,int limiteCatastros)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && aCatastros != NULL && limiteCatastros)
	{
		printf("\n\n------------------------------------------------------------------------------------------------------------\n");
		printf("****************************************** LISTADO DE VIVIENDAS *******************************************");
		printf("\n------------------------------------------------------------------------------------------------------------\n");
		printf(" ID            CALLE          CANT.PERSONAS   HABITACIONES   TIPO VIVIENDA   LEGAJO CENSISTA      LOCALIDAD   ");
		printf("\n------------------------------------------------------------------------------------------------------------\n");
		for(i = 0; i < limiteViviendas; i++)
		{
			eVivienda_listarUno((*(aViviendas+i)), aTipos, limiteTipos, aCatastros,limiteCatastros);
		}
		retorno = 0;
	}
	return retorno;
}

int eVivienda_inicializarArray(eVivienda* aViviendas, int limite)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			(*(aViviendas+i)).isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

int eVivienda_getIndiceEspacioLibre(eVivienda* aViviendas, int limite)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if((*(aViviendas+i)).isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eVivienda_getIndicePorId(eVivienda* aViviendas, int limite, int idBuscado)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limite > 0 && idBuscado >= 20000)
	{
		for(i = 0; i < limite; i++)
		{
			if((*(aViviendas+i)).isEmpty == OCUPADO && (*(aViviendas+i)).idVivienda == idBuscado)
			{
				retorno = i;
				break;
			}
		}
		if(retorno == -1)
		{
			printf("\nEl ID ingresado no es valido\n");
		}
	}
	return retorno;
}

int eVivienda_alta(eVivienda* aViviendas, int limiteViviendas, int* id)
{
	int retorno = -1;
	int indiceLibre;
	eVivienda auxiliar;

	if(aViviendas != NULL && limiteViviendas > 0 && id != NULL)
	{
		indiceLibre = eVivienda_getIndiceEspacioLibre(aViviendas, limiteViviendas);

		if(indiceLibre >= 0 && indiceLibre < limiteViviendas)
		{
			if( utn_getCalle(auxiliar.calle,"\nIngrese la calle: ","\nLa calle ingresada no es valida\n",4,MAX_CALLE,3) == 1 &&
				utn_getNumeroEntero(&auxiliar.cantidadPersonas,"\nIngrese la cantidad de personas que habitan el hogar: ","\nLa cantidad ingresada no es valida\n",1,10,3) == 1 &&
				utn_getNumeroEntero(&auxiliar.cantidadHabitaciones,"\nIngrese la cantidad de habitaciones del hogar: ","\nLa cantidad ingresada no es valida\n",1,5,3) == 1 &&
				utn_getNumeroEntero(&auxiliar.tipoVivienda,"\nTIPO DE VIVIENDA\n1.CASA\n2.DEPARTAMENTO\n3.CASILLA\n4.RANCHO\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,4,3) == 1 &&
				utn_getNumeroEntero(&auxiliar.legajoCensista,"\nIngrese el legajo de censista: ","\nEl legajo ingresado no es valido\n",100,102,3) == 1 &&
				utn_getNumeroEntero(&auxiliar.idCatastro, "\nIngrese el ID del catastro: ", "\nEl ID ingresado no es valido\n",1000,1004, 3) == 1)
			{
				auxiliar.idVivienda = *id;
				auxiliar.isEmpty = OCUPADO;
				(*(aViviendas+indiceLibre)) = auxiliar;
				(*id)++;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int eVivienda_modificarUno(eVivienda* pVivienda, int opcionModificar)
{
	int retorno = -1;
	eVivienda auxiliar;

	if(pVivienda != NULL && opcionModificar > 0)
	{
		switch(opcionModificar)
		{
			case 1:
				if(utn_getCalle(auxiliar.calle,"\nIngrese la calle: ","\nLa calle ingresada no es valida\n",4,MAX_CALLE,3) == 1)
				{
					strcpy(pVivienda->calle,auxiliar.calle);
					retorno = 0;
				}
				break;
			case 2:
				if(utn_getNumeroEntero(&auxiliar.cantidadPersonas,"\nIngrese la cantidad de personas del hogar: ","\nLa cantidad ingresada no es valida\n",1,10,3) == 1)
				{
					pVivienda->cantidadPersonas = auxiliar.cantidadPersonas;
					retorno = 0;
				}
				break;
			case 3:
				if(utn_getNumeroEntero(&auxiliar.cantidadHabitaciones,"\nIngrese la cantidad de habitaciones del hogar: ","\nLa cantidad ingresada no es valida\n",1,5,3) == 1)
				{
					pVivienda->cantidadHabitaciones = auxiliar.cantidadHabitaciones;
					retorno = 0;
				}
				break;
			case 4:
				if(utn_getNumeroEntero(&auxiliar.tipoVivienda,"\nTIPO DE VIVIENDA\n1.CASA\n2.DEPARTAMENTO\n3.CASILLA\n4.RANCHO\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,4,3) == 1)
				{
					pVivienda->tipoVivienda = auxiliar.tipoVivienda;
					retorno = 0;
				}
				break;
			case 5:
				break;
			default:
				break;
		}
	}
	return retorno;
}

int eVivienda_modificar(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, eCatastro* aCatastros, int limiteCatastros, int contAltas)
{
	int retorno = -1;
	int idIngresado;
	int opcionModificacion;
	int indiceId;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && aCatastros != NULL && limiteCatastros > 0 && contAltas > 0)
	{
		eVivienda_listarTodos(aViviendas, limiteViviendas, aTipos, limiteTipos,aCatastros,limiteCatastros);
		if(utn_getNumeroEntero(&idIngresado,"\nIngrese el ID de la vivienda a modificar: ","\nEl ID ingresado no es valido\n",20000,19999+contAltas,3) == 1)
		{
			indiceId = eVivienda_getIndicePorId(aViviendas,limiteViviendas,idIngresado);
			if(indiceId >= 0)
			{
				do
				{
					printf("\n\n------------------------------------------------------------------------------------------------------------\n");
					printf("**************************************** DATOS DE LA DE VIVIENDA *******************************************");
					printf("\n------------------------------------------------------------------------------------------------------------\n");
					printf(" ID            CALLE          CANT.PERSONAS   HABITACIONES   TIPO VIVIENDA   LEGAJO CENSISTA      LOCALIDAD   ");
					printf("\n------------------------------------------------------------------------------------------------------------\n");
					eVivienda_listarUno((*(aViviendas+indiceId)), aTipos, limiteTipos,aCatastros,limiteCatastros);
					if(utn_getNumeroEntero(&opcionModificacion, "\nMENU DE MODIFICACION"
																"\n1.MODIFICAR CALLE"
																"\n2.MODIFICAR CANTIDAD DE PERSONAS"
																"\n3.MODIFICAR CANTIDAD DE HABITACIONES"
																"\n4.MODIFICAR TIPO DE VIVIENDA"
																"\n5.SALIR"
																"\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,5,3) == 1)
					{
						if(eVivienda_modificarUno((aViviendas+indiceId),opcionModificacion) == 0)
						{
							printf("\n*** La modificacion se realizo con exito ***\n");
							retorno = 0;
						}
					}
				}while(opcionModificacion != 5);
			}
		}
	}
	return retorno;
}

int eVivienda_baja(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos,eCatastro* aCatastros, int limiteCatastros, int contAltas)
{
	int retorno = -1;
	int idIngresado;
	int indiceId;
	int confirmacion;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && aCatastros != NULL && limiteCatastros > 0 && contAltas > 0)
	{
		eVivienda_listarTodos(aViviendas, limiteViviendas, aTipos, limiteTipos,aCatastros,limiteCatastros);
		if(utn_getNumeroEntero(&idIngresado,"\nIngrese el numero del ID a dar de baja: ","\nEl ID ingresado no es valido\n",20000,19999+contAltas,3) == 1)
		{
			indiceId = eVivienda_getIndicePorId(aViviendas,limiteViviendas,idIngresado);

			if(indiceId >= 0)
			{
				printf("\n\n------------------------------------------------------------------------------------------------------------\n");
				printf("**************************************** DATOS DE LA DE VIVIENDA *******************************************");
				printf("\n------------------------------------------------------------------------------------------------------------\n");
				printf(" ID            CALLE          CANT.PERSONAS   HABITACIONES   TIPO VIVIENDA   LEGAJO CENSISTA      LOCALIDAD   ");
				printf("\n------------------------------------------------------------------------------------------------------------\n");
				eVivienda_listarUno((*(aViviendas+indiceId)), aTipos, limiteTipos,aCatastros,limiteCatastros);
				if(utn_getNumeroEntero(&confirmacion,"\nEsta seguro/a que quiere dar de baja la vivienda?\n1.SI\n2.NO\nElija una opcion: ",
													 "\nLa opcion ingresada no es valida\n",1,2,3) == 1 && confirmacion == 1)
				{
					(*(aViviendas+indiceId)).isEmpty = LIBRE;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int eVivienda_ordenador(eVivienda* aViviendas, int limite)
{
	int retorno = -1;
	int i;
	int j;
	eVivienda auxiliar;

	if(aViviendas != NULL && limite > 0)
	{
		retorno = 1;

		for(i = 0; i < limite-1; i++)
		{
			for(j = i+1; j < limite; j++)
			{
				if((*(aViviendas+i)).isEmpty == LIBRE || (*(aViviendas+j)).isEmpty == LIBRE)
				{
					continue;
				}
				if(strcmp((*(aViviendas+i)).calle,(*(aViviendas+j)).calle) > 0)
				{
					auxiliar = (*(aViviendas+i));
					(*(aViviendas+i)) = (*(aViviendas+j));
					(*(aViviendas+j)) = auxiliar;
				}
				else if(strcmp((*(aViviendas+i)).calle,(*(aViviendas+j)).calle) == 0)
				{
					if((*(aViviendas+i)).cantidadPersonas > (*(aViviendas+j)).cantidadPersonas)
					{
						auxiliar = (*(aViviendas+i));
						(*(aViviendas+i)) = (*(aViviendas+j));
						(*(aViviendas+j)) = auxiliar;
					}
				}
			}
		}
	}
	return retorno;
}







