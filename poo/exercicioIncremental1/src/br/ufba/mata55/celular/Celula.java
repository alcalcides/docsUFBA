package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;

public class Celula extends Entidade {

	private Poder[] poder = { new Poder1(), new Poder2(), new Poder3() };
	private int poderAtivo;

	public Celula() {
		setTamanho(3);
		setAtivo(true);
		poderAtivo = 1;
	}

	/**
	 * celula tem centro em (x,y) e raio = tamanho/2
	 */
	public void desenha(Graphics g) {
		if (isAtivo()) {
			setX(Controle.mouseX);
			setY(Controle.mouseY);
			g.setColor(Color.WHITE);
			g.fillOval(getX() - getTamanho() / 2, getY() - getTamanho() / 2, getTamanho(), getTamanho());
		}
	}

	public Poder[] getPoder() {
		return poder;
	}

	public void setPoder(Poder[] poder) {
		this.poder = poder;
	}

	public int getPoderAtivo() {
		return poderAtivo;
	}

	public void setPoderAtivo(int numPoder) {
		if (numPoder >= 1 && numPoder <= 3) {
			this.poderAtivo = numPoder;
		} else {
			throw new IllegalArgumentException("Poder deve ser 1, 2 ou 3");
		}
	}

}
