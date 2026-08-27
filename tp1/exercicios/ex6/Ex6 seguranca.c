#include <stdio.h>

//a ideia é contar as letras. Tem que dar numero par

int verifAnagrama (char linha[]){
    int tamanho = verifTamanho(linha);
    char palavra[50]={0};

    for (int i=0; i<tamanho; i++){
        if (palavra[i]==0){
            palavra
        }
    }

    
    return 1;
}

int verifTamanho (char linha[]){
    int i=0;
    while (linha[i] != '\0'){
        i++;
    }
    return (i);
}


int main(){
    char linha[50];
    int resp=0;
    while (fgets(linha, 50, stdin) !=NULL){
        if (linha[0]=='F' && linha[1]=='I' && linha[2]=='M' && linha[3]=='\0'){
            return 1;
        }

        resp = verifAnagrama(linha);//resp 1 = SIM, resp 0 = NAO
        if (resp==1){
            printf("SIM\n");
        } else ("NAO\n");
    }

}