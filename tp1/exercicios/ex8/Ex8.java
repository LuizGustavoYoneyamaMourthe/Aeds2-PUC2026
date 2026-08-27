import java.util.*;

public class Ex8 {

    public static boolean validarSenha(String linha){
        int caracteres=0, maiusculas=0, minusculas=0, numeros=0, especial=0;
        
        //caracteres = verifCaracteres(linha);
        maiusculas = verifMaiusculas(linha);
        minusculas = verifMinusculas(linha);
        numeros = verifNumeros(linha);
        especial = verifEspecial(linha);
        
        if ((maiusculas >= 1 && minusculas >= 1 && numeros >= 1 && especial >=1)
        && ((maiusculas+minusculas+numeros+especial>=8))){
            return true;
        } else {
            return false;
        }
    }
    /*
    public static int verifCaracteres (String linha){
        int contador=0;
        
        for (int i=0; i<linha.length(); i++){
            if ( (linha.charAt(i)>= 'A' && linha.charAt(i)<='Z') || (linha.charAt(i)>= 'a' && linha.charAt(i)<='z')){
                contador++;
            }
        }
        return contador;
    }
    */
    public static int verifMaiusculas (String linha){
        int contador=0;
        
        for (int i=0; i<linha.length(); i++){
            if ((linha.charAt(i)>= 'A' && linha.charAt(i)<='Z')){
                contador++;
            }
        }
        return contador;
    }

    public static int verifMinusculas (String linha){
        int contador=0;
        
        for (int i=0; i<linha.length(); i++){
            if ( (linha.charAt(i)>= 'a' && linha.charAt(i)<='z')){
                contador++;
            }
        }
        return contador;
    }

    public static int verifNumeros (String linha){
        int contador=0;
        
        for (int i=0; i<linha.length(); i++){
            if ( (linha.charAt(i)>= '0' && linha.charAt(i)<='9')){
                contador++;
            }
        }
        return contador;
    }

    public static int verifEspecial (String linha){
        int contador=0;
        for (int i=0; i<linha.length(); i++){
            if ( (linha.charAt(i) < '0')
                || (linha.charAt(i) >'9' && linha.charAt(i) < 'A' )
                || (linha.charAt(i) >'Z' && linha.charAt(i) < 'a' )
                || (linha.charAt(i) > 'z')){
                contador++;
            }
        }
        return contador;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()){
            String linha = sc.nextLine();
            if (linha.length() == 3 && linha.charAt(0)=='F'&& linha.charAt(1)=='I'&& linha.charAt(2)=='M'){
                break;
            }

            boolean resposta = validarSenha(linha);

            if (resposta==true){
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }
    }

}
