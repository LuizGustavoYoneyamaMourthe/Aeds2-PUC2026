#include <stdio.h>

int contarLetras (char palavra[]){
    int contador =0;
    for (int i=0; i<100; i++){
        if (palavra[i] != '\0'){
            contador++;
        } else {
            i=100;
        }
    }
    return contador;
}

void lerLinha (char palavra[]){
    fgets (palavra, 100, stdin);
    int tamanho = contarLetras(palavra);
    if (tamanho > 0 && palavra[tamanho-1] == '\n'){
        palavra[tamanho-1] = '\0';
    }
}

int main() {
    char palavra[100];
    char resposta[100];

    lerLinha (palavra);

    while (!(palavra[0]=='F' && palavra[1]=='I' && palavra[2]=='M' && palavra[3]=='\0')) {

        int tamanho = contarLetras(palavra);

        for (int i=0; i<tamanho; i++){
            resposta[tamanho-1-i]=palavra[i];
        }
        resposta[tamanho] = '\0';

    printf ("%s\n", resposta);
    lerLinha (palavra);
    }

}