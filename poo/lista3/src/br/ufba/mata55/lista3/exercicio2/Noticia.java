package br.ufba.mata55.lista3.exercicio2;

public class Noticia extends Conteudo{
	private String autor;
	private String data;
	
	public Noticia(String titulo, String corpo, String autor, String data) {
		super(titulo, corpo);
		this.autor = autor;
		this.data = data;
	}
	public String getAutor() {
		return autor;
	}
	public void setAutor(String autor) {
		this.autor = autor;
	}
	public String getData() {
		return data;
	}
	public void setData(String data) {
		this.data = data;
	}
	
}
