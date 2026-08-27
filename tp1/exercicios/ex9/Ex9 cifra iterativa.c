#include <stdio.h>

int main(){

    char linha[100];
    while (fgets(linha, 100, stdin) !=NULL){
        if (linha[0]=='F' && linha[1]=='I' && linha[2]=='M' 
            && linha[3]=='\n'){
                return 0;
            }

    int i = 0;
    while (linha[i] != '\0' && linha[i] != '\n') {
        linha[i] = linha[i] + 3;
        i++;
    }
    linha[i] = '\0';
    printf("%s\n", linha);
    }
}