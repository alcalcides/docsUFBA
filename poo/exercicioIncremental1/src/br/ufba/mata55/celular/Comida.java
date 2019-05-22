package br.ufba.mata55.celular;

import java.awt.Color;
import java.awt.Graphics;
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
        gerador = new Random();
        tamanho = gerador.nextInt(18) + 3;
        x = gerador.nextInt(Painel.LARGURA - tamanho + 1) + tamanho / 2;
        y = gerador.nextInt(Painel.ALTURA - tamanho + 1) + tamanho / 2;
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

    /**
     * comida tem centro em (x,y)
     */
    public void desenha(Graphics g) {
        if(isAtivo()){
            g.setColor(Color.GREEN);
            g.fillRect(x - tamanho / 2, y - tamanho / 2, tamanho, tamanho);
        }
    }

    /**
     * calcula a distancia para a celula
     */
    public int iteracaoComCelula(int xDaCelula, int yDaCelula, int tamanhoDaCelula){
        double difX, difY;
        double dist, mediaDosTamanhos;
        int tamanhoParaAcrescentar;
        difX = x - xDaCelula;
        difY = y - yDaCelula;
        difX = Math.pow(difX, 2);
        difY = Math.pow(difY, 2);
        dist = Math.sqrt(difX + difY);
        mediaDosTamanhos = (tamanhoDaCelula + tamanho)/2;
        if(dist < mediaDosTamanhos){
            this.setAtivo(false);
            tamanhoParaAcrescentar = tamanho;
        }
        else{
            tamanhoParaAcrescentar = 0;
        }
        return tamanhoParaAcrescentar;
    }
}
