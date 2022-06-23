/*
 * Informes.c
 *
 *  Created on: 18 jun. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>
#include <stdlib.h>
#include "Vivienda.h"
#include "input-UTN.h"
#include "Informes.h"

void Informes_PorTipoDeVivienda(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas)
{
	int i;
	int j;
	int k;

	printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("************************************************** VIVIENDAS DE TIPO DEPARTAMENTO *****************************************************");
	printf("\n---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" ID            CALLE          CANT.PERSONAS   HABITACIONES    TIPO VIVIENDA    CENSISTA   CATASTRO     LOCALIDAD      MANZANA  PARCELA");
	printf("\n---------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i < limiteViviendas;i++)
	{
		for(j = 0; j < limiteCatastros; j++)
		{
			for(k = 0; k < limiteCensistas; k++)
			{
				if( (*(aViviendas+i)).tipoVivienda == 2 &&
					(*(aViviendas+i)).legajoCensista == (*(aCensistas+k)).legajoCensista &&
					(*(aViviendas+i)).idCatastro == (*(aCatastros+j)).idCatastro)
				{
						printf("%-8d  %-25s %d %15d     %15s  %10s      %-10d %8s %10d %8d\n",
						(*(aViviendas+i)).idVivienda,(*(aViviendas+i)).calle,(*(aViviendas+i)).cantidadPersonas,(*(aViviendas+i)).cantidadHabitaciones,
						(*(aTipos+1)).descripcion,(*(aCensistas+k)).nombre,(*(aCatastros+j)).idCatastro,(*(aCatastros+j)).localidad,
						(*(aCatastros+j)).manzana,(*(aCatastros+j)).parcela);
				}
			}
		}
	}
}

void Informes_PorLocalidad(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas)
{
	int i;
	int j;
	int k;

	printf("\n\n--------------------------------------------------------------------------------------------------------------------\n");
	printf("***************************************** VIVIENDAS DE LA LOCALIDAD AVELLANEDA ***************************************");
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ID            CALLE          CANT.PERSONAS   HABITACIONES    TIPO VIVIENDA    CENSISTA   CATASTRO   MANZANA  PARCELA");
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i < limiteViviendas;i++)
	{
		for(j = 0; j < limiteTipos; j++)
		{
			for(k = 0; k < limiteCensistas; k++)
			{
				if( (*(aViviendas+i)).tipoVivienda == (*(aTipos+j)).tipoVivienda &&
					(*(aViviendas+i)).legajoCensista == (*(aCensistas+k)).legajoCensista &&
					(*(aViviendas+i)).idCatastro == 1000)
				{
					printf("%-8d  %-25s %d %16d        %-10s  %11s      %-10d %d %8d\n",
					(*(aViviendas+i)).idVivienda,(*(aViviendas+i)).calle,(*(aViviendas+i)).cantidadPersonas,
					(*(aViviendas+i)).cantidadHabitaciones,(*(aTipos+j)).descripcion,(*(aCensistas+k)).nombre,
					(*(aCatastros)).idCatastro,(*(aCatastros)).manzana,(*(aCatastros)).parcela);
				}
			}
		}
	}
}

void Informes_CantidadAvellaneda(eVivienda* aViviendas,int limiteViviendas)
{
	int i;
	int contadorCasasCensadas = 0;

	for(i = 0; i < limiteViviendas; i++)
	{
		if((*(aViviendas+i)).idCatastro == 1000)
		{
			contadorCasasCensadas++;
		}
	}
	printf("\n*** La cantidad de casas censadas en la localidad de Avellaneda es: %d ***\n",contadorCasasCensadas);
}

void Informes_PorCensista(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas)
{
	int i;
	int j;
	int k;

	printf("\n\n---------------------------------------------------------------------------------------------------------------------------\n");
	printf("************************************************ VIVIENDAS CENSDADAS POR SOL ************************************************");
	printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
	printf(" ID            CALLE          CANT.PERSONAS   HABITACIONES   TIPO VIVIENDA    CATASTRO      LOCALIDAD      MANZANA   PARCELA ");
	printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i < limiteViviendas;i++)
	{
		for(j = 0; j < limiteTipos; j++)
		{
			for(k = 0; k < limiteCatastros; k++)
			{
				if((*(aViviendas+i)).legajoCensista == 102)
				{
					if((*(aViviendas+i)).tipoVivienda == (*(aTipos+j)).tipoVivienda)
					{
						if((*(aViviendas+i)).idCatastro == (*(aCatastros+k)).idCatastro)
						{
							printf("%-8d  %-25s %d %15d     %15s  %10d   %17s %8d %8d\n",
							(*(aViviendas+i)).idVivienda,(*(aViviendas+i)).calle,(*(aViviendas+i)).cantidadPersonas,(*(aViviendas+i)).cantidadHabitaciones,(*(aTipos+j)).descripcion,
							(*(aCatastros+k)).idCatastro,(*(aCatastros+k)).localidad,(*(aCatastros+k)).manzana,(*(aCatastros+k)).parcela);
						}
					}
				}
			}
		}
	}
}

void Informes_CantidadTipoCasa(eVivienda* aViviendas,int limiteViviendas)
{
	int i;
	int contadorTipoCasa = 0;

	for(i = 0; i < limiteViviendas; i++)
	{
		if((*(aViviendas+i)).tipoVivienda == 1)
		{
			contadorTipoCasa++;
		}
	}
	printf("\n*** La cantidad de viviendas tipo CASA censadas es: %d ***\n",contadorTipoCasa);
}

void Informes_CantidadDeptosLanus(eVivienda* aViviendas,int limiteViviendas)
{
	int i;
	int contadorDeptosLanus = 0;

	for(i = 0; i < limiteViviendas; i++)
	{
		if((*(aViviendas+i)).tipoVivienda == 2 && (*(aViviendas+i)).idCatastro == 1001)
		{
			contadorDeptosLanus++;
		}
	}
	printf("\n*** La cantidad de viviendas tipo DEPARTAMENTO en la localidad de Lanus es: %d ***\n",contadorDeptosLanus);
}

void Informes_informar(eVivienda* aViviendas,int limiteViviendas,tipoVivienda* aTipos,int limiteTipos, eCatastro* aCatastros, int limiteCatastros, eCensista* aCensistas, int limiteCensistas)
{
	int opcionInforme;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && aCatastros != NULL && limiteCatastros > 0 && aCensistas != NULL && limiteCensistas > 0)
	{
		do
		{
			if(utn_getNumeroEntero(&opcionInforme, "\n\n***** MENU DE INFORMES *****"
												   "\n1. Informar por tipo de vivienda (DEPARTAMENTO)"
												   "\n2. Informar por localidad (Avellaneda)"
												   "\n3. Informar cantidad de viviendas censadas en la localidad de Avellaneda"
												   "\n4. Informar viviendas censadas por censista elegido (Sol)"
												   "\n5. Informar cantidad de viviendas de tipo CASA"
												   "\n6. Informar cantidad de viviendas de tipo DEPARTAMENTO de la localidad de Lanus"
												   "\n7. Salir"
												   "\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,7,3) == 1)
			{
				switch(opcionInforme)
				{
					case 1:
						Informes_PorTipoDeVivienda(aViviendas,limiteViviendas,aTipos,limiteTipos,aCatastros,limiteCatastros,aCensistas,limiteCensistas);
						break;
					case 2:
						Informes_PorLocalidad(aViviendas,limiteViviendas,aTipos,limiteTipos,aCatastros,limiteCatastros,aCensistas,limiteCensistas);
						break;
					case 3:
						Informes_CantidadAvellaneda(aViviendas,limiteViviendas);
						break;
					case 4:
						Informes_PorCensista(aViviendas,limiteViviendas,aTipos,limiteTipos,aCatastros,limiteCatastros,aCensistas,limiteCensistas);
						break;
					case 5:
						Informes_CantidadTipoCasa(aViviendas,limiteViviendas);
						break;
					case 6:
						Informes_CantidadDeptosLanus(aViviendas,limiteViviendas);
						break;
					case 7:
						break;
				}
			}
		}while(opcionInforme != 7);
	}
}

