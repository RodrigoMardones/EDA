#include "stdio.h"
#include "stdlib.h"

// declaracion de nodo
typedef struct Nodo {
    int valor;
    unsigned x;
    unsigned y;
    struct Nodo *next;
} nodo;

// declaracion de lista
typedef struct Lista {
    int rows;
    int cols;
    nodo* inside;
}lista;


nodo* push(nodo *l, int value, unsigned x, unsigned y){
    nodo *newNode = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNode->valor = value;
    newNode->x = x;
    newNode->y = y;
    newNode->next = l;
    return newNode;
}

int isNodo(nodo *l , unsigned x, unsigned y){

    nodo *aux = l;
    while(aux != NULL) {
        if(aux->x == x && aux->y == y){
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

int getValueNodo(nodo *l, unsigned x, unsigned y){
    nodo* aux = l;
    while(aux != NULL){
        if(aux->x == x && aux->y == y){
            return aux->valor;
        }
        aux = aux->next;
    }
    return 0;
}

void rellenarMatriz(lista* l){
    FILE *fptr;
    int x,y = 0;
    fptr = fopen("matriz.in", "r");
    fscanf(fptr, "%i", &x);
    fscanf(fptr, "%i", &y);
    l->cols = x;
    l->rows = y;
    for(unsigned i = 0; i< l->rows; i++){
        for(unsigned j = 0; j< l->cols; j++){
            int val = 0;
            fscanf(fptr ,"%d", &val);
            // printf("(%d, %d) = %d\n", i, j, val);
            if(val != 0){
                l->inside = push(l->inside, val, i, j);
            }
        }
    }
    fclose(fptr);
}

void mostrarMatriz(lista* l){
    nodo * aux = l->inside;
    printf("la matriz resultante es: \n");
    for(unsigned i = 0; i < l->rows ; i++){
        for(unsigned j = 0; j< l->cols; j++){
            printf("  %d  ", getValueNodo(aux, i,j));
        }
        printf("\n");
    }
}


void multiplicarMatriz(lista* l, lista* n, lista *r){
    nodo * aux = NULL;
    int x = 0;
    for (int i = 0; i < l->rows; i++) { 
        for (int j = 0; j < l->cols; j++) {
            x =  0;
            for (int k = 0; k < l->rows; k++){
                int valueNodoA = getValueNodo(l->inside, i, k);
                int valueNodoB = getValueNodo(n->inside, k, j);
                x+= valueNodoA * valueNodoB;
            }
            if(x != 0){
                aux = push(aux, x, i, j);
            }
        }
    }
    r->cols = l->cols;
    r->rows = l->rows;
    r->inside = aux;
}

void multiplicarRecursivo(lista *l, lista *n, lista* r, int contador){
    if(contador == 1){
        return;
    }
    multiplicarMatriz(l,n,r);
    multiplicarRecursivo(l,r,r,contador - 1);
}

void calculateMemory(lista *l){
    nodo * aux = l->inside;
    int possibleMemory, totalMemory = 0;
    while(aux != NULL){
        totalMemory += 1;
        aux = aux->next;
    }
    totalMemory = totalMemory * 4;
    possibleMemory = l->cols * l->rows * 4;
    printf("tamano en memoria de la matriz de entrada es: %d bytes \n", totalMemory);
    printf("tamano en memoria de la matriz completa hubiera sido: %d \n", possibleMemory);
}