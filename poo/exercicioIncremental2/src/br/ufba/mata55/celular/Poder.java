package br.ufba.mata55.celular;

import java.util.Collection;

public interface Poder {
	public abstract void acionar(Celula celula, Collection<Entidade> vizinhos);
}
