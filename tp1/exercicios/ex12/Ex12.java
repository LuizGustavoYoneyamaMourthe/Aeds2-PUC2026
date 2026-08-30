import java.util.*;

public class Ex12 {


    //eh exatamente a mesma coisa do 5 mas em java
    public static int somarDigitos(int numero){
        int resposta=0;
        if (numero/10==0){
            return numero%10;
        }
        else {
            resposta = (numero%10)+ somarDigitos(numero/10);
        }
        return resposta;
    }

    
    public static void main (String[] args){

        Scanner sc = new Scanner(System.in);

        int numero;

        while (sc.hasNextInt()){
            
            numero=sc.nextInt();

            int resposta = somarDigitos(numero);

            System.out.println(resposta);


        }
    }

}
