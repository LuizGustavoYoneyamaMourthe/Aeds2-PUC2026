#include <stdio.h>
#include <stdlib.h>

int substring(char palavra[]){
	int n=0;//tamanho da array
	
	for (int i=0; palavra[i]!='\0'; i++){
			n++;
	}
	
	int max = 0;
       
	for (int i = 0; i < n; i++) {
        	int repetido[256] = {0}; // cria um array no tamanho da tabela ASCII
        	int tamanho = 0;

        	for (int j = i; j < n; j++) {
            		if (repetido[(int)palavra[j]] == 1) {//aqui eu transformo um lugar do array 
							     //"repetido" correpondente a tabela ASCII
							     //do caracter
							    //256 sao os 128 da tabela ascii mais os caracteres especiais 
                	break;
            	}
		repetido[(int)palavra[j]] = 1;
        	tamanho++;
        	}	

        	if (tamanho > max) {
            	max = tamanho;
        	}	
    	}

    return max;
}


int main(){
	char palavra[100];
	int resposta;
	while (scanf("%s", palavra) != EOF){
		if (palavra[0]=='F' && palavra[1]=='I' && palavra[2]=='M' && palavra[3]=='\0'){
			return 0;
		}
		resposta=substring(palavra);	
		printf("%d\n", resposta);	
			
	}//fim do while
	


}//fim do main
