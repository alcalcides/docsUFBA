package br.ufba.mata55.celular;

import java.util.ArrayList;
import java.util.Collection;

public class Poder3 implements Poder {

	@Override
	public void acionar(Celula celula, Collection<Entidade> vizinhos) {
		System.out.println("poder 3");
		ArrayList<Entidade> alvo = new ArrayList<>();
		for (Entidade entidade : vizinhos) {
			String classe = entidade.getClass().getSimpleName();
			System.out.println(classe);
			if(classe.equals("Veneno")) {
				System.out.println("Capturou");
				alvo.add(entidade);
			}
		}
		vizinhos.clear();
		vizinhos.addAll(alvo);
	}

}
