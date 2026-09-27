import java.util.*;


class Lista{
        private int[] array;
        private int n;

        public Lista(){
            this(6);
        }

        public Lista(int tamanho){
            array = new int[tamanho];
            n=0;
        }

        public void inserirInicio(int x) throws Exception {
            //verificar se está cheia
            if (n>=array.length) {
                throw new Exception("Erro");
            }
            for (int i = n; i>0; i--){
                array[i]=array[i-1];
            }
            array[0]=x;
            n++;
        }

        public void inserirFim(int x) throws Exception {
            //verificar se está cheia
            if (n>=array.length){
                throw new Exception ("Erro");
            }
            array[n]=x;
            n++;
        }

        public void inserir (int x, int pos) throws Exception {
            if (n>=array.length || pos < 0 || pos > n){
                throw new Exception("Erro");
            }
            for (int i = n; i>pos; i--){
                array[i]=array[i-1];
            }
            array[pos]=x;
            n++;
        }

        public int removerInicio() throws Exception {
            //verificar se esta vazia
            if (n==0){
                throw new Exception ("Erro");
            }
            int resp = array[0];
            n--;//importante isso daqui

            // trazer todos para esquerda
            for (int i = 0; i<n; i++){
            array [i] = array[i+1];
            }
            
            return resp;
        }

        public int removerFim() throws Exception {
            //ver se estar cheio
            if (n==0){
                throw new Exception ("Erro");
            }
            int resp = array[n-1];
            n--;
            return resp;
        }

        public int remover(int pos) throws Exception {
            // ver se esta cheio e a posicao é valida
            if (n==0 || pos < 0 || pos >= n) {
                throw new Exception ("Erro");
            }
            int resp = array[pos];
            n--;
            for (int i = pos; i < n ; i++){
                array[i] = array [i+1];
            }
            return resp;
        }



        public void mostrar(){
            System.out.print("[");
            for (int i=0; i<n; i++){
                System.out.print(array[i] + " ");
            }
            System.out.print("]");
        }


    }//fim da class Lista




public class ListaPrincipal{

    public static void main (String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        Lista compras = new Lista(5);
        compras.inserirInicio(0);
        compras.inserirInicio(1);
        compras.inserirInicio(2);
        compras.inserirFim(9);
        compras.inserir(8, 2);
        compras.removerFim();

        compras.mostrar();

        
    }
}