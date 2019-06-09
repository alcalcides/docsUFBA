package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;

public class Celula extends Entidade {

	public Celula() {
		setTamanho(3);
		setAtivo(true);
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
}
