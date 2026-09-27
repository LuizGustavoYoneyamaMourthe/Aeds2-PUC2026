#include <stdio.h>


int somar (int n){
    if (n==0){
        return 0;
    }
    int resp = n + somar(n-1);
    return resp;
}

int main(){

    int n=5;

    int resp = somar(n);
    printf ("%d\n", resp);
}