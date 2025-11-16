// implementacion de arraylist para enteros en C a modo de practica
// metodos a implementar:
//  - len() --> retorna la longitud
//  - size() --> retorna el tamaño del array
//  - add() --> agregar elemento al final
//  - addin() --> agregar elemento en indice dado
//  - del() --> elimina el ultimo elemento
//  - delin() --> elimina el elmento en el indice dado
//  - get() --> retorna el elemento en el indice dado
//  - find() --> retorna el indice del elemento dado o -1 si no se encuentra
//  - set() --> modifica el elemento en el indice dado
//  - del_list() --> libera la memoria ocupada por la lista

// caracteristicas:
//  - la lista debe ser implementada con arrays y debe ser dinamica
//  - si la lista se llena y se desea agregar otro elemento, se debe reservar otro array con el doble de capacidad del actual
//    y se deben copiar todos los elementos al nuevo array
//  - si la lista se va vaciando y llega a 1/4 de su capacidad, reducir el tamaño del array a la mitad

#include <stdio.h>
#include <stdlib.h>

typedef struct arraylist{
    int *nums; // array
    int size; // tamaño del array
    int elements; // cantidad de elementos
} arraylist;

arraylist *newlist(size_t list_length) {
    // reservar espacio para la estructura
    arraylist *list = malloc(sizeof(arraylist));
    if (list == NULL) return NULL;

    list->nums = calloc(list_length, sizeof(int));
    if (list->nums == NULL) return NULL;

    list->size = list_length;
    list->elements = 0;
    return list;
}

// reservar mas espacio cuando la lista este llena y mudar los datos. Retorna -1 si no se puedo realizar la operacion
int resize(arraylist *list) {

    int list_length = list->size;

    // nuevo array
    int *newpos = calloc(list_length * 2, sizeof(int));
    if (newpos == NULL) return -1;

    // trasladar datos
    for (int i = 0; i < list_length; ++i) {
        *(newpos+i) = *(list->nums + i);
    }

    // liberar anterior ubicacion y cambiar puntero al array
    free(list->nums);
    list->nums = newpos;
    list->size = list_length * 2;
    return 0;
}


// reducir el tamaño de la lista. Retorna -1 si no se pudo realizar la operacion
int downsize(arraylist *list) {
    int new_size = list->size / 2;

    // reducir tamaño
    list->nums = realloc(list->nums, new_size * sizeof(int));
    if (list->nums == NULL) return -1;
    list->size = new_size;
    return 0;
}


// len() ... retorna la cantidad de elementos en la lista
int len(arraylist *list) {return list->elements;}


// size() ... retorna el tamaño del array
int size(arraylist *list) {return list->size;}


// add() ... agregar un elemento al final de la lista
int add(arraylist *list, int num) {
    // si la lista esta llena reservamos mas espacio
    if (list->elements == list->size) {
        int result = resize(list);
        if (result == -1) return result;
    }

    *(list->nums + list->elements++) = num;
    return 0;
}


// addin() ... agregar un elemento en el indice dado. Retorna -1 si el indice es invalido
int addin(arraylist *list, int value, int index) {
    // comprobar que el indice sea valido
    if (index < 0 || index > list->elements) return -1;
    if (index == list->elements) return add(list, value);


    // si la lista esta llena reservamos mas espacio
    if (list->elements == list->size) {
        int result = resize(list);
        if (result == -1) return result;
    }

    int tmp = list->nums[index];
    list->nums[index] = value;
    for (int i = index + 1; i < list->elements + 1; i++) {
        int tmp2 = list->nums[i];
        list->nums[i] = tmp;
        tmp = tmp2;
    }
    list->elements++;
    return 0;
}


// del() ... elimina el ultimo elemento de la lista. Retorna -1 si la lista esta vacia
int del (arraylist *list) {
    // comprobar que la lista no este vacia
    if (list->elements == 0) return -1;

    *(list->nums + --list->elements) = 0;

    if (list->elements == (int) (0.25 * list->size)) return downsize(list);

    return 0;
}


// delin() ... elimina elimina elemento en indice dado
int delin(arraylist *list, int index) {
    // comprobar que el indice sea correcto
    if (list->elements == 0 || index < 0 || index > list->elements) return -1;

    if (index == list->elements - 1) return del(list);

    for (int i = index; i < list->elements; i++) {
        *(list->nums + i) = *(list->nums + i + 1);
    }
    list->elements--;

    if (list->elements == (int) (0.25 * list->size)) return downsize(list);

    return 0;
}


// get() ... consultar elemento por inidice
int get(arraylist *list, int index) {
    if (index < 0 || index > list->elements - 1) return -1;
    return *(list->nums + index);
}


// find() ... buscar el indice de un elemento, -1 si no se encuentra
int find(arraylist *list ,int num) {
    if (list->elements == 0) return -1;
    for (int i = 0; i < list->elements; i++) {
        if (*(list->nums + i) == num) return i;
    }
    return -1;
}


// set() ... modificar elemento en indice dado. Retorna -1 si no se pudo realizar
int set(arraylist *list, int num, int index) {
    if (list->elements == 0 || index < 0 || index > list->elements) return -1;
    *(list->nums + index) = num;
    return 0;
}


// del_list() ... libera la memoria ocupada por la lista
void del_list(arraylist *list) {
    free(list->nums);
    list->nums = NULL;
    free(list);
    list = NULL;
}


