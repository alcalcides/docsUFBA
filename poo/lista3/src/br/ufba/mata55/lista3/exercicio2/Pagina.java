package br.ufba.mata55.lista3.exercicio2;

public class Pagina extends Conteudo {
	private String endereco;

	public Pagina(String titulo, String corpo, String endereco) {
		super(titulo, corpo);
		this.endereco = endereco;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	
}
