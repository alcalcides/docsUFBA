package br.ufba.mata55.celular;

import java.util.Collection;

public class Poder3 implements Poder {

	@Override
	public void acionar(Celula celula, Collection<Entidade> vizinhos) {
		System.out.println("poder 3 em acao");
		
	}

}
