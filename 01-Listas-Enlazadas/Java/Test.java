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

        System.out.println(lista);

        lista.elim(0);
        System.out.println(lista);

        System.out.println(lista.buscar("Juana"));
    }
}
