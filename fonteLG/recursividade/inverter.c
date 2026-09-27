#include <stdio.h>

void inverter(char palavra[], int i) {
    if (palavra[i] == '\0') {
        return;
    }
    inverter(palavra, i + 1);
    printf("%c", palavra[i]);
}

int main() {
    char palavra[] = "recursao";
    inverter(palavra, 0);
    printf("\n");
    return 0;
}