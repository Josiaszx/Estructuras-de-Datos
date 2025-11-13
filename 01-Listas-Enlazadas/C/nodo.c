#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *siguiente;
}nodo;

nodo *newnodo(int *data) {
    nodo *nuevo = (nodo *) malloc(sizeof(nodo));
    nuevo->dato = *data;
    nuevo->siguiente = NULL;
    return nuevo;
}