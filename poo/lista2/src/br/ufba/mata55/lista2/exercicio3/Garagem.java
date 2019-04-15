package br.ufba.mata55.lista2.exercicio3;

import br.ufba.mata55.lista2.exercicio3.Veiculo;

public class Garagem {
	private Veiculo[] veiculos;

	public Garagem(Veiculo[] veiculos) {
		this.veiculos = veiculos;
	}

	public Veiculo[] getVeiculos() {
		return veiculos;
	}

	public void setVeiculos(Veiculo[] veiculos) {
		this.veiculos = veiculos;
	}

	public Veiculo buscar (String placa){
		int i;
		for (i = 0; i < veiculos.length; i++){
			if(veiculos[i].getPlaca().equals(placa)){
				break;
			}
		}
		if(i == veiculos.length) veiculos[i] = null;
		return veiculos[i];
	}
	public Veiculo buscar (int renavam){
		int i;
		for (i = 0; i < veiculos.length; i++){
			if(veiculos[i].getRenavam() == renavam){
				break;
			}
		}
		if(i == veiculos.length) veiculos[i] = null;
		return veiculos[i];
	}
	public Veiculo buscar (Pessoa condutor){
		int i;
		for (i = 0; i < veiculos.length; i++){
			if(veiculos[i].getCondutor().equals(condutor)){
				break;
			}
		}
		if(i == veiculos.length) veiculos[i] = null;
		return veiculos[i];
	}
}
