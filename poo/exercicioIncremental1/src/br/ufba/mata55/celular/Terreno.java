package br.ufba.mata55.celular;

import java.util.ArrayList;

public class Terreno {
	private int largura;
	private int altura;
	private Celula cel;
	private ArrayList<Comida> comidas = new ArrayList<Comida>();
	private ArrayList<Veneno> venenos = new ArrayList<Veneno>();
	
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

	public Celula getCel() {
		return cel;
	}

	public void setCel(Celula cel) {
		this.cel = cel;
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

	public void desenha(Graphics g){

	}
}
