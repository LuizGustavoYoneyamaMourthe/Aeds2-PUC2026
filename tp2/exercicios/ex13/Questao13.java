import java.util.*;
import java.io.*;

class Data {
	private int ano;
	private int mes;
	private int dia;

	public Data(int ano, int mes, int dia){
		this.ano = ano;
		this.mes = mes;
		this.dia = dia;
	}

	public int getAno(){ 
		return ano;
	}
	
	public int getMes(){ 
		return mes; 
	}
	
	public int getDia(){ 
		return dia; 
	}

	// Recebe "AAAA-MM-DD" e retorna um Data
	public static Data parseData(String linha){
		String[] partes = linha.split("-");
		return new Data(Integer.parseInt(partes[0]),
		                Integer.parseInt(partes[1]),
		                Integer.parseInt(partes[2]));
	}

	// Retorna a data no formato DD/MM/YYYY
	public String format(){
		return String.format("%02d/%02d/%04d", dia, mes, ano);
	}
}

class Veiculo {
	private int id;
	private String marca;
	private String modelo;
	private int ano;
	private String categoria;
	private String[] combustivel;
	private int cilindros;
	private double cilindrada;
	private String transmissao;
	private String tracao;
	private double consumoCidade;
	private double consumoEstrada;
	private double co2;
	private boolean turbo;
	private Data dataRegistro;

	public Veiculo(int id, String marca, String modelo, int ano, String categoria,
	               String[] combustivel, int cilindros, double cilindrada,
	               String transmissao, String tracao, double consumoCidade,
	               double consumoEstrada, double co2, boolean turbo, Data dataRegistro){
		this.id = id;
		this.marca = marca;
		this.modelo = modelo;
		this.ano = ano;
		this.categoria = categoria;
		this.combustivel = combustivel;
		this.cilindros = cilindros;
		this.cilindrada = cilindrada;
		this.transmissao = transmissao;
		this.tracao = tracao;
		this.consumoCidade = consumoCidade;
		this.consumoEstrada = consumoEstrada;
		this.co2 = co2;
		this.turbo = turbo;
		this.dataRegistro = dataRegistro;
	}

	public int getId(){ 
		return id;
	}
	
	public String getMarca(){
		return marca;
	}
	
	public String getModelo(){
		return modelo;
	}
	public int getAno(){
		return ano;
	}

	public String getCategoria(){
		return categoria;
	}

	public String[] getCombustivel(){
		return combustivel;
	}

	public int getCilindros(){
		return cilindros;
	}

	public double getCilindrada(){
		return cilindrada;
	}

	public String getTransmissao(){
		return transmissao;
	}

	public String getTracao(){
		return tracao;
	}

	public double getConsumoCidade(){
		return consumoCidade;
	}

	public double getConsumoEstrada(){
		return consumoEstrada;
	}

	public double getCo2(){
		return co2;
	}

	public boolean isTurbo(){
		return turbo;
	}

	public Data getDataRegistro(){
		return dataRegistro;
	}

	/* 
	Pega uma linha do CSV (linha) e retorna um new Veiculo
	(0)id, (1)marca, (2)modelo, (3)ano, (4)categoria, (5)combustivel, (6)cilindros,
	(7)cilindrada, (8)transmissao, (9)tracao, (10)consumo_cidade, (11)consumo_estrada,
	(12)co2, (13)turbo, (14)data_registro
	*/

	public static Veiculo parseVeiculo(String linha){
		String[] arrayVeiculos = linha.split(",");
		return new Veiculo(
						   Integer.parseInt(arrayVeiculos[0]), //converter string em int
		                   arrayVeiculos[1],
		                   arrayVeiculos[2],
		                   Integer.parseInt(arrayVeiculos[3]),
		                   arrayVeiculos[4],
		                   arrayVeiculos[5].split(";"), //combustivel
		                   Integer.parseInt(arrayVeiculos[6]),
		                   Double.parseDouble(arrayVeiculos[7]), //converter string em double
		                   arrayVeiculos[8],
		                   arrayVeiculos[9],
		                   Double.parseDouble(arrayVeiculos[10]),
		                   Double.parseDouble(arrayVeiculos[11]),
		                   Double.parseDouble(arrayVeiculos[12]),
		                   Boolean.parseBoolean(arrayVeiculos[13]),
		                   Data.parseData(arrayVeiculos[14]) //metodo que fiz la encima
						);
	}

	/*COMO FORMATAR: 
	[id ## marca ## modelo ## ano ## categoria ## [combustivel] ## cilindros ##
	cilindrada ## transmissao ## tracao ## consumoCidade ## consumoEstrada ## co2
	## turbo ## dataRegistro] 
	*/
	
	public String format(){

		String combinar = ""; // AQUI UMA MARACUTAIA PARA COMBINAR OS COMBUSTIVEIS
		//combustivel.length devolve o numero de entradas no arranjo combustivel
		for (int i = 0; i < combustivel.length; i++){ 
			combinar += combustivel[i];
			if (i < combustivel.length - 1){  //se tiver 1 combustivel nem entra no if
				combinar += ",";
			}
		}
		return String.format("[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1f ## %s ## %s ## %.2f ## %.2f ## %.1f ## %b ## %s]",
            id, marca, modelo, ano, categoria, combinar, cilindros, cilindrada,
            transmissao, tracao, consumoCidade, consumoEstrada, co2, turbo,
            dataRegistro.format());

	}
}

class LeitorCsv {

	// Le o CSV e retorna um arranjo com todos os veiculos (ignora o cabecalho)
	public static Veiculo[] ler(String caminhoArquivo){
		Veiculo[] veiculos = new Veiculo[500]; // 500 veiculos no veiculos.csv

		try {
			Scanner sc = new Scanner(new File(caminhoArquivo));
			sc.nextLine(); // descarta o cabecalho
			int i = 0;
			while (sc.hasNextLine() && i < veiculos.length){
				veiculos[i] = Veiculo.parseVeiculo(sc.nextLine());
				i++;
			}
			sc.close();
		} catch (FileNotFoundException e){
			System.out.println("Arquivo nao encontrado");
		}

		return veiculos;
	}
}

class Celula {
    public Veiculo elemento;   // o veiculo guardado nesta celula
    public Celula ant;         // celula anterior
    public Celula prox;        // proxima celula

    public Celula(){
        this(null);
    }

    public Celula(Veiculo elemento){
        this.elemento = elemento;
        this.ant = null;
        this.prox = null;
    }
}

class ListaDupla {
    private Celula primeiro;   // celula cabeça
    private Celula ultimo;

    public ListaDupla(){
        primeiro = new Celula();   // criando cabeça
        ultimo = primeiro;         
    }

    // ve quantos veiculos tem na listadupla
    public int tamanho(){
        int tamanho = 0;
        for (Celula i = primeiro.prox; i != null; i = i.prox){
            tamanho++;
        }
        return tamanho;
    }

    public void inserirInicio(Veiculo veiculo){
        Celula tmp = new Celula(veiculo);
        tmp.ant = primeiro;
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;

        if (primeiro == ultimo){   // serve para quando a lista esta vazia
            ultimo = tmp;
        } else {
            tmp.prox.ant = tmp;
        }
    }

    public void inserirFim(Veiculo veiculo){
        ultimo.prox = new Celula(veiculo);
        ultimo.prox.ant = ultimo;
        ultimo = ultimo.prox;
    }

    public void inserir(Veiculo veiculo, int pos) throws Exception {
        int tamanho = tamanho();
		//aqui eh so copiar do slide
        if (pos < 0 || pos > tamanho){
            throw new Exception("Erro!");
        } else if (pos == 0){
            inserirInicio(veiculo);
        } else if (pos == tamanho){
            inserirFim(veiculo);
        } else {
            // para 1 antes da celula que quero
            Celula i = primeiro;
            for (int j = 0; j < pos; j++){
                i = i.prox;
            }

            Celula tmp = new Celula(veiculo);
            tmp.ant = i;
            tmp.prox = i.prox;
            tmp.ant.prox = tmp;
            tmp.prox.ant = tmp;
        }
    }

    public Veiculo removerInicio() throws Exception {
        if (primeiro == ultimo){
            throw new Exception("Erro, lista vazia!");
        }

        Celula tmp = primeiro;
        primeiro = primeiro.prox;   // a primeira celula passa a ser a cabeça
        Veiculo resp = primeiro.elemento;
        tmp.prox = null;
        primeiro.ant = null;
        return resp;
    }

    public Veiculo removerFim() throws Exception {
        if (primeiro == ultimo){
            throw new Exception("Erro, lista vazia!");
        }

        Veiculo resp = ultimo.elemento;
        ultimo = ultimo.ant;    // o penultimo passa a ser o ultimo
        ultimo.prox.ant = null;
        ultimo.prox = null;
        return resp;
    }

    public Veiculo remover(int pos) throws Exception {
        Veiculo resp;
        int tamanho = tamanho();

        if (primeiro == ultimo || pos < 0 || pos >= tamanho){
            throw new Exception("Erro, posicao invalida!");
        } else if (pos == 0){
            resp = removerInicio(); //simplificando
        } else if (pos == tamanho - 1){
            resp = removerFim(); //simplificando
        } else {
            // aqui eu paro na posicao que quero
            Celula i = primeiro.prox;
            for (int j = 0; j < pos; j++){
                i = i.prox; //vai arrendano
            }

            // pula a celula que o i esta apontando
            i.ant.prox = i.prox;
            i.prox.ant = i.ant;
            resp = i.elemento;
            i.prox = i.ant = null;
        }
        return resp;
    }

    public void mostrar(){
        for (Celula i = primeiro.prox; i != null; i = i.prox){
            System.out.println(i.elemento.format());
        }
    }
}

public class Questao13{

    	public static Veiculo buscar(Veiculo[] veiculos, int id) {
		Veiculo resp = null;
		for (int i = 0; i < veiculos.length; i++) {
			if (veiculos[i].getId() == id) {
				resp = veiculos[i];
				i = veiculos.length;
			}
		}
		return resp;
	}

	public static void main (String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		
		
		
		//ATENCAO /tmp/veiculos.csv
		//"/home/lgym/3-período/AEDS 2/TP-LGYM/tp2/veiculos.csv"

		Veiculo[] veiculos = LeitorCsv.ler("/tmp/veiculos.csv");
		int n;

		ListaDupla lista = new ListaDupla();

		while (sc.hasNextInt()){
			n = sc.nextInt();
			if (n==-1) {
				break;
			}
			// AQUI VOU CONSTRUIR A LISTA COM OS ESCOLHIDOS PELO PUB.IN
			// NO EXERCICIO 1 POR EXEMPLO EU JÁ SAIA PRINTANDO CADA ID QUE ACHAVA
			lista.inserirFim(buscar(veiculos, n));
		}//fim do while com a lista pronta



        // segunda parte: agora vamos ler os comandos e chamar os metodos
    int qtdComandos = sc.nextInt(); //le a proxima palavra

    for (int c = 0; c < qtdComandos; c++) { //le cada comando
        String comando = sc.next();

        if (comando.charAt(0) == 'I') {
            // aqui já vimos que vai ser inserir
            if (comando.charAt(1) == 'I') { //II é inserir inicio
                lista.inserirInicio(buscar(veiculos, sc.nextInt()));
            } else if (comando.charAt(1) == 'F') { //IF inserir Fim
                lista.inserirFim(buscar(veiculos, sc.nextInt()));
            } else { //se nao for II ou IF, so pode ser i*
                int pos = sc.nextInt(); //ler a posicao que vai ser inserido
                lista.inserir(buscar(veiculos, sc.nextInt()), pos);
            }
        } else {
            // remocao: imprime (R) marca modelo
            Veiculo removido;
            if (comando.charAt(1) == 'I') {
                removido = lista.removerInicio();
            } else if (comando.charAt(1) == 'F') {
                removido = lista.removerFim();
            } else {
                removido = lista.remover(sc.nextInt());
            }
            //aqui no println ja vai pular a proxima linha, o que estava dando problema antes
            System.out.println("(R)" + removido.getMarca() + " " + removido.getModelo());
        }
    }

    lista.mostrar();
    }
}