public class Test {
    public static void main(String[] args) {
        
        var lista = new ListaEnlazada<String>();

        // Agregar elementos
        lista.agg("Juan");
        lista.agg("Marco");
        lista.agg("Pedro");

        // Agregar en indice dado
        lista.agg("Juana", 0);
        lista.agg("Andrea", 4);

        System.out.println(lista); // --> Juana -> Juan -> Marco -> Pedro -> Andrea
        
        lista.elim(0);
        System.out.println(lista); // --> Juan -> Marco -> Pedro -> Andrea

        System.out.println(lista.buscar("Juana")); // -1

        System.out.println(lista.obtener(2)); // --> Pedro
    }
}
