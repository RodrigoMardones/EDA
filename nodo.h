#include "stdio.h"
#include "stdlib.h"
#include "nodo.c"



/**
 * descripcion : agrega un elemento a una lista de nodos
 * @param  l  * nodo  - puntero a un nodo especifico a modificar
 * @param value int - valor a guardar
 * @param x int - posicion x en lista
 * @param y int - posicion y en lista
 * @param next * Nodo - puntero al siguiente nodo 
 + @return *nodo
 * */ 
nodo* push(nodo *l, int value, unsigned x, unsigned y);

/**
 * 
 * @param l * nodo - lista creada con los elementos de la matriz dispersa 
 * @param x int - posicion x del nodo a buscar
 * @param y int - posicion y del nodo a buscar
 * @return bool - si se encuentra o no el nodo
*/
int isNodo(nodo *l , unsigned x, unsigned y);

/**
 * @param l * nodo - lista creada con los elementos de la matriz dispersa 
 * @param x int - posicion x del nodo a buscar
 * @param y int - posicion y del nodo a buscar
 * @return nodo en la posicion correspondiente al nodo buscado o NULL si no está
*/
nodo* getNodo(nodo *l, unsigned x, unsigned y);

