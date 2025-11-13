#include "nodo.c"
#include <stdio.h>
#include <stdlib.h>

// lista enlazada creada para manejar enteros
typedef struct lista_enlazada {
    nodo *inicio;
    nodo *fin;
    int longitud;
}lista_enlazada;

// crear una nueva lista enlazada
// retorna un puntero a la lista
lista_enlazada *crearlista() {
    lista_enlazada *list = malloc(sizeof(lista_enlazada));
    list->longitud = 0;
    list->inicio = NULL;
    list->fin = NULL;
    return list;
}

// agregar un elemento en el indice pos
// si pos es -1 agregar al final
void agregar(lista_enlazada *list, int *dato, int pos) {
    if (pos < -1 || pos > list->longitud) return;

    if (list->longitud == 0) {
        nodo *new = newnodo(dato);
        list->inicio = new;
        list->fin = new;
        list->longitud = 1;
    }
    else if (list->longitud == 1) {
        nodo *new = newnodo(dato);
        list->fin = new;
        list->longitud++;
        list->inicio->siguiente = list->fin;
    }
    else if (pos == 0) {
        nodo *new = newnodo(dato);
        new->siguiente = list->inicio;
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
void eliminar(lista_enlazada *list, int pos) {
    if (pos < -1 || pos >= list->longitud) return;
    if (list->longitud == 0) return;

    if (list->longitud == 1) {
        list->inicio = NULL;
        list->fin = NULL;
        list->longitud = 0;
        list->longitud--;
    }
    else if (pos == 0) {
        nodo *tmp = list->inicio->siguiente;
        free(list->inicio);
        list->inicio = tmp;
        list->longitud--;
    }
    else {
        if (pos == -1) pos = list->longitud - 1;
        nodo *current = list->inicio;
        for (int i = 0; i < pos - 1; i++) {
            current = current->siguiente;
        }
        nodo *next = current->siguiente->siguiente;
        free(current->siguiente);
        current->siguiente = next;
        list->longitud--;
    }

}

// imprimir la lista por consola
void printlist(lista_enlazada *list) {
    if (list->longitud == 0) {
        printf("empy list\n");
        return;
    }
    int len = list->longitud;
    nodo *current = list->inicio;
    for (int i = 0; i < len; i++) {
        if (i != len - 1)printf("%d -> ", current->dato);
        else printf("%d", current->dato);
        current = current->siguiente;
    }
    printf("\n");
}
