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

	public static final int LARGURA = 640;
	public static final int ALTURA = 480;

	private int x = 15;
	private int y = 15;

	public Painel() {
		addMouseListener(this);
		addMouseMotionListener(this);
	}

	public void atualiza() {
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);

		// desenha
		g.setColor(Color.GRAY);
		g.fillRect(x, y, 10, 10);
		
		g.setColor(Color.ORANGE);
		g.fillOval(Controle.mouseX - 5, Controle.mouseY - 5, 10, 10);
		
		// atualiza posição
		x++;
		y++;
	}

	@Override
	public void keyTyped(KeyEvent e) {
		char keyChar = e.getKeyChar();

		if (keyChar == 27) { // Esc
			System.exit(0);
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
