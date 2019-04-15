package br.ufba.mata55.lista2.exercicio4;

public class Item {
	private String codigo;
	private String nome;
	private int preco;
	
	public Item(String codigo, String nome, int preco) {
		this.codigo = codigo;
		this.nome = nome;
		this.preco = preco;
	}
	public String getCodigo() {
		return codigo;
	}
	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getPreco() {
		return preco;
	}
	public void setPreco(int preco) {
		this.preco = preco;
	}
	
}
