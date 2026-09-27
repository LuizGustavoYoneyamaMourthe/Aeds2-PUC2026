#include <stdio.h>


int contar(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + contar(n / 10);
}


int main(){

    int n=40721;
    
    int resp = contar(n);
    printf ("%d\n", resp);
}