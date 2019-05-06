package br.ufba.mata55.lista3.exercicio3;

public class FilmeInfantil extends Filme{
	public FilmeInfantil(String titulo) {
		super(titulo);
	}
	@Override
	public int getPreco() {
		return 4;
	}
	@Override
	public int getPrazo() {
		return 4;
	}
}
