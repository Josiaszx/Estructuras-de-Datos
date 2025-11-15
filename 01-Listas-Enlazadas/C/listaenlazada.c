#include "nodo.c"
#include <stdio.h>
#include <stdlib.h>

// lista enlazada simple creada para manejar datos genericos
// desarrollada de esta forma solo para fines didacticos
// es mas conveniente desarrorla directamente para manejar el tipo de dato especifico que se desea usar
typedef struct lista {
    nodo *inicio;
    nodo *fin;
    int longitud;
}lista;

// crear una nueva lista enlazada
// retorna un puntero a la lista
lista *crearlista() {
    lista *list = malloc(sizeof(lista)); // reserva memoria en heap para la lista
    list->longitud = 0;
    list->inicio = NULL;
    list->fin = NULL;
    return list;
}

// agregar un elemento en el indice pos
// si pos es -1 agregar al final
void agregar(lista *list, void *dato, int pos) {
    if (pos < -1 || pos > list->longitud) return;

    if (list->longitud == 0) {
        nodo *new = newnodo(dato);
        list->inicio = new;
        list->fin = new;
        list->longitud = 1;
    }
    else if (list->longitud == 1 && (pos == 1 || pos == -1)) {
        nodo *new = newnodo(dato);
        list->fin = new;
        list->inicio->siguiente = list->fin;
        list->longitud++;
    }
    else if (pos == 0) {
        nodo *new = newnodo(dato);
        new->siguiente = list->inicio;
        if (list->longitud == 1) list->fin = list->inicio;
        list->inicio = new;
        list->longitud++;
    }
    else if (pos == list->longitud || pos == -1) {
        nodo *new = newnodo(dato);
        list->fin->siguiente = new;
        list->fin = new;
        list->longitud++;
    }
    else {
        nodo *tmp = list->inicio;
        nodo *new = newnodo(dato);
        for (int i = 0; i < pos - 1; i++) {
            tmp = tmp->siguiente;
        }
        new->siguiente = tmp->siguiente;
        tmp->siguiente = new;
        list->longitud++;
    }
}

// elminar el elmento en el indice pos
// si pos es -1 eliminar el ultimo elemento
void eliminar(lista *list, int pos) {
    if (pos < -1 || pos >= list->longitud) return;
    if (list->longitud == 0) return;

    if (list->longitud == 1) {
        free(list->inicio); // liberamos la memoria del nodo
        list->inicio = NULL;
        list->fin = NULL;
        list->longitud = 0;
    }
    else if (pos == 0) {
        nodo *tmp = list->inicio->siguiente;
        free(list->inicio); // liberamos la memoria del nodo
        list->inicio = tmp;
        list->longitud--;
    }
    else if (list->longitud == 2 && (pos == 1 || pos == -1)) {
        free(list->fin); // liberamos la memoria del nodo
        list->inicio->siguiente = NULL;
        list->fin = list->inicio;
        list->longitud--;
    }
    else {
        int n = pos == -1 ? list->longitud - 1 : pos;
        nodo *actual = list->inicio;
        for (int i = 0; i < n - 1; i++) {
            actual = actual->siguiente;
        }
        nodo *sig = actual->siguiente->siguiente;
        free(actual->siguiente); // liberamos la memoria del nodo
        actual->siguiente = sig;
        if (n == list->longitud - 1) list->fin = actual;
        list->longitud--;
    }

}

// obtener el valor en el indice dado
// si el indice es -1 obtener el ultimo elemento
// solo funciona si el tipo de dato es int
void *obtener(lista *list, int indice) {
    if (indice < -1 || indice >= list->longitud) return NULL;
    if (indice == 0) return list->inicio->dato;
    if (indice == -1) return list->fin->dato;
        nodo *tmp = list->inicio;
        for (int i = 0; i < indice; i++) {
            tmp = tmp->siguiente;
        }
        return tmp->dato;
}

// buscar el indice del dato dado
// si no se encuentra retorna -1
// solo funciona si el tipo de dato es int
int buscar(lista *list, int dato) {
    if (dato == *(int*)(list->inicio->dato)) return 0;
    if (dato == *(int*)(list->fin->dato)) return list->longitud - 1;
    nodo *current = list->inicio;
    int index = 0;
    while (current != NULL) {
        if (*(int*)(current->dato) == dato) {
            return index;
        }
        current = current->siguiente;
        index++;
    }
    return -1;
}


// imprimir la lista por consola
// solo funciona si el tipo de dato es int
void printlist(lista *list) {
    if (list->longitud == 0) {
        printf("empty list\n");
        return;
    }
    int len = list->longitud;
    nodo *current = list->inicio;
    for (int i = 0; i < len; i++) {
        if (i != len - 1)printf("%d -> ", *(int*)(current->dato));
        else printf("%d", *(int*)(current->dato));
        current = current->siguiente;
    }
    printf("\n");
}