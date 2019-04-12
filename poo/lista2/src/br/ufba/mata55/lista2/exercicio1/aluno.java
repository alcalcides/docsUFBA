package br.ufba.mata55.lista2.exercicio1;

public class Aluno {
	private final String nome;
	private double nota;
	
	public Aluno(String nome) {
		this.nome = nome;
	}

	public Aluno(String nome, double nota) {
		this.nome = nome;
		this.setNota(nota);
	}


	public String getNome() {
		return nome;
	}
//	public void setNome(String nome) {
//		this.nome = nome;
//	}
	public double getNota() {
		return nota;
	}
	public void setNota(double nota) {
		if (nota >= 0.0 && nota <= 10.0)
			this.nota = nota;
		else 
			System.out.println("Nota invalida");
	}
	
	public static void main(String[] args) {
		Aluno std1 = new Aluno("Alcides", 7);
		System.out.println(std1.nome);
		System.out.println(std1.nota);
		Aluno std2 = new Aluno("Cido");
		System.out.println(std2.nome);
		System.out.println(std2.nota);
		
	}

}
