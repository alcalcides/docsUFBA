package br.ufba.mata55.lista2.exercicio3;

public class Veiculo {
	private Pessoa condutor;
	private String placa;
	private int renavam;
	
	public String getPlaca() {
		return placa;
	}
	public void setPlaca(String placa) {
		this.placa = placa;
	}
	public int getRenavam() {
		return renavam;
	}
	public void setRenavam(int renavam) {
		this.renavam = renavam;
	}
	public Pessoa getCondutor() {
		return condutor;
	}
	public void setCondutor(Pessoa condutor) {
		this.condutor = condutor;
	}
}
