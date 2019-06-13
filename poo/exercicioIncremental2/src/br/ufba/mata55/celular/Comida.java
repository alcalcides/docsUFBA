package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;

public class Comida extends Comestivel {
	/**
	 * comida tem centro em (x,y)
	 */
	public void desenha(Graphics g) {
		if (isAtivo()) {
			g.setColor(Color.GREEN);
			g.fillRect(getX() - getTamanho() / 2, getY() - getTamanho() / 2, getTamanho(), getTamanho());
		}
	}

}
