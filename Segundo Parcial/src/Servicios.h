/*
 * Servicios.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Joel Barrera
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int idServicio;
	char descripcion[25];
	int tipoServicio;
	float precioUnitario;
	int cantidad;
	float totalServicio;
}eServicio;

/**
 * @brief Crea un elemento del tipo eServicio y lo retorna
 *
 * @return Retorna el elemento
 */
eServicio* Servicio_newServicio();

/**
 * @brief Crea un elemento del tipo eServicio a partir de parametros y lo retorna
 *
 * @param idStr
 * @param descripcion
 * @param tipoStr
 * @param precioUnitarioStr
 * @param cantidadStr
 * @param totalServicioStr
 * @return
 */
eServicio* Servicio_newServicioParametros(char* idStr,char* descripcion,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

/**
 * @brief Imprime un elemento de la LinkedList
 *
 * @param pElemento Puntero al elemento a imprimir
 */
void Servicio_imprimirUno(eServicio* pElemento);

/**
 * @brief Calcula el total del servicio (Cantidad x Precio Unitario)
 *
 * @param element Puntero al elemento a completar
 */
void Servicio_calcularTotal(void* element);

/**
 * @brief Retorna valores que indican si pertenece a la condicion
 *
 * @param element Puntero al elemento
 * @return
 */
int Servicio_filtrarPorTipoMinorista(void* element);

/**
 * @brief Retorna valores que indican si pertenece a la condicion
 *
 * @param element
 * @return
 */
int Servicio_filtrarPorTipoMayorista(void* element);

/**
 * @brief Retorna valores que indican si pertenece a la condicion
 *
 * @param element
 * @return
 */
int Servicio_filtrarPorTipoExportar(void* element);

/**
 * @brief Retorna valores que indican la comparacion de dos elementos
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al primer elemento
 * @return
 */
int Servicio_compararDescripcion(void* pElementoUno, void* pElementoDos);//ll_sort

/**
 * @brief Setea el campo ID en base al valor pasado como parametro
 *
 * @param this
 * @param id
 * @return
 */
int Servicio_setId(eServicio* this,int id);

/**
 * @brief Obtiene el valor del campo ID de un elemento
 *
 * @param this
 * @param id
 * @return
 */
int Servicio_getId(eServicio* this,int* id);

/**
 * @brief Setea el campo descripcion en base al valor pasado como parametro
 *
 * @param this
 * @param descripcion
 * @return
 */
int Servicio_setDescripcion(eServicio* this, char* descripcion);
/**
 * @brief Obtiene el valor del campo descripcion de un elemento
 *
 * @param this
 * @param descripcion
 * @return
 */
int Servicio_getDescripcion(eServicio* this, char* descripcion);

/**
 * @brief Setea el campo tipoServicio en base al valor pasado como parametro
 *
 * @param this
 * @param tipoServicio
 * @return
 */
int Servicio_setTipo(eServicio* this,int tipoServicio);
/**
 * @brief Obtiene el valor del campo tipoServicio de un elemento
 *
 * @param this
 * @param tipoServicio
 * @return
 */
int Servicio_getTipo(eServicio* this,int* tipoServicio);

/**
 * @brief Setea el campo precioUnitario en base al valor pasado como parametro
 *
 * @param this
 * @param precioUnitario
 * @return
 */
int Servicio_setPrecioUnitario(eServicio* this, float precioUnitario);
/**
 * @brief Obtiene el valor del campo precioUnitario de un elemento
 *
 * @param this
 * @param precioUnitario
 * @return
 */
int Servicio_getPrecioUnitario(eServicio* this, float* precioUnitario);

/**
 * @brief Setea el campo Cantidad en base al valor pasado como parametro
 *
 * @param this
 * @param cantidad
 * @return
 */
int Servicio_setCantidad(eServicio* this,int cantidad);
/**
 * @brief Obtiene el valor del campo cantidad de un elemento
 *
 * @param this
 * @param cantidad
 * @return
 */
int Servicio_getCantidad(eServicio* this,int* cantidad);

/**
 * @brief Setea el campo totalServicio en base al valor pasado como parametro
 *
 * @param this
 * @param totalServicio
 * @return
 */
int Servicio_setTotalServicio(eServicio* this,float totalServicio);
/**
 * @brief Obtiene el valor del campo totalServicio de un elemento
 *
 * @param this
 * @param totalServicio
 * @return
 */
int Servicio_getTotalServicio(eServicio* this,float* totalServicio);

#endif /* SERVICIOS_H_ */
