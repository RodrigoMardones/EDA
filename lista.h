#include "lista.c"



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
int getValueNodo(nodo *l, unsigned x, unsigned y);


/**
 * @descripcion - rellena una matriz dispersa desde un archivo base 
 * @param lista *l - lista a rellenar con los datos del archivo
 * @return lista leida desde archivo
*/
void rellenarMatriz(lista *l);

/**
 * @descripcion - toma la funcion de multiplicar y la aplica de manera recursiva
 * @param lista *l - lista como base para multiplicar
 * @param lista *n - lista como base para multiplicar con l
 * @param lista +r - lista como base para guardar resultado de multiplicacion
 * @param int contador - contador para definir la cantidad de iteraciones
*/
void multiplicarRecursivo(lista *l, lista *n, lista* r, int contador);

/**
 * @pdescripcion - toma una lista l y muestra la cantidad de memoria utilizada y la posible utilizacion
 * @param lista *l - lista a evaluar
 */
void calculateMemory(lista *l);


/**
 * 
 * @descripcion - muestra una lista dispersa de menera ordenada como si fuera matriz
 * @param lista *l - lista a mostrar
*/
void mostrarMatriz(lista* l);
