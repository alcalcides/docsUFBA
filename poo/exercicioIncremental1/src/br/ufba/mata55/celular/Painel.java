package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.event.MouseInputListener;

public class Painel extends JPanel implements KeyListener, MouseInputListener {

    private static final long serialVersionUID = 1L;
    public static final int LARGURA = 500;
    public static final int ALTURA = 500;

    private Terreno terreno = new Terreno();
    private int qtdNovasComidas;
    private int qtdNovosVenenos;
    private static final int ANO_NOVO = 100;
    private int contador;

    public Painel() {
        setBackground(Color.BLACK);
        addMouseListener(this);
        addMouseMotionListener(this);
        zerarContadores();
    }

    public void zerarContadores() {
        Random gerador = new Random();
        qtdNovasComidas = gerador.nextInt(5);
        qtdNovosVenenos = gerador.nextInt(5);
        contador = 0;
    }

    public void atualiza() {
        verificarItens();
    }

    public void verificarItens() {
        if (contador < ANO_NOVO) {
            contador++;
            verificarComilancas();
        } else {
            carregarNovosItens();
            zerarContadores();
        }
    }

    public void verificarComilancas() {
        verificarCrescimento();
        verificarEncolhimento();
    }

    public void verificarEncolhimento() {
        int diminuicao;
        if (!terreno.getVenenos().isEmpty()) {
            System.out.println("venenos: " + terreno.getVenenos().size());
            for (int i = 0; i < terreno.getVenenos().size(); i++) {
                diminuicao = quantidadeVenenoDigerido(i);
                if (diminuicao >= 3) {
                    terreno.getVenenos().remove(i);
                    terreno.getCelula().setTamanho(terreno.getCelula().getTamanho() - diminuicao);
                }
            }
        } else {
//            System.out.println("terreno SEM venenos");
        }
    }
    
    public void verificarCrescimento() {
        int aumento;
        if (!terreno.getComidas().isEmpty()) {
            System.out.println("comidas: " + terreno.getComidas().size());
            for (int i = 0; i < terreno.getComidas().size(); i++) {
                aumento = quantidadeComidaDigerida(i);
                if (aumento >= 3) {
                    terreno.getComidas().remove(i);
                    terreno.getCelula().setTamanho(terreno.getCelula().getTamanho() + aumento);
                }
            }
        } else {
//            System.out.println("terreno SEM comidas");
        }
    }

    public int quantidadeComidaDigerida(int i) {
        return terreno.getComidas().get(i).iteracaoComCelula(
                terreno.getCelula().getX(),
                terreno.getCelula().getY(),
                terreno.getCelula().getTamanho());
    }

    public int quantidadeVenenoDigerido(int i) {
        return terreno.getVenenos().get(i).iteracaoComCelula(
                terreno.getCelula().getX(),
                terreno.getCelula().getY(),
                terreno.getCelula().getTamanho());
    }

    public void carregarNovosItens() {
        for (int i = 0; i < qtdNovasComidas; i++) {
            terreno.addComida();
        }
        for (int i = 0; i < qtdNovosVenenos; i++) {
            terreno.addVeneno();
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        terreno.desenha(g);
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
