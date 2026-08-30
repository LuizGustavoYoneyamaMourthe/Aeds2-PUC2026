import java.util.*;

public class Ex1 {

    public static void main (String[] args){

        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()){
            String linha = sc.nextLine();

            if (linha.length() == 3 && linha.charAt(0)=='F' && linha.charAt(1)=='I' && linha.charAt(2)=='M'){
                break;
            }
            
            //Cria um array de caracteres. Eu acho que dava para concatenar
            //e fazer uma string
            int tamanho = linha.length();
            char[] cifra = new char[linha.length()];
            

            for (int i = 0; i<tamanho; i++){
                cifra[i] = (char)(linha.charAt(i) + 3);
            }

            //cria uma string com o array de char
            String resposta = new String(cifra);

            System.out.println(resposta);
        }
        sc.close();

    }
    
}
