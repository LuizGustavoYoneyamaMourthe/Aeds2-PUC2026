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

int main() {
    char palavra[100];
    char resposta[100];

    scanf ("%s", palavra);

    while (palavra[0] != 'F' && palavra[1] != 'I' && palavra[2] != 'M') {

        int tamanho = contarLetras(palavra);

        for (int i=0; i<tamanho; i++){
            resposta[tamanho-1-i]=palavra[i];
        }
        resposta[tamanho] = '\0';

    printf ("%s\n", resposta);
    scanf ("%s", palavra);
    }

}