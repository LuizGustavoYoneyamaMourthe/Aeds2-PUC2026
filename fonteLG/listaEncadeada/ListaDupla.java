package listaEncadeada;

public void inserir inicio{
    CelulaDupla tmp = new CelulaDupla();
    tmp.ant = primeiro;
    tmp.prox = primeiro.prox;
    primeiro.prox = tmp;
    tmp.prox.ant=tmp; 
}

public class ListaDupla {
    
}
