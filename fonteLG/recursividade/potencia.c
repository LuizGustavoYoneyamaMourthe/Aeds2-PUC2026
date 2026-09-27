#include <stdio.h>


int potencia (int n, int exp) {
    if (exp == 0) {
        return 1;
    }
    return n * potencia (n, exp-1);
}


int main(){

    int n=2;
    int exp=10;
    
    int resp = potencia (n, exp);
    printf ("%d\n", resp);
}