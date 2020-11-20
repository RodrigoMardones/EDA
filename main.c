#include "stdio.h"
#include "nodo.h"


/* void readMatriz(){
    FILE *fptr;
    int x = 0;
    int y = 0;
    int z= 0;
    fptr = fopen("matriz.in", "r");
    fscanf(fptr, "%d", &x);
    printf("valor de x: %d \n", x);
    fscanf(fptr, "%d", &y);
    printf("valor de y: %d \n", y);
    fscanf(fptr, "%d", &z);
    printf("valor de y: %d \n", z);
    fclose(fptr);
} */

nodo* rellenarMatriz(int *x, int *y){
    FILE *fptr;
    nodo *l = NULL;
    fptr = fopen("matriz.in", "r");
    fscanf(fptr, "%d", x);
    fscanf(fptr, "%d", y);
    for(unsigned i = 0; i< *x; i++){
        for(unsigned j = 0; j< *y; j++){
            int val = 0;
            fscanf(fptr ,"%d", &val);
            printf("(%d, %d) = %d\n", i, j, val);
            if(val != 0){
                l = push(l, val, i, j);
            }
        }
    }
    fclose(fptr);
    return l;
}

void printMatriz(nodo* l){
    nodo *aux = l;
    while(aux != NULL){
        printf("%d \n", aux->valor);
        aux = aux->next;
    }
}

int main(){
    printf("hello friend... \n");
    nodo *l = NULL;
    int x,y;
    l = rellenarMatriz(&x , &y);
    printMatriz(l);
    return 0;
}



