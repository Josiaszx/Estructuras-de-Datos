
// implementacion de pilas dinamicas con listas enlazadas para datos genericos
// metodos a implementar:
//  - push() --> agregar elemento al tope
//  - pop() --> eliminar y retornar el elemento del tope
//  - peek() --> retornar el elemento del tope sin eliminarlo
//  - isEmpty() --> retorna 1 si la pila esta vacia, 0
//  - size() --> retorna el numero de elementos en la pila

public class StackDinamico<T> {

    private Nodo<T> top;
    private Nodo<T> bottom;
    private int size;

    public StackDinamico() {
        top = bottom = null;
        size = 0;
    }

    // push() ... agregar elemento al tope
    public void push(T valor) {
        if (size == 0) {
            top = new Nodo(valor);
            bottom = top;
        } else if (size == 1) {
            top = new Nodo(valor);
            bottom.setSiguiente(top);
        } else {
            Nodo<T> aux = new Nodo(valor);
            top.setSiguiente(aux);
            top = aux;
        }
        size++;
    }

    // pop() ... eliminar y retornar el elemento del tope
    public T pop() {
        if (size == 0) {return null;}
        if (size == 1) {
            T valor = top.getValor();
            top = null;
            bottom = null;
            size--;
            return valor;
        }
        if (size == 2) {
            T valor = top.getValor();
            top = bottom;
            bottom.setSiguiente(null);
            size--;
            return valor;
        }
        Nodo<T> aux = bottom;
        for (int i = 0; i < size - 2; i++) {
            aux = aux.getSiguiente();
        }
        T valor = aux.getSiguiente().getValor();
        aux.setSiguiente(null);
        top = aux;
        size--;
        return valor;
    }

    // peek() ... retornar el elemento del tope sin eliminarlo
    public T peek() {
        if (size == 0) {return null;}
        return top.getValor();
    }

    // isEmpty() ... retorna 1 si la pila esta vacia, 0
    public boolean isEmpty() {return size == 0;}

    // size() ... retorna el numero de elementos en la pila
    public int size() {return size;}

    // imprimir stack
    public void printStack() {
        if (size == 0) {
            System.out.println("Stack vacio");
            return;
        }
        System.out.println("Stack:");
        Nodo<T> arr[] = new Nodo[size];
        Nodo<T> aux = bottom;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = aux;
            aux = aux.getSiguiente();
        }
        arr[size - 1] = top;
        for (int i = 0; i < arr.length; i++) {
            System.out.println("- " + arr[size - 1 - i]);
        }
        System.out.println();
    }


}

class Nodo<T> {

    private T valor;
    private Nodo<T> siguiente;

    public Nodo(T valor) {
        this.valor = valor;
        this.siguiente = null;
    }

    public Nodo() {}

    public Nodo<T> getSiguiente() {
        return siguiente;
    }

    public void setSiguiente(Nodo<T> siguiente) {
        this.siguiente = siguiente;
    }

    public T getValor() {
        return valor;
    }

    public void setValor(T valor) {
        this.valor = valor;
    }

    @Override
    public String toString() {
        return valor.toString();
    }
}

