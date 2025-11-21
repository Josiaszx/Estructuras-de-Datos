// implementacion de pilas dinamicas con listas enlazadas para manejar enteros
// metodos a implementar:
//  - push() --> agregar elemento al tope
//  - pop() --> eliminar y retornar el elemento del tope
//  - peek() --> retornar el elemento del tope sin eliminarlo
//  - is_empty() --> retorna 1 si la pila esta vacia, 0
//  - size() --> retorna el numero de elementos en la pila

#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct node {
    int data;
    struct node *next;
} node;

// definicion del stack
typedef struct stack {
    node *bottom;
    node *top;
    int size;
} stack;

// crear una nueva pila
stack *newstack() {
    stack *s = malloc(sizeof(stack));
    if (s == NULL) return NULL;
    s->bottom = NULL;
    s->top = NULL;
    s->size = 0;
    return s;
}

// crear un nuevo nodo
node *newnode(int data) {
    node *n = calloc(1, sizeof(node));
    if (n == NULL) return NULL;
    n->data = data;
    n->next = NULL;
    return n;
}

// push() ... agregar elemento al tope - retornar -1 si hubo un error
int push(stack *s, int data) {
    if (s == NULL) return -1;
    if (s->size == 0) {
        node *n = newnode(data);
        if (n == NULL) return -1;
        s->bottom = n;
        s->top = n;
        s->size++;
        return 0;
    }
    if (s->size == 1) {
        node *n = newnode(data);
        if (n == NULL) return -1;
        s->bottom->next = n;
        s->top = n;
        s->size++;
        return 0;
    }
    node *n = newnode(data);
    if (n == NULL) return -1;

    s->top->next = n;
    s->top = n;
    s->size++;
    return 0;
}

// pop() ... eliminar y retornar el elemento del tope - retornar -1 si hubo un error
int pop(stack *s) {
    if (s == NULL) return -1;
    if (s->size == 0) return -1;
    if (s->size == 1) {
        int n = s->top->data;
        free(s->top);
        s->bottom = NULL;
        s->top = NULL;
        s->size--;
        return n;
    }
    if (s->size == 2) {
        int n = s->top->data;
        free(s->top);
        s->top = s->bottom;
        s->top->next = NULL;
        s->size--;
        return n;
    }
    node *aux = s->bottom;
    for (int i = 0; i < s->size - 2; i++) {
        aux = aux->next;
    }
    int data = s->top->data;
    free(s->top);
    aux->next = NULL;
    s->top = aux;
    s->size--;
    return data;
}

// peek() ... retornar el elemento del tope sin eliminarlo
int peek(stack *s) {
    if (s->size == 0) return -1;
    return s->top->data;
}

// is_empty() ... retornar 1 si esta vacia y 0 si no
int is_empty(stack *s) {
    return s->size == 0;
}

// size() ... retornar el tamaño de la pila
int size(stack *s) {
    return s->size;
}

// imprimir lista
void printstack(stack *s) {

    if (s->size == 0) {
        printf("la pila esta vacia\n");
        return;
    }

    if (s == NULL) {
        printf("la pila esta vacia\n");
        return;
    }

    int *nums = malloc(sizeof(int) * s->size);
    if (nums == NULL) {
        printf("error: sin memoria para imprimir la pila\n");
        return;
    }
    node *p = s->bottom;
    int i = 0;
    while (p != NULL) {
        *(nums+i) = p->data;
        p = p->next;
        i++;
    }

    printf("pila de numeros: \n");
    for (i = s->size-1; i >= 0; i--) {
        printf("- %d\n", *(nums + i));
    }
    printf("\n");
    free(nums);
}

// liberar toda la pila y sus nodos
void freestack(stack *s) {
    if (s == NULL) return;
    node *p = s->bottom;
    while (p != NULL) {
        node *next = p->next;
        free(p);
        p = next;
    }
    free(s);
}



int main() {
    stack *mystack = newstack();
    push(mystack, 1);
    push(mystack, 2);

    printstack(mystack); // --> 2 - 1

    pop(mystack);
    pop(mystack);

    printstack(mystack); // --> la pila esta vacia

    push(mystack, 3);
    push(mystack, 4);

    printf("el ulitimo numero en la pila: %d\n", peek(mystack)); // --> el ultimo numero en la pila: 4

    printstack(mystack); // --> 4 - 3

    freestack(mystack);

    return 0;
}
