#include <stdio.h>

//a ideia é separar as palavras
//contar as letras e comparar

int verifAnagrama (char linha[]){
    int tamanho = letraAteEspaco(linha);
    for (int i=0, j=tamanho; i<(tamanho/2); i++, j--){
        
    }
    
    return 1;
}

int letraAteEspaco (char linha[]){
    int contador=0, i=0;
    while (linha[i] != '\0'){
        contador++;
        i++;
    }
    return (contador);
}


int main(){
    char linha[100];
    int resp=0;
    while (fgets(linha, 100, stdin) !=NULL){
        resp = verifAnagrama(linha);//resp 1 = SIM, resp 0 = NAO
    }

}