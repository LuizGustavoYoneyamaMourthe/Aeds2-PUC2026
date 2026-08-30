import java.util.*;


public class Ex11{

    
    
    
        public static String inversaoString(String palavra) {
    return inversaoString(palavra, palavra.length());
    }

    public static String inversaoString(String palavra, int i) {
        String resposta;
        //a ideia é a mesma do C => ir lendo de tras para frente e criando uma string nova concatenando
        //a diferença aqui é que no java tem como criar o tipo String ao inves de array de caracteres
        if (i == 0) {
            resposta = "";
        } else {
            resposta = palavra.charAt(i - 1) + inversaoString(palavra, i - 1);
            //string é imutavel no sentido de que nao adiante ficar modificando o resposta.charAt(i)
        }
        return resposta;
    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String palavra;
        String resposta;

        while(sc.hasNextLine()){
            
            palavra = sc.nextLine();
            
            if (palavra.length() == 3 && palavra.charAt(0)=='F' && palavra.charAt(1)=='I' && palavra.charAt(2)=='M'){
                break;
            }
            resposta = inversaoString(palavra);
            System.out.println(resposta);
        }

    }
}



