package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;

public class Veneno extends Comestivel {
	/**
	 * veneno tem centro em (x,y)
	 */
	public void desenha(Graphics g) {
		if (this.isAtivo()) {
			g.setColor(Color.GREEN);
			g.fillRect(getX() - getTamanho() / 2, getY() - getTamanho() / 2, getTamanho(), getTamanho());
			g.setColor(Color.BLUE);
			g.fillOval(getX() - getTamanho() / 2, getY() - getTamanho() / 2, getTamanho(), getTamanho());
		}
	}

}
