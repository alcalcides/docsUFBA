package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;
import javax.swing.event.MouseInputListener;

public class Painel extends JPanel implements KeyListener, MouseInputListener {

	private static final long serialVersionUID = 1L;
	public static final int LARGURA = 500;
	public static final int ALTURA = 500;

	private Terreno terreno = new Terreno();

	public Painel() {
		setBackground(Color.BLACK);
		addMouseListener(this);
		addMouseMotionListener(this);
		terreno.zerarContadores();
	}

	public void atualiza() {
		terreno.verificarItens();
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		terreno.desenha(g);
	}

	@Override
	public void keyTyped(KeyEvent e) {
		char keyChar = e.getKeyChar();

		if (keyChar == 27) {
			System.exit(0);
		} else if (keyChar >= '1' && keyChar <= '3') {
			terreno.getCelula().setPoderAtivo(keyChar - '0');
		} else if (keyChar == ' ') {
			terreno.acionarPoder();
		}
	}

	@Override
	public void keyPressed(KeyEvent e) {
	}

	@Override
	public void keyReleased(KeyEvent e) {
	}

	@Override
	public void mouseClicked(MouseEvent e) {
	}

	@Override
	public void mousePressed(MouseEvent e) {
	}

	@Override
	public void mouseReleased(MouseEvent e) {
	}

	@Override
	public void mouseEntered(MouseEvent e) {
	}

	@Override
	public void mouseExited(MouseEvent e) {
	}

	@Override
	public void mouseDragged(MouseEvent e) {
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		Controle.mouseX = e.getX();
		Controle.mouseY = e.getY();
	}
}
