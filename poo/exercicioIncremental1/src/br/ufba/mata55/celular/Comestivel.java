package br.ufba.mata55.celular;

import java.util.Random;

public abstract class Comestivel extends Entidade {
	private Random gerador;

	public Random getGerador() {
		return gerador;
	}

	public void setGerador() {
		this.gerador = new Random();
	}

	public Comestivel() {
		setGerador();
		setTamanho(gerador.nextInt(18) + 3);
		setX(gerador.nextInt(Painel.LARGURA - getTamanho() + 1) + getTamanho() / 2);
		setY(gerador.nextInt(Painel.ALTURA - getTamanho() + 1) + getTamanho() / 2);
		setAtivo(true);
	}

	/**
	 * calcula a distancia para a celula
	 */
	public int iteracaoComCelula(Celula celula) {
		int tamanhoDoPrato;
		double dist;
		dist = distanciaParaCelula(celula);
		double mediaDosTamanhos = mediaDosTamanhos(celula);

		if (dist < mediaDosTamanhos)
			setAtivo(false);

		tamanhoDoPrato = !isAtivo() ? getTamanho() : 0;

		return tamanhoDoPrato;
	}

	public double mediaDosTamanhos(Celula celula) {
		double mediaDosTamanhos;

		mediaDosTamanhos = (celula.getTamanho() + getTamanho()) / 2;

		return mediaDosTamanhos;
	}

	public double distanciaParaCelula(Celula celula) {
		double dist;
		double difX, difY;
		difX = getX() - celula.getX();
		difY = getY() - celula.getY();
		difX = Math.pow(difX, 2);
		difY = Math.pow(difY, 2);
		dist = Math.sqrt(difX + difY);
		return dist;
	}
}
