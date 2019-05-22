package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;

public class Celula {

    private int x;
    private int y;
    private int tamanho;
    private boolean ativo;

    public Celula() {
//        this.setX(0);
//        this.setY(0);
        this.setTamanho(3);
        this.setAtivo(true);
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
        if(this.tamanho < 3){
            setAtivo(false);
        }
    }

    public boolean isAtivo() {
        return ativo;
    }

    public void setAtivo(boolean ativo) {
        this.ativo = ativo;
    }

    /**
     * celula tem centro em (x,y) e raio = tamanho/2
     */
    public void desenha(Graphics g) {
        if(isAtivo()){
            this.setX(Controle.mouseX);
            this.setY(Controle.mouseY);
            g.setColor(Color.WHITE);
            g.fillOval(x - tamanho / 2, y - tamanho / 2, tamanho, tamanho);
        }
    }
}
