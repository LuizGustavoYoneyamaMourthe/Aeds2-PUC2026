import java.util.*;


class Pilha {

    private int[] array;
    int n;

    public Pilha (){
        this(6);
    }

    public Pilha (int tamanho){
        array = new int[tamanho];
        n=0;
    }

    public void inserirFim(int x) throws Exception{
        if (n>= array.length){
            throw new Exception ("Erro");
        }
        array[n]=x;
        n++;
    }

    public int removerFim() throws Exception{
        if (n==0){
            throw new Exception ("Erro");
        }
        int resp = array[n-1];
        n--;
        return resp;
    }

}



    public class PilhaPrincipal {
        
    
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);

    }
}

