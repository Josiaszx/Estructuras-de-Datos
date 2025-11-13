
#include <stdio.h>
#include "lista_enlazada.c"


int main() {

    lista_enlazada *firstlist = crearlista();

    // agregar valores
    int valores[5] = {1, 3, 4, 6, 8};
    for (int i = 0; i < 5; i++) {
        agregar(firstlist, valores + i, -1);
    }

    int n = 99;
    agregar(firstlist, &n, -1); // agregar 99 al final
    printlist(firstlist); // --> 1 -> 3 -> 4 -> 6 -> 8 -> 99

    // eliminar el ultimo elemento
    eliminar(firstlist, -1);

    printlist(firstlist); // --> 1 -> 3 -> 4 -> 6 -> 8

    // eliminar primer elemento
    eliminar(firstlist, 0);
    printlist(firstlist); // --> 3 -> 4 -> 6 -> 8

    // obtener elemento en el indice 2
    int valor = obtener(firstlist, 2);
    printf("Valor en el indice 2: %d\n", valor); // --> Valor en el indice 2: 6

    // buscar elemento en el indice 1
    int buscado = buscar(firstlist, 1);
    printf("Valor en el indice 1: %d\n", buscado); // --> Valor en el indice 1: 4

    return 0;


}

