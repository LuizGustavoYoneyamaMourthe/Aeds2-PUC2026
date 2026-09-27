#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21]; //nome 20 caracteres + positivio ou negativo
} kids;

int main() {
    int n, positivo = 0, negativo = 0;
    kids lista[100]; //no maximo 100 criancas
    char sinal;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c %s", &sinal, lista[i].nome); //o espaço é para pegar o enter

        if (sinal == '+') {
            positivo++;
        } else if (sinal == '-') {
            negativo++;
        }
    }

    

    for (int i = 0; i<n-1; i++){
        int menor = i;
        for (int j=i+1; j<n; j++){
            if (strcmp (lista[j].nome,lista[menor].nome) < 0){
                menor=j;
            }
        }
        kids temp = lista[i];
        lista[i]=lista[menor];
        lista[menor] = temp;
    }

    for (int i=0; i<n; i++){
        printf ("%s\n", lista[i].nome);
    }
     printf ("Se comportaram: %d | Nao se comportaram: %d\n", positivo, negativo);

    return 0;
}

/*ENUNCIADO

Papai Noel está nos preparativos finais para a entrega dos presentes para as crianças do mundo todo pois o natal está chegando mais uma vez. Olhando suas novas listas de crianças que irão ganhar presentes neste ano ele percebeu que o duende estagiário (que havia ficado responsável por fazer as listas) não havia colocado os nomes em ordem alfabética.

Como o Papai Noel é um homem muito organizado ele deseja que cada lista de crianças possua, no seu final, o total de crianças que foram bem comportadas neste ano e um total das que não foram. Assim ele pode comparar a quantidade de crianças que se comportam este ano com as dos anos anteriores.

Para ajudar o bom velhinho, seu dever é criar um programa que leia todos os nomes da lista e imprima os mesmos nomes em ordem alfabética. No final da lista, você deve imprimir o total de crianças que foram e não foram comportadas neste ano.

Entrada
A entrada é composta por vários nomes. O primeiro valor N (0 ≤ N ≤ 100), indica quantos nomes tem na lista. As N linhas seguintes, contem um caracter especial correspondente ao comportamento da criança (+ indica que a criança foi bem comportada, - indica que a criança não foi bem comportada). Após o caracter especial, segue o nome da criança com no máximo 20 caracteres.

Saída
Para cada lista de crianças, você deve imprimir os nomes em ordem alfabética. Após imprimir os nomes das crianças, você deve mostrar o total de crianças que se comportaram bem ou mal durante o ano.
*/