import java.util.*;

class Fila {
    private int[] array;
    private int primeiro, ultimo;

    public Fila() {
        this(5);
    }

    public Fila (int tamanho){
        array = new int[tamanho+1];
        primeiro = ultimo = 0;
    }

    public void inserir(int x) throws Exception {
        if (((ultimo+1)%array.length) == primeiro){
            throw new Exception ("array cheio");
        }
        array[ultimo]=x;
        ultimo = (ultimo+1)%array.length;
    }

    /*ATENÇÃO!!!!!
    Lembre que isso é fila, entao voce só insere no fim e remove o inicio */
    public int remover() throws Exception {
        if (primeiro==ultimo) {
            throw new Exception ("array vazio");
        }
        int resp = array[primeiro];
        primeiro = (primeiro+1)%array.length;
        return resp;        
    }

    public void mostrar(){
        int i=primeiro;
        System.out.print("[");
        while (i!=ultimo){
            System.out.print(array[i] + " ");
            i = (i+1)%array.length;
        }
        System.out.println("]");
    }



}


public class FilaCircular {

    public static void main (String[] args) throws Exception{
        Fila inss = new Fila(6);
        inss.inserir(9);
        inss.inserir(3);
        inss.inserir(2);
        inss.inserir(2);
        inss.inserir(1);
        inss.remover();
        inss.mostrar();

    }

}