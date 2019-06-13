package br.ufba.mata55.celular;

import java.util.ArrayList;
import java.util.Collection;

public class Poder3 implements Poder {

	@Override
	public void acionar(Celula celula, Collection<Entidade> vizinhos) {
		ArrayList<Entidade> alvo = new ArrayList<>();
		for (Entidade entidade : vizinhos) {
			String classe = entidade.getClass().getSimpleName();
			if (classe.equals("Veneno")) {
				alvo.add(entidade);
				entidade.setAtivo(false);
			}
		}
		vizinhos.clear();
		vizinhos.addAll(alvo);
		celula.setTamanho(celula.getTamanho() - 3);
	}

}
