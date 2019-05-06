package br.ufba.mata55.lista3.exercicio3;

public class Filme {
	private String titulo; 
	
	public Filme(String titulo) {
		this.titulo = titulo;
	}
	
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public int getPreco() {
		return 3;
	}
	public int getPrazo() {
		return 2;
	}
	@Override
	public String toString() {
		return titulo + ";" + getPreco() + ";" + getPrazo();
	}
		
}
