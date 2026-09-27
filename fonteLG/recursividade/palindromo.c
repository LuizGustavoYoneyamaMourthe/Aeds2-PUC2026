#include <stdio.h>
#include <string.h>

int palindromo(char palavra[], int i, int j) {
    if (i >= j) {
        return 0;          // cruzou sem diferença → é palindromo
    }
    if (palavra[i] != palavra[j]) {
        return 1;          // achou par diferente → nao é
    }
    return palindromo(palavra, i + 1, j - 1);
}

int main() {
    char palavra[] = "arara";
    printf("%d\n", palindromo(palavra, 0, strlen(palavra) - 1));
    return 0;
}