package br.ufba.mata55.celular;

import java.awt.Graphics;
import java.util.ArrayList;

public class Terreno {

    private int largura;
    private int altura;
    private Celula celula;
    private ArrayList<Comida> comidas = new ArrayList<Comida>();
    private ArrayList<Veneno> venenos = new ArrayList<Veneno>();

    public Terreno(){
        largura = Painel.LARGURA;
        altura = Painel.ALTURA;
        celula = new Celula();
    }

    public void addComida() {
        Comida comida = new Comida();
        comidas.add(comida);        
    }
    
    public void addVeneno() {
        Veneno veneno = new Veneno();
        venenos.add(veneno);        
    }
    
    public int getLargura() {
        return largura;
    }

    public void setLargura(int largura) {
        this.largura = largura;
    }

    public int getAltura() {
        return altura;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public Celula getCelula() {
        return celula;
    }

    public void setCelula(Celula celula) {
        this.celula = celula;
    }

    public ArrayList<Comida> getComidas() {
        return comidas;
    }

    public void setComidas(ArrayList<Comida> comidas) {
        this.comidas = comidas;
    }

    public ArrayList<Veneno> getVenenos() {
        return venenos;
    }

    public void setVenenos(ArrayList<Veneno> venenos) {
        this.venenos = venenos;
    }

    public void desenharVenenos(Graphics g) {
        for(int i = 0 ; i<this.venenos.size(); i++){
            venenos.get(i).desenha(g);
        }
    }

    public void desenharComidas(Graphics g) {
        for(int i = 0 ; i<this.comidas.size(); i++){
            comidas.get(i).desenha(g);
        }
    }

    public void desenha(Graphics g) {
        celula.desenha(g);
        desenharComidas(g);
        desenharVenenos(g);
    }

}
