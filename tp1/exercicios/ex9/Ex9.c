#include <stdio.h>

/*Em C nao pode mandar um string ou, no caso do C,
nao pode mandar um array de char.
Entao o esquema é fazer mudando o array la dentro*/

/*A magica daqui eh que voce consegue mudar o lnha
no meio dos metodos pq é um ponteiro, se fosse uma 
variavel ia ser uma local que nao ia funcoinar*/

void cifrando (char linha[], int i){
    if(linha[i] != '\0' && linha[i] != '\n'){
        linha[i]=linha[i]+3;
        cifrando(linha,i+1);
    }
}

void ciframentoCesar(char linha[]){
    cifrando(linha, 0);
}


int main(){

    char linha[1000];
    while (fgets(linha, 1000, stdin) !=NULL){
        if (linha[0]=='F' && linha[1]=='I' && linha[2]=='M' 
            && linha[3]=='\n'){
                return 0;
            }
    
    /*A ideia aqui é a mesma daquele outro exericio,
    o fgets as vezes pega o \n tambem, entao eu tenho
    que tirar para fazer a cifra de cesar*/
    int i = 0;
    while (linha[i] != '\0' && linha[i] != '\n'){
        i++;
        }
    linha[i]='\0';

    
    ciframentoCesar(linha);
    printf("%s\n", linha);
    }
}