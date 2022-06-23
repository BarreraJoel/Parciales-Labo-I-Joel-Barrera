/*
 ============================================================================
 Name        : Segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "input-UTN.h"
#include "Controller.h"

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList* listaServicios = ll_newLinkedList();
	int opcionMenu;
	int flagOpcionCinco = 0;
	int flagOpcionUno = 0;

	do
	{
		if(utn_getNumeroEntero(&opcionMenu, "\n\n*** MENU DE OPCIONES ***\n"
											"\n1.CARGAR ARCHIVO"
											"\n2.IMPRIMIR LISTA"
											"\n3.ASIGNAR TOTALES"
											"\n4.FILTRAR POR TIPO"
											"\n5.MOSTRAR SERVICIOS"
											"\n6.GUARDAR SERVICIOS"
											"\n7.SALIR"
											"\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,7,3) == 1)
		{
			switch(opcionMenu)
			{
				case 1:
					if(flagOpcionUno == 0)
					{
						if(controller_cargarArchivo("data.csv",listaServicios) == 1)
						{
							printf("\n*** La lista se cargo con exito ***\n");
							flagOpcionUno = 1;
						}
					}
					else
					{
						printf("\n*** El archivo ya fue cargado anteriormente ***\n");
					}
					break;
				case 2:
					if(flagOpcionUno == 1)
					{
						controller_imprimirLista(listaServicios);
					}
					else
					{
						printf("\n*** Primero debe cargar un archivo ***\n");
					}
					break;
				case 3:
					if(flagOpcionUno == 1)
					{
						if(controller_asignarTotales(listaServicios) == 1)
						{
							printf("\n*** Se asignaron los totales de todos los servicios ***\n");
						}
					}
					else
					{
						printf("\n*** Primero debe cargar un archivo ***\n");
					}
					break;
				case 4:
					if(flagOpcionUno == 1)
					{
						if(controller_filtrar(listaServicios) == 1)
						{
							printf("\n*** La lista se filtro y se guardo con exito ***\n");
						}
					}
					else
					{
						printf("\n*** Primero debe cargar un archivo ***\n");
					}
					break;
				case 5:
					if(flagOpcionUno == 1)
					{
						if(controller_ordenarServicios(listaServicios) == 0)
						{
							printf("\n*** La lista se ordeno correctamente ***\n");
							controller_imprimirLista(listaServicios);
							flagOpcionCinco = 1;
						}
					}
					else
					{
						printf("\n*** Primero debe cargar un archivo ***\n");
					}
					break;
				case 6:
					if(flagOpcionCinco == 1)
					{
						if(controller_guardarArchivo("dataOrdenada.csv",listaServicios) == 1)
						{
							printf("\n*** El archivo se guardo con exito ***\n");
						}
					}
					else
					{
						printf("\n*** Primero debe ordenar los servicios ***\n");
					}
					break;
				case 7:
					break;
			}

		}
	}while(opcionMenu != 7);

	return EXIT_SUCCESS;
}
