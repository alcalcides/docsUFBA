package br.ufba.mata55.lista2.exercicio1;

public class aluno {
	private String nome;
	private double nota;
	
	public aluno(String nome) {
		super();
		this.nome = nome;
	}

	public aluno(String nome, double nota) {
		super();
		this.nome = nome;
		this.nota = nota;
	}


	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public double getNota() {
		return nota;
	}
	public void setNota(double nota) {
		this.nota = nota;
	}
	

}
