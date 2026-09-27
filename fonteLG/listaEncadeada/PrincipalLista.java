import java.util.*;

class Celula {
	public int elemento; // Elemento inserido na celula.
	public Celula prox; // Aponta a celula prox.


	public Celula() {
		this(0);
	}

	public Celula(int elemento) {
      this.elemento = elemento;
      this.prox = null;
	}
}

class Lista {
	private Celula primeiro;
	private Celula ultimo;


	
	public Lista() {
		primeiro = new Celula();
		ultimo = primeiro;
	}

	public void inserirInicio() throws Exception{
		Celula tmp = new Celula();
		
		tmp.prox = primeiro.prox;
		tmp = primeiro.prox;
		if (primeiro==ultimo){
			ultimo=tmp;
		}
		tmp=null;
	}

	public void inserir(int x, int pos) throws Exception{
		int tamanho = tamanho();
		if (pos<0 || pos>tamanho) {
			throw new Execption ("Erro");
		} else if (pos==0){
			inserirInicio(x);
		} else if (pos==tamanho){
			inserirFim(x);
		} else {

			Celula i = new Celula();
			for (int j=0; j<pos; j++, i=i.prox){
				Celula tmp = new Celula(x);
				tmp.prox = i.prox;
				i.prox=tmp;
				tmp=i=null;
			}
		}
	}

	public int removerFim() throws Exception{
		if (primeiro==ultimo){
			throw Exception ("Erro");

		}
		int resp = ultimo.elemento;
		Celula i;
		for (i=primeiro;i.prox!=ultimo;i=i.prox);
		int resp = ultimo.elemento;
		ultimo=i;
		i=null;
		ultimo.prox=null;
		return resp;
	}

	public int remover(int pos){
		Celula i=primeiro;
		for (int j=0;j<pos;j++,i=i.prox ){
			Celula tmp = i.prox;
			int resp = tmp.elemento;
			i.prox =  tmp.prox;
			tmp = i = null;
			tmp.prox = null;

		}

	}


}














	

class PrincipalLista {
	public static void main(String[] args) {
		
        
	}
}
