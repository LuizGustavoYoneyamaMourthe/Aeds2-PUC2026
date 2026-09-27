#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ano;
    int mes;
    int dia;

} Data;

Data parseData (char *linha){
    Data data;
    sscanf(linha, "%d-%d-%d", &data.ano, &data.mes, &data.dia);
    return data;
}

void formatData(Data d, char* linha) {
    sprintf(linha, "%02d/%02d/%04d", d.dia, d.mes, d.ano);
}


typedef struct { //chutei 50 para sobrar
    int id;
    char marca[50];
    char modelo[50];
    int ano;
    char categoria[50];
    char combustivel[5][50];   // ate 5 tipos de combustiveis, 50 chars cada
    int qtdCombustivel;        // quantos realmente tem -> importante para fazer o format
    int cilindros;
    double cilindrada;
    char transmissao[50];
    char tracao[50];
    double consumoCidade;
    double consumoEstrada;
    double co2;
    int turbo; //aqui era boolean, coloquei como 0 false e 1 verdadeiro
    Data dataRegistro;
} Veiculo;

void formatVeiculo(Veiculo v, char* buffer) {
    /* ESS PRIMEIRA PARTE É MUUUIIITTOOOO COMPLICADA, SERVE PARA JUNTAR COMBUSTÍVEIS
    ESTÃO SEPARADOS POR VIRGULA

    combinar[pos] vai recebendo  do v.combustivel[i][j] letra por letra, 
    ai apos o j coloca uma virgula, e depois volta para escrever outro combustivel.

    exemplo: i é o array que esta o combustivel e j é o nome do combustivel.
    no final combustivel[pos] vai ter, por exemplo, "alcool,gasolina"
    */

    char combinar[200]; //vai ser a linha do combustivel
    int pos = 0;
    for (int i = 0; i < v.qtdCombustivel; i++) {
        for (int j = 0; v.combustivel[i][j] != '\0'; j++) {
            combinar[pos] = v.combustivel[i][j];
            pos++;
        }
        if (i < v.qtdCombustivel - 1) {
            combinar[pos] = ',';
            pos++;
        }
    }
    combinar[pos] = '\0';


    // aqui o negocio é usar o metodo lá do data para formatar o v.dataRegistro
    char bufferData[20];
    formatData(v.dataRegistro, bufferData);

    sprintf(buffer, "[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1f ## %s ## %s ## %.2f ## %.2f ## %.1f ## %s ## %s]",
            v.id, v.marca, v.modelo, v.ano, v.categoria, combinar, v.cilindros, //combinar eh o combustivel!!!
            v.cilindrada, v.transmissao, v.tracao, v.consumoCidade,
            v.consumoEstrada, v.co2, v.turbo ? "true" : "false", bufferData);
}


Veiculo parseVeiculo(char* linha) {
    Veiculo v;
    char campos[15][200]; //o CSV tem 15 colunas, ai separa em 15 arranjos de 200 char
    int c = 0, pos = 0;

    // quebra a linha nas virgulas, campo a campo
    for (int i = 0; linha[i] != '\0' && linha[i] != '\n' && c < 15; i++) { //passa por cada char
        if (linha[i] == ',') {       //quando encontra uma "," copia para o campos[c][pos]
            campos[c][pos] = '\0';
            c++;
            pos = 0;
        } else {
            campos[c][pos] = linha[i]; //para ultima entrada depois da virgula
            pos++;
        }
    }
    campos[c][pos] = '\0';

    //no fim desse for cada campo[] vai ser uma coluna de uma linha do CSV
    //lembra que o ler CSV trabalha linha por linha



    //A IDEIA AQUI É CADA SPRINTF REGISTRA UMA COLUNA EM UMA ATRIBUTO
    //AQUI ESTA CONSTRUINDO O STRUCT
    //ISSO TUDO DO CAMPOS E TAL EH SO PQ A MERDA DO C NAO TEM CONSTRUTOR

    v.id = atoi(campos[0]); //é o Integer.parseInt -> string para int
    sprintf(v.marca, "%s", campos[1]);
    sprintf(v.modelo, "%s", campos[2]);
    v.ano = atoi(campos[3]);
    sprintf(v.categoria, "%s", campos[4]);

    // quebra o combustivel nos ponto-e-virgula
    v.qtdCombustivel = 0;
    pos = 0;
    for (int i = 0; campos[5][i] != '\0'; i++) {
        if (campos[5][i] == ';') { //se achar o ponto e virgula muda o combustivel
            v.combustivel[v.qtdCombustivel][pos] = '\0';
            v.qtdCombustivel++;
            pos = 0;
        } else {
            v.combustivel[v.qtdCombustivel][pos] = campos[5][i];
            pos++;
        }
    }
    v.combustivel[v.qtdCombustivel][pos] = '\0';
    v.qtdCombustivel++;

    v.cilindros = atoi(campos[6]);
    v.cilindrada = atof(campos[7]); //é o Double.parseDouble -> string para double
    sprintf(v.transmissao, "%s", campos[8]);
    sprintf(v.tracao, "%s", campos[9]);
    v.consumoCidade = atof(campos[10]);
    v.consumoEstrada = atof(campos[11]);
    v.co2 = atof(campos[12]);
    v.turbo = (campos[13][0] == 't');
    v.dataRegistro = parseData(campos[14]);

    return v;
}

int lerCsv(char* caminhoArquivo, Veiculo* veiculos) {
    char linha[1000]; //todo loop do while é sobreescrito entano nao tem problema
    int n = 0; //numero de veiculos

    FILE* arquivo = fopen(caminhoArquivo, "r"); //modo leitura
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    fgets(linha, 1000, arquivo);   // isso daqui eh so para pular o cabeçalho, tipo o sc.nextLine()

    while (fgets(linha, 1000, arquivo) != NULL && n < 500) { //le ate nul ou até chegar no 500
        veiculos[n] = parseVeiculo(linha);
        n++;
    }

    fclose(arquivo);
    return n;
}



//fazendo aqui a lista
typedef struct Celula {
    Veiculo elemento;
    struct Celula* prox;   // precisa do "struct Celula" pq o typedef ainda nao acabou
} Celula;

typedef struct {
    Celula* primeiro;   // celula cabeca
    Celula* ultimo;
} Lista;

// cria uma celula nova na memoria com return do ponteiro
Celula* novaCelula(Veiculo v) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = v;
    nova->prox = NULL;
    return nova;
}

void inicializarLista(Lista* l) {
    l->primeiro = (Celula*) malloc(sizeof(Celula));   // so a cabeca
    l->primeiro->prox = NULL;
    l->ultimo = l->primeiro;   // lista vazia: os dois no mesmo lugar
}

// conta quantos veiculos tem de verdade (a cabeca nao conta)
int tamanhoLista(Lista* l) {
    int tamanho = 0;
    for (Celula* i = l->primeiro; i != l->ultimo; i = i->prox) {
        tamanho++;
    }
    return tamanho;
}

void inserirInicio(Lista* l, Veiculo v) {
    Celula* tmp = novaCelula(v);
    tmp->prox = l->primeiro->prox;
    l->primeiro->prox = tmp;

    if (l->primeiro == l->ultimo) {   // a lista estava vazia
        l->ultimo = tmp;
    }
}

void inserirFim(Lista* l, Veiculo v) {
    l->ultimo->prox = novaCelula(v);
    l->ultimo = l->ultimo->prox;
}

void inserir(Lista* l, Veiculo v, int pos) {
    int tamanho = tamanhoLista(l);

    if (pos == 0) {
        inserirInicio(l, v);
    } else if (pos == tamanho) {
        inserirFim(l, v);
    } else {
        // anda ate a celula antes a posicao que quero
        Celula* i = l->primeiro;
        for (int j = 0; j < pos; j++) {
            i = i->prox;
        }

        Celula* tmp = novaCelula(v);
        tmp->prox = i->prox;
        i->prox = tmp;
    }
}

Veiculo removerInicio(Lista* l) {
    Celula* tmp = l->primeiro;
    l->primeiro = l->primeiro->prox;   // a primeira celula real vira a nova cabeca
    Veiculo resp = l->primeiro->elemento;
    tmp->prox = NULL;
    free(tmp);    // devolve a memoria da cabeca velha
    return resp;
}

Veiculo removerFim(Lista* l) {
    //percorre a lista toda até a utlima posicao
    Celula* i;
    for (i = l->primeiro; i->prox != l->ultimo; i = i->prox);

    Veiculo resp = l->ultimo->elemento;
    i->prox = NULL;
    free(l->ultimo);
    l->ultimo = i;
    return resp;
}

Veiculo remover(Lista* l, int pos) {
    Veiculo resp;
    int tamanho = tamanhoLista(l);

    if (pos == 0) {
        resp = removerInicio(l);
    } else if (pos == tamanho - 1) {
        resp = removerFim(l);
    } else {
        // anda ate a celula antes da que vou tirar
        Celula* i = l->primeiro;
        for (int j = 0; j < pos; j++) {
            i = i->prox;
        }

        Celula* tmp = i->prox;    
        resp = tmp->elemento;
        i->prox = tmp->prox;      
        tmp->prox = NULL;
        free(tmp);
    }
    return resp;
}

// mostra do primeiro ate o fim, seguindo os ponteiros
void mostrarLista(Lista* l) {
    char temp[500];
    for (Celula* i = l->primeiro->prox; i != NULL; i = i->prox) {
        formatVeiculo(i->elemento, temp);
        printf("%s\n", temp);
    }
}

// procura o veiculo pelo id no arranjo lido do CSV
Veiculo buscar(Veiculo* veiculos, int n, int id) {
    Veiculo resp = veiculos[0];
    for (int i = 0; i < n; i++) {
        if (veiculos[i].id == id) {
            resp = veiculos[i];
            i = n;
        }
    }
    return resp;
}


int main() {
    Veiculo veiculos[500]; //ja sei que tem 500 veiculos

    //ATENCAO     /tmp/veiculos.csv
    //    "/home/lgym/3-período/AEDS 2/TP-LGYM/tp2/veiculos.csv"
    int n = lerCsv("/tmp/veiculos.csv", veiculos);

    Lista lista;
    inicializarLista(&lista);

    int id;

    // primeira parte: monta o array para fazer a pesquisa até -1
    while (scanf("%d", &id) == 1) {
        if (id == -1) {
            break;
        }
        inserirFim(&lista, buscar(veiculos, n, id));
    }

    // segunda parte: quantidade de comandos e depois os comandos
    int qtdComandos;
    scanf("%d", &qtdComandos);

    char comando[10];
    int pos;

    for (int c = 0; c < qtdComandos; c++) {
        scanf("%s", comando);

        if (comando[0] == 'I') {
            if (comando[1] == 'I') {          // II = inserir inicio
                scanf("%d", &id);
                inserirInicio(&lista, buscar(veiculos, n, id));
            } else if (comando[1] == 'F') {   // IF = inserir fim
                scanf("%d", &id);
                inserirFim(&lista, buscar(veiculos, n, id));
            } else {                          // I* = inserir na posicao
                scanf("%d", &pos);
                scanf("%d", &id);
                inserir(&lista, buscar(veiculos, n, id), pos);
            }
        } else {
            Veiculo removido;
            if (comando[1] == 'I') {          // RI = remover inicio
                removido = removerInicio(&lista);
            } else if (comando[1] == 'F') {   // RF = remover fim
                removido = removerFim(&lista);
            } else {                          // R* = remover da posicao
                scanf("%d", &pos);
                removido = remover(&lista, pos);
            }
            printf("(R)%s %s\n", removido.marca, removido.modelo);
        }
    }

    mostrarLista(&lista);

    return 0;
}

 /*
    Veiculo v;
    v.id = 63595;
    sprintf(v.marca, "Honda");
    sprintf(v.modelo, "Civic Hybrid");
    v.ano = 2005;
    sprintf(v.categoria, "Compact Cars");
    sprintf(v.combustivel[0], "Gasoline");
    sprintf(v.combustivel[1], "Electricity");
    v.qtdCombustivel = 2;
    v.cilindros = 4;
    v.cilindrada = 1.3;
    sprintf(v.transmissao, "CVT");
    sprintf(v.tracao, "Front-Wheel Drive");
    v.consumoCidade = 16.58;
    v.consumoEstrada = 17.86;
    v.co2 = 134.7;
    v.turbo = 0;
    v.dataRegistro = parseData("2013-01-01");
    char linha[500];
    formatVeiculo(v, linha);
    printf("%s\n", linha);
    */

    /*
    char kenya[20] = "1996-06-01";
    Data d = parseData(kenya);
    printf("Kenya nasceu em ano=%d mes=%d dia=%d\n", d.ano, d.mes, d.dia);
    char buffer[20];
    formatData(d,buffer);
    printf ("%s\n", buffer);
    return 0;
    */


     



