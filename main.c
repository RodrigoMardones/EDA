#include "stdio.h"
#include "lista.h"



int main(){

    lista *l = malloc(sizeof(lista));
    lista *n = malloc(sizeof(lista));
    lista *r = malloc(sizeof(lista));
    rellenarMatriz(l);
    multiplicarRecursivo(l,l,r, 3);
    mostrarMatriz(r);
    calculateMemory(r);
    
    return 0;
}



