package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

public class Veneno extends Entidade {
	private Random gerador;

	public Random getGerador() {
		return gerador;
	}

	public void setGerador() {
		this.gerador = new Random();
	}

	public Veneno() {
		setGerador();
		setTamanho(gerador.nextInt(18) + 3);
		setX(gerador.nextInt(Painel.LARGURA - getTamanho() + 1) + getTamanho() / 2);
		setY(gerador.nextInt(Painel.ALTURA - getTamanho() + 1) + getTamanho() / 2);
		setAtivo(true);
	}

	/**
	 * veneno tem centro em (x,y)
	 */
	public void desenha(Graphics g) {
		if (isAtivo()) {
			g.setColor(Color.GREEN);
			g.fillRect(getX() - getTamanho() / 2, getY() - getTamanho() / 2, getTamanho(), getTamanho());
			g.setColor(Color.BLUE);
			g.fillOval(getX() - getTamanho() / 2, getY() - getTamanho() / 2, getTamanho(), getTamanho());
		}
	}

	/**
	 * calcula a distancia para a celula
	 */
	public int iteracaoComCelula(Celula celula) {
		double difX, difY;
		double dist, mediaDosTamanhos;
		int tamanhoParaDiminuir;
		difX = getX() - celula.getX();
		difY = getY() - celula.getY();
		difX = Math.pow(difX, 2);
		difY = Math.pow(difY, 2);
		dist = Math.sqrt(difX + difY);
		mediaDosTamanhos = (celula.getTamanho() + getTamanho()) / 2;

		if(dist < mediaDosTamanhos)
			setAtivo(false);
		
		tamanhoParaDiminuir = !isAtivo() ? getTamanho() : 0;

		return tamanhoParaDiminuir;
	}

}
