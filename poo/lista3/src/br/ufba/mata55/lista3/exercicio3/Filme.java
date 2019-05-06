package br.ufba.mata55.lista3.exercicio3;

public class Filme {
	private String titulo;
	protected int preco;
	protected int prazo;
	
	public Filme(String titulo) {
		this.titulo = titulo;
		this.preco = 3;
		this.prazo = 2;
	}
	
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public int getPreco() {
		return preco;
	}
	public void setPreco(int preco) {
		this.preco = preco;
	}
	public int getPrazo() {
		return prazo;
	}
	public void setPrazo(int prazo) {
		this.prazo = prazo;
	}

	public String toString() {
		return titulo + ";" + preco + ";" + prazo;
	}
		
}
