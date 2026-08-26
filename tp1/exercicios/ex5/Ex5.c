#include <stdio.h>
/*
int recursivaSomandoDigitos (int numero){
    return recursiva(numero, 0); 
}
*/
int recursiva (int numero){
    int resposta=0;
    if ((numero/10) == 0){
        return numero;
    }
    else {
        resposta = numero%10 + recursiva(numero/10);
    }
    return resposta;
}

int main(){
    int numero;

    while (scanf("%d", &numero) != EOF){
        int resposta = recursiva(numero);
        printf("%d\n", resposta);
    }
    return 0;

}