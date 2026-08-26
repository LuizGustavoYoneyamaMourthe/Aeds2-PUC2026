import java.util.*;

public class Ex3 {

    public static boolean vogal (String linha){
        for (int i=0; i<linha.length(); i++){
            if (!(linha.charAt(i) == 'A' || linha.charAt(i) == 'a' ||
                linha.charAt(i) == 'E' || linha.charAt(i) == 'e' ||
                linha.charAt(i) == 'I' || linha.charAt(i) == 'i' ||
                linha.charAt(i) == 'O' || linha.charAt(i) == 'o' ||
                linha.charAt(i) == 'U' || linha.charAt(i) == 'u')){
                    return false;
                }
        }
        return true;
    }

    //aqui dificultou pq tem que procurar se é letra e consoante
    // se excluir o que nao é vogal pode cair um numero e 
    //entender como consoante

public static boolean consoantes(String linha) {
   for (int i = 0; i < linha.length(); i++) {
      char c = linha.charAt(i);
      boolean verifLetra = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
      boolean verifVogal = (c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u');
      if ( verifLetra==false || verifVogal==true) {
         return false;
      }
   }
   return true;
}

public static boolean inteiros (String linha){
    for (int i=0; i<linha.length(); i++){
        char c = linha.charAt(i);
        boolean verifLetra = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
        boolean verifNumero = (c >= '0' && c <= '9');
        if (verifLetra==true || verifNumero==false){
            return false;
        }
    }
    return true;
}

public static boolean reais (String linha){
    int pontoOuVirgula = 0;
    for (int i=0; i<linha.length();i++){
        char c = linha.charAt(i);
        if (c=='.' || c==','){
            pontoOuVirgula++;
        } else  if (c<'0' || c>'9'){
            return false;
        }
    }
    if(pontoOuVirgula<=1){ //"<= 1" pq parece que o exericio considera 43 numero real (mesmo sem .ou ,)
        return true;
    } else {
        return false;
    }
}

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            String linha = sc.nextLine();

            if (linha.length() == 3 && linha.charAt(0) == 'F' && linha.charAt(1) == 'I' && linha.charAt(2) == 'M') {
                break;
            }

            boolean X1 = vogal(linha);
            boolean X2 = consoantes(linha);
            boolean X3 = inteiros(linha);
            boolean X4 = reais(linha);

            if (X1 ==true){
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            
            if (X2 ==true){
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (X3 ==true){
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (X4 ==true){
                System.out.print("SIM\n");
            } else {
                System.out.print("NAO\n");
            }

        }
    }
}