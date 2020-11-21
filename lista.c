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

void *listaInit(lista* l){
    l->inside = NULL;
    l->rows = 0;
    l->cols = 0;
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
 
    for(unsigned i = 0; i < l->rows ; i++){
        for(unsigned j = 0; j< l->cols; j++){
            int in = isNodo(aux, i,j);
            if(in){
                printf(" %d ", aux->valor);
                aux = aux->next;
            } else {
                printf(" 0 ");
            }
            printf("\n");
        }
    }
}

void mostrarLista(lista* l){
    nodo* aux = l->inside;
    while(aux != NULL){
        printf(" %d ", aux->valor);
        aux = aux->next;
    }
}

lista* multiplicarMatriz(lista* l,lista *n){
    nodo * aux = NULL;
    lista* final = NULL;
    int x = 0;
    for (int i = 0; i < l->rows; i++) { 
        for (int j = 0; j < l->cols; j++) {
            x =  0;
            for (int k = 0; k < l->rows; k++){
                int valueNodoA = getValueNodo(l->inside, i, k);
                int valueNodoB = getValueNodo(l->inside, k, j);
                x = valueNodoA + valueNodoB;
            }
            if( x != 0 ){
                aux = push(aux, x, i, j);
            }
        }
    }
    final->cols = l->cols;
    final->rows = l->rows;
    final->inside = aux;
    return final;
}