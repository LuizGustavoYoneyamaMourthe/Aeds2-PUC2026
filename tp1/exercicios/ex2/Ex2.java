import java.util.*;

public class Ex2 {

    //tem que declarar aqui encima esse metodo
    public static Random gerador = new Random();

    //alteracao aleatoria
    public static String alteracaoAleatoria (String linha){
        //linha = ("Mantegada Defenduro!");
        //return linha;

        //pegando 2 letras aleatorias
        char letra1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
        char letra2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));

        String resposta = trocarLetras(letra1, letra2,linha);

        return resposta;

    }

    public static String trocarLetras (char letra1, char letra2, String linha){
        
        //tenho que criar um array de char para conseguir mudar o conteudo da posicao
        //nao da para mudar um String em java
        char[] resposta = new char[linha.length()];

        for (int i=0; i<linha.length(); i++){

            if (linha.charAt(i)== letra1){
                resposta[i] = letra2;
            } else {
                resposta[i] = linha.charAt(i);
            }
        }
        //convendo o array de char em string
        return new String(resposta);
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        gerador.setSeed(4);
        
        while(sc.hasNextLine()){

            String linha = sc.nextLine();

            if (linha.length() == 3 && linha.charAt(0)=='F' && linha.charAt(1)=='I' && linha.charAt(2)=='M'){
                break;
            }

            String resposta = alteracaoAleatoria(linha);
            System.out.println(resposta);


        }


    }
    
}
