public class ListaEnlazada<T> {
    
    // nodos
    Nodo<T> primero;
    Nodo<T> ultimo;
    int longitud;

    public ListaEnlazada() {
        primero = ultimo = null;
        longitud = 0;
    }

    // agregar un elemento al final
    public void agg(T dato) {
        Nodo<T> nodo = new Nodo<>(dato);
        if (estaVacio()) primero = ultimo = nodo;
        else if (longitud == 1) {
            ultimo = nodo;
            primero.setSig(ultimo);
        }
        else {
            ultimo.setSig(nodo);
            ultimo = nodo;
        }
        longitud++;
    }

    // agregar un elemento en una posicion dada
    public void agg(T dato, int pos) {
        if (pos < 0 || pos > longitud) throw new IndexOutOfBoundsException();
        if (estaVacio() || longitud == 1 || pos == longitud) agg(dato);
        else if (pos == 0) {
            Nodo<T> nodo = new Nodo<>(dato);
            nodo.setSig(primero);
            primero = nodo;
            longitud++;
        }
        else {
            Nodo<T> nodo = new Nodo<>(dato);
            Nodo<T> aux = primero;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux.getSig();
            }
            nodo.setSig(aux.getSig());
            aux.setSig(nodo);
            longitud++;
        }
    }

    // eliminar el ultimo elemento
    public void elim() {
        if (estaVacio()) throw new RuntimeException("Lista vacia");
        if (longitud == 1) primero = ultimo = null;
        else if (longitud == 2) {
            ultimo = primero;
            primero.setSig(null);
        }
        else {
            Nodo<T> aux = primero;
            for (int i = 1; i < longitud - 1; i++) {
                aux = aux.getSig();
            }
            aux.setSig(null);
            ultimo = aux;
        }
        longitud--;
    }

    // eliminar el elemento en indice dado
    public void elim(int pos) {
        if (estaVacio()) throw new RuntimeException("Lista vacia");
        if  (pos < 0 || pos > longitud) throw new IndexOutOfBoundsException();
        if (pos == longitud - 1) elim();
        else if (pos == 0) {
            primero = primero.getSig();
            longitud--;
        }
        else {
            Nodo<T> aux = primero;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux.getSig();
            }
            aux.setSig(aux.getSig().getSig());
            longitud--;
        }
    }

    // buscar dato, retorna el indice de su posicion o -1 si no lo encuentra
    public int buscar(T dato) {
        if (estaVacio()) throw new RuntimeException("Lista vacia");
        if (primero.getDato().toString().equals(dato.toString())) return 0;
        else if (ultimo.getDato().toString().equals(dato.toString())) return longitud - 1;
        else {
            Nodo<T> aux = primero;
            int pos = 0;
            while (aux != null) {
                if (aux.getDato().toString().equals(dato.toString())) return pos;
                aux = aux.getSig();
                pos++;
            }
            return -1;
        }
    }

    // obtener dato en indice dado
    public T obtener(int pos) {
        if (estaVacio()) throw new RuntimeException("Lista vacia");
        if (pos < 0 || pos > longitud) throw new IndexOutOfBoundsException();
        if (pos == 0)  return primero.getDato();
        else if (pos == longitud - 1) return ultimo.getDato();
        else {
            Nodo<T> aux = primero;
            for (int i = 0; i < pos; i++) {
                aux = aux.getSig();
            }
            return aux.getDato();
        }
    }

    public boolean estaVacio() {
        return longitud == 0;
    }


    @Override
    public String toString() {
        Nodo<T> nodo = primero;
        String rsp = "";
        while (nodo != null) {
            if (nodo.getSig() != null)rsp += nodo.getDato().toString() + " -> ";
            else rsp += nodo.getDato().toString();
            nodo = nodo.getSig();
        }
        return rsp;
    }
}
