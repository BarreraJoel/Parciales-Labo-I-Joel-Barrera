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
 * @param idStr Cadena de caracteres que contiene un id
 * @param descripcion Cadena de caracteres que contiene una descripcion
 * @param tipoStr Cadena de caracteres que contiene un tipo de servicio
 * @param precioUnitarioStr Cadena de caracteres que contiene un precio Unitario
 * @param cantidadStr Cadena de caracteres que contiene una cantidad
 * @param totalServicioStr Cadena de caracteres que contiene el valor total de un servicio
 * @return Retorna (NULL) Error: Si alguno de los parametros es NULL
 * 		   		   (pElemento) OK
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
 * @return (-1) Error: elemento nulo
 * 		   ( 1) OK: cumple la condicion
 * 		   ( 0) no cumple la condicion
 */
int Servicio_filtrarPorTipoMinorista(void* element);

/**
 * @brief Retorna valores que indican si pertenece a la condicion
 *
 * @param element Puntero al elemento
 * @return (-1) Error: elemento nulo
 * 		   ( 1) OK: cumple la condicion
 * 		   ( 0) no cumple la condicion
 */
int Servicio_filtrarPorTipoMayorista(void* element);

/**
 * @brief Retorna valores que indican si pertenece a la condicion
 *
 * @param element Puntero al elemento
 * @return (-1) Error: elemento nulo
 * 		   ( 1) OK: cumple la condicion
 * 		   ( 0) no cumple la condicion
 */
int Servicio_filtrarPorTipoExportar(void* element);

/**
 * @brief Retorna valores que indican la comparacion de dos elementos
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al segundo elemento
 * @return (-1) Error: elementos nulo
 * 		   (<1) OK: Si el primer elemento es menor que el segundo
 * 		   (>1) OK: Si el primer elemento es mayor que el segundo
 * 		   ( 0) OK: Si los dos elementos son iguales
 */
int Servicio_compararDescripcion(void* pElementoUno, void* pElementoDos);

/**
 * @brief Setea el campo ID en base al valor pasado como parametro
 *
 * @param this Puntero al elemento
 * @param id Valor de ID a setear
 * @return (-1) Error: Elemento NULL o ID no valido
 * 		   ( 0) OK
 */
int Servicio_setId(eServicio* this,int id);

/**
 * @brief Obtiene el valor del campo ID de un elemento
 *
 * @param this Puntero al elemento
 * @param id Puntero a int donde se guardara el valor
 * @return (-1) Error: Elemento NULL o Id NULL
 * 		   ( 0) OK
 */
int Servicio_getId(eServicio* this,int* id);

/**
 * @brief Setea el campo descripcion en base al valor pasado como parametro
 *
 * @param this Puntero al elemento
 * @param descripcion Cadena de caracteres que contiene una descripcion
 * @return (-1) Error: Elemento NULL o descripcion NULL
 * 		   ( 0) OK
 */
int Servicio_setDescripcion(eServicio* this, char* descripcion);
/**
 * @brief Obtiene el valor del campo descripcion de un elemento
 *
 * @param this Puntero al elemento
 * @param descripcion Cadena de caracteres donde se guardara una descripcion
 * @return (-1) Error: Elemento NULL o descripcion NULL
 * 		   ( 0) OK
 */
int Servicio_getDescripcion(eServicio* this, char* descripcion);

/**
 * @brief Setea el campo tipoServicio en base al valor pasado como parametro
 *
 * @param this Puntero al elemento
 * @param tipoServicio Valor del tipo de servicio a setear
 * @return (-1) Error: Elemento NULL o tipoServicio no valido
 * 		   ( 0) OK
 */
int Servicio_setTipo(eServicio* this,int tipoServicio);

/**
 * @brief Obtiene el valor del campo tipoServicio de un elemento
 *
 * @param this Puntero al elemento
 * @param tipoServicio Puntero a int donde se guardara el tipo de servicio
 * @return (-1) Error: Elemento NULL o tipoServicio NULL
 * 		   ( 0) OK
 */
int Servicio_getTipo(eServicio* this,int* tipoServicio);

/**
 * @brief Setea el campo precioUnitario en base al valor pasado como parametro
 *
 * @param this Puntero al elemento
 * @param precioUnitario Valor del precio unitario a setear
 * @return (-1) Error: Elemento NULL o precioUnitario no valido
 * 		   ( 0) OK
 */
int Servicio_setPrecioUnitario(eServicio* this, float precioUnitario);

/**
 * @brief Obtiene el valor del campo precioUnitario de un elemento
 *
 * @param this Puntero al elemento
 * @param precioUnitario Puntero a float donde se guardara el precio
 * @return (-1) Error: Elemento NULL o precioUnitario NULL
 * 		   ( 0) OK
 */

int Servicio_getPrecioUnitario(eServicio* this, float* precioUnitario);

/**
 * @brief Setea el campo Cantidad en base al valor pasado como parametro
 *
 * @param this Puntero al elemento
 * @param cantidad Valor de la cantidad a setear
 * @return (-1) Error: Elemento NULL o cantidad no valida
 * 		   ( 0) OK
 */
int Servicio_setCantidad(eServicio* this,int cantidad);

/**
 * @brief Obtiene el valor del campo cantidad de un elemento
 *
 * @param this Puntero al elemento
 * @param cantidad Puntero a int donde se guardara la cantidad
 * @return (-1) Error: Elemento NULL o cantidad NULL
 * 		   ( 0) OK
 */
int Servicio_getCantidad(eServicio* this,int* cantidad);

/**
 * @brief Setea el campo totalServicio en base al valor pasado como parametro
 *
 * @param this Puntero al elemento
 * @param totalServicio Valor del total del servicio a setear
 * @return (-1) Error: Elemento NULL o totalServicio no valido
 * 		   ( 0) OK
 */
int Servicio_setTotalServicio(eServicio* this,float totalServicio);

/**
 * @brief Obtiene el valor del campo totalServicio de un elemento
 *
 * @param this Puntero al elemento
 * @param totalServicio Puntero a float donde se guardara el total del servicio
 * @return (-1) Error: Elemento NULL o totalServicio NULL
 * 		   ( 0) OK
 */
int Servicio_getTotalServicio(eServicio* this,float* totalServicio);

#endif /* SERVICIOS_H_ */
