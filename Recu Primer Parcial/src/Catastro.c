/*
 * Catastro.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Catastro.h"

void eCatastro_listarUno(eCatastro catastro)
{
	printf("\n  %-8d  %-20s   %-10d   %d",catastro.idCatastro,catastro.localidad,catastro.manzana,catastro.parcela);
}

int eCatastro_listarTodos(eCatastro* aCatastros,int limiteCatastros)
{
	int retorno = -1;
	int i;

	if(aCatastros != NULL && limiteCatastros > 0)
	{
		printf("\n------------------------------------------------------");
		printf("\n***************** LISTADO DE CATASTROS **************");
		printf("\n------------------------------------------------------");
		printf("\n   ID      LOCALIDAD            MANZANA       PARCELA");
		printf("\n------------------------------------------------------");
		for(i = 0; i < limiteCatastros; i++)
		{
			eCatastro_listarUno((*(aCatastros+i)));
		}
		retorno = 1;
	}

	return retorno;
}

int eCatastro_ordenar(eCatastro* aCatastros,int limiteCatastros)
{
	int retorno = -1;
	int i;
	int j;
	eCatastro auxiliar;

	if(aCatastros != NULL && limiteCatastros > 0)
	{
		for(i = 0; i < limiteCatastros-1; i++)
		{
			for(j = i+1; j < limiteCatastros; j++)
			{
				if(strcmp((*(aCatastros+i)).localidad,(*(aCatastros+j)).localidad) > 0)
				{
					auxiliar = (*(aCatastros+i));
					(*(aCatastros+i)) = (*(aCatastros+j));
					(*(aCatastros+j)) = auxiliar;
				}
			}
		}
		retorno = 1;
	}

	return retorno;
}
