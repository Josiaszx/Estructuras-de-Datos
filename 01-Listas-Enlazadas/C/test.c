
#include <stdio.h>
#include "listaenlazada.c"



int main() {

    lista *lista_enlazada = crearlista();

    // agregar datos
    int valores[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        agregar(lista_enlazada, valores + i, i);
    }

    int n = 99;
    agregar(lista_enlazada, &n, 5);
    printlist(lista_enlazada); // --> [1, 2, 3, 4, 5, 99]

    // eliminar datos
    eliminar(lista_enlazada, -1);
    printlist(lista_enlazada); // --> [1, 2, 3, 4, 5]

    eliminar(lista_enlazada, -1);
    printlist(lista_enlazada); // --> [1, 2, 3, 4]

    eliminar(lista_enlazada, -1);
    printlist(lista_enlazada); // --> [1, 2, 3]

    eliminar(lista_enlazada, -1);
    printlist(lista_enlazada); // --> [1, 2]

    eliminar(lista_enlazada, -1);
    printlist(lista_enlazada); // --> [1]

    printf("\n");


    int l = 777;
    agregar(lista_enlazada, &l, -1);
    printlist(lista_enlazada); // --> [1, 777]

    agregar(lista_enlazada, &l, 0);
    printlist(lista_enlazada); // --> [777, 1, 777]

    // buscar por indice
    int *dato = obtener(lista_enlazada, -1);
    printf("\nEl dato en la posicion final es: %d\n", *dato); // --> El dato en la posicion final es: 777

    int *dato2 = obtener(lista_enlazada, 1);
    printf("El dato en el indice 1 es: %d\n", *dato2); // --> El dato en el indice 1 es: 1

    int *dato3 = obtener(lista_enlazada, 0);
    printf("El dato en el indice 0 es: %d\n\n", *dato3); // --> El dato en el indice 0 es: 777

    // buscar por valor
    int pos1 = buscar(lista_enlazada, 777);
    printf("El dato 777 se encuentra en la posicion: %d\n", pos1); // --> El dato 777 se encuentra en la posicion: 0

    int pos2 = buscar(lista_enlazada, 1);
    printf("El dato 1 se encuentra en la posicion: %d\n", pos2); // --> El dato 1 se encuentra en la posicion: 1

    int pos3 = buscar(lista_enlazada, 42);
    printf("El dato 42 se encuentra en la posicion: %d\n\n", pos3); // --> El dato 42 se encuentra en la posicion: -1

    eliminar(lista_enlazada, 1);
    printlist(lista_enlazada); // --> [777, 777]


    return 0;


}

