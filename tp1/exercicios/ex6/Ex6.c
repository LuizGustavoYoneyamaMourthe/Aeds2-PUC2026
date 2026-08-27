#include <stdio.h>
#include <stdlib.h>

int anagrama(char string1[], char string2[]){
	int tamanho1=0, tamanho2=0;
	
	// primeiro mede o tamanho das strings
	// e aprovita e transforma maiuscula em minuscula
	for (int i=0; i<100; i++){
		if(string1[i]!='\0'){
			if (string1[i]>= 'A' && string1[i]<='Z'){
				string1[i] = string1[i] + 32;
			}
			tamanho1++;
		} else { i=100; }
	}
	//fazendo o mesmo com a segunda palavra
	for (int i=0; i<100; i++){
		if(string2[i]!='\0'){
			if (string2[i]>= 'A' && string2[i]<='Z'){
				string2[i] = string2[i] + 32;
			}
			tamanho2++;
		} else { i=100; }
	}

	//se o tamanho nao for o mesmo já nao eh anagrama
	if (tamanho1 != tamanho2) return 0;

	//para cada letra da primeira, acha e marca uma igual na segunda
	for (int i=0; i<tamanho1; i++){
		for (int j=0; j<tamanho2; j++){
			if (string1[i] == string2[j]){
                //marcando a posicao do string2 que ja achou letra correpondente
				string2[j] = '#'; 
				j = tamanho2;
			}
		}
	}

	//verificando se eh um anagrama perfeito
	for (int i=0; i<tamanho1; i++){
		if(string2[i] != '#'){ //string2 deve estar toda com #
			return 0;
		}
	}	

	return 1;
}


int main() {
    char string1[100], string2[100];

    // Le a primeira palavra e segunda palavra. Se for EOF, para.
    // Isso daqui é roubado pq já separa as duas palavras ja que o scanf le até o espacço
    while (scanf("%s %s", string1, string2) != EOF) {
        
        // Verifica se é FIM
        if (string1[0] == 'F' && string1[1] == 'I' && string1[2] == 'M' && string1[3] == '\0') {
            break;
        }

        //se der return 0 quer dizer que é falso, e printa NAO
        if (anagrama(string1, string2)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}