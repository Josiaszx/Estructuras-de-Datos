
#include <stdio.h>
#include "lista_enlazada.c"


int main() {

    lista_enlazada *firstlist = crearlista();
    int valores[5] = {1, 3, 4, 6, 8};
    for (int i = 0; i < 5; i++) {
        agregar(firstlist, valores + i, -1);
        printlist(firstlist);
    }

    int n = 99;
    agregar(firstlist, &n, -1);
    printlist(firstlist);

    // del(firstlist, -1);

    printlist(firstlist);


    return 0;


}

