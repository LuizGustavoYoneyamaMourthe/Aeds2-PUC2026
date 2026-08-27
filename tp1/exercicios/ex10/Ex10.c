#include <stdio.h>

/*vou fazer tantos metodos que nao vou usar 
o metodo que manda o contador.*/


int soVogais(char linha[], int i){
    if(linha[i]!='\0' && linha[i]!='\n'){
        if(!(linha[i] == 'A' || linha[i] == 'a'
        || linha[i] == 'E' || linha[i] == 'e'
        || linha[i] == 'I' || linha[i] == 'i'
        || linha[i] == 'O' || linha[i] == 'o'
        || linha[i] == 'U' || linha[i] == 'u')){
            return 0;
            } else {
                return soVogais(linha, i+1);
            }
    }
    return 1;
}

int soConsoantes(char linha[], int i){
    if(linha[i]!='\0' && linha[i]!='\n'){
        if(
        (linha[i] == 'A' || linha[i] == 'a'
        || linha[i] == 'E' || linha[i] == 'e'
        || linha[i] == 'I' || linha[i] == 'i'
        || linha[i] == 'O' || linha[i] == 'o'
        || linha[i] == 'U' || linha[i] == 'u') //se ela for vogal
        || //OU 
        !((linha[i] >= 'A' && linha[i] <= 'Z') // se nao for uma letra
        || (linha[i] >= 'a' && linha[i] <= 'z'))
        )//fim do if de dentro
        {
            return 0;
            } else {
                return soConsoantes(linha, i+1);
            }
    }
    return 1;
}

int ehInteiro (char linha[], int i){
    if (linha[i] != '\0' && linha[i] != '\n'){
        if (!(linha[i]>='0' && linha[i]<='9')){
            return 0;
        } else {
            return ehInteiro(linha, i+1);
        }
    }
    return 1;
}

int ehReal (char linha[], int i, int pontoVirgula){
    if (linha[i] != '\0' && linha[i] != '\n'){
        if (!(linha[i]>='0' && linha[i]<='9') && (linha[i]!='.' && linha[i]!=',')){
            return 0;
        } else {
            if (linha[i]=='.' || linha[i]==','){
                pontoVirgula++;
                if (pontoVirgula > 1){
                    return 0;
                } else {
                    return ehReal(linha, i+1, pontoVirgula);
                }
            } else {
                return ehReal(linha, i+1, pontoVirgula);
            }  
        }
    }
    return 1;
}



int main(){
    char linha[1000];

    while (fgets(linha, 1000, stdin) !=NULL){

        if (linha[0] == 'F' && linha[1] == 'I' && linha[2] == 'M'){
            break;
        }

        /*A ideia aqui é a mesma daquele outro exericio,
        o fgets as vezes pega o \n tambem, entao eu tenho
        que tirar para fazer a cifra de cesar*/
        int i = 0;
        while (linha[i] != '\0' && linha[i] != '\n'){
            i++;
            }
        linha[i]='\0';

        /*para subs boolean vou colcar 1 = true 0=false*/
        int X1 = soVogais(linha, 0);
        
        //ja verifica se eh tudo vogal(X1==1), 
        //ai da para concluir que nao eh tudo consoante
        int X2;
        if (X1==1){
            X2==0;
        } else {
            X2 = soConsoantes(linha, 0);
        }

        int X3;
        if (X1==1 || X2==1){
            X3==0;
        } else {
            X3 = ehInteiro(linha, 0);
        }

        int X4;
        if (X1==1 || X2==1){
            X4==0;
        } else {
            X4 = ehReal(linha, 0, 0);
        }


        //int X3 = ehInteiro(linha);
        //int X4 = ehReal(linha);

        if (X1==1){printf ("SIM ");} else{printf ("NAO ");}
        if (X2==1){printf ("SIM ");} else{printf ("NAO ");}
        if (X3==1){printf ("SIM ");} else{printf ("NAO ");}
        if (X4==1){printf ("SIM\n");} else{printf ("NAO\n");}

    }



}