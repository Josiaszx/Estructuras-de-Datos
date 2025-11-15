#include <stdlib.h>

// nodo de la lista enlazada.
// contiene un puntero a un dato generico y un puntero al siguiente nodo.
// como usamos un puntero a un dato generico en vez de almecenar simplemente el dato especifico, estamos perdiendo
// 8+n bytes por cada nodo, donde n es el tamaño del dato especifico. Esto se evitaria si se desarrollara la lista para un tipo de dato especifico.

typedef struct nodo {
    void *dato;
    struct nodo *siguiente;
}nodo;

// crear un nuevo nodo y retornar un puntero a el
nodo *newnodo(void *data) {
    nodo *nuevo = malloc(sizeof(nodo)); // reserva memoria en heap para el nodo
    nuevo->dato = data;
    nuevo->siguiente = NULL;
    return nuevo;
}

