#include "stdio.h"
#include "lista.h"


int main(){
    lista *l;
    listaInit(l);
    rellenarMatriz(l);
    mostrarLista(l);
    l = multiplicarMatriz(l,l);
    mostrarLista(l);
    return 0;
}



