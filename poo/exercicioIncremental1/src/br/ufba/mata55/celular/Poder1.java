package br.ufba.mata55.celular;

import java.util.Collection;

public class Poder1 implements Poder {

	@Override
	public void acionar(Celula celula, Collection<Entidade> vizinhos) {
		System.out.println("poder 1 em acao");
	}

}
