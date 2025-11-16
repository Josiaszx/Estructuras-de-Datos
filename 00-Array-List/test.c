#include <stdio.h>
#include "arraylist.c"

void printarray (arraylist *list) {
    for (int i = 0; i < len(list); i++) {
        printf(" %d ", *(list->nums+i));
    }
    printf("\n");
}



int main()
{

    arraylist *list = newlist(10);
    add(list, 11);
    add(list, 33);
    add(list, 99);
    add(list, 777);
    printarray(list); // 11 33 99 777


    set(list, 555, 1);
    printarray(list); // 11 555 99 777

    del(list);
    printarray(list); // 11 555 99

    delin(list, 0);
    printarray(list); // 555 99

    addin(list, 434, 2);
    printarray(list); // 555 99 434
    

    printf("cantidad de elementos: %d\n", list->elements);
    printf("cantidad de espacios reservados: %d\n", list->size);



    return 0;
}
