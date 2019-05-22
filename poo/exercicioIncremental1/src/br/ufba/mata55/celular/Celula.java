package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;

public class Celula {

    private int x;
    private int y;
    private int tamanho;
    private boolean ativo;

    public Celula() {
        x = y = 100;
        tamanho = 30;
        ativo = false;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public boolean isAtivo() {
        return ativo;
    }

    public void setAtivo(boolean ativo) {
        this.ativo = ativo;
    }

    public void desenha(Graphics g) {
        this.setX(Controle.mouseX);
        this.setY(Controle.mouseY);
        g.setColor(Color.WHITE);
        g.fillOval(x - tamanho/2, y - tamanho/2, tamanho, tamanho);
    }
}
