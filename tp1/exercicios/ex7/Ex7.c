#include <stdio.h>

/* Para cada posicao inicial, avanca enquanto nao repetir caractere.
   O vetor 'apareceu' marca quais caracteres ja foram vistos
   nessa tentativa, e eh zerado a cada novo inicio. */

int maiorSubstring(char linha[]) {
    int maior = 0;

    for (int inicio = 0; linha[inicio] != '\0'; inicio++) {
        int apareceu[256] = {0};
        int tamanho = 0;

        for (int j = inicio; linha[j] != '\0'; j++) {
            int c = (unsigned char) linha[j];

            if (apareceu[c] == 1) {
                break;   /* achou repetido, para de crescer */
            } else {
                apareceu[c] = 1;
                tamanho++;
            }
        }

        if (tamanho > maior) {
            maior = tamanho;
        }
    }

    return maior;
}

int main() {
    char linha[1000];

    while (fgets(linha, 1000, stdin) != NULL) {

        if (linha[0] == 'F' && linha[1] == 'I' && linha[2] == 'M' && linha[3] == '\n') {
            break;
        }

        /* tirando o \n que o fgets traz junto */
        int i = 0;
        while (linha[i] != '\0' && linha[i] != '\n') {
            i++;
        }
        linha[i] = '\0';

        printf("%d\n", maiorSubstring(linha));
    }

    return 0;
}