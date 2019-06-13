package br.ufba.mata55.celular;

import java.util.Collection;

public class Poder2 implements Poder {

	@Override
	public void acionar(Celula celula, Collection<Entidade> vizinhos) {
		for(Entidade entidade : vizinhos) {
			entidade.setTamanho(entidade.getTamanho() + 3);
		}
		celula.setTamanho(celula.getTamanho() - 3);
	}

}
