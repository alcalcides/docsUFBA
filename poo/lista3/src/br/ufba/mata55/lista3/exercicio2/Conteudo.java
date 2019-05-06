package br.ufba.mata55.lista3.exercicio2;

public class Conteudo {
	private String titulo;
	private String corpo;
	
	public Conteudo(String titulo, String corpo) {
		super();
		this.titulo = titulo;
		this.corpo = corpo;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public String getCorpo() {
		return corpo;
	}
	public void setCorpo(String corpo) {
		this.corpo = corpo;
	}
}
