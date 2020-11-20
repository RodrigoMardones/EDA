#include "stdlib.h"

// declaracion de nodo
typedef struct Nodo {
    int valor;
    unsigned x;
    unsigned y;
    struct Nodo *next;
} nodo;

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

nodo* getNodo(nodo *l, unsigned x, unsigned y){
    nodo* aux = l;
    while(aux != NULL){
        if(aux->x == x && aux->y == y){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}