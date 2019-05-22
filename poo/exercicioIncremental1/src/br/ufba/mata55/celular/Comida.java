package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;

public class Comida {
    private Random gerador;
    private int x;
    private int y;
    private int tamanho;
    private boolean ativo;

    /**
     *
     */
    public Comida() {
        gerador  = new Random();
        tamanho = gerador.nextInt(98)+3;
        x = gerador.nextInt(Painel.LARGURA - tamanho + 1) + tamanho/2;
        y = gerador.nextInt(Painel.ALTURA - tamanho + 1) + tamanho/2;        
        ativo = true;
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
        g.setColor(Color.GREEN);
        g.fillRect(x - tamanho/2, y - tamanho/2, tamanho, tamanho);
    }

}
