package br.ufba.mata55.celular;

import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;

public class Terreno {
	private Celula celula;
	private ArrayList<Comida> comidas = new ArrayList<Comida>();
	private ArrayList<Veneno> venenos = new ArrayList<Veneno>();
	private ArrayList<Inimigo> inimigos = new ArrayList<Inimigo>();
	private int contador;
	private int qtdNovasComidas;
	private int qtdNovosVenenos;
	private int qtdNovosInimigos;
	private static final int ANO_NOVO = 100;

	public Terreno() {
		celula = new Celula();
	}

	public void zerarContadores() {
		Random gerador = new Random();
		qtdNovasComidas = gerador.nextInt(5);
		qtdNovosVenenos = gerador.nextInt(5);
		qtdNovosInimigos = gerador.nextInt(5);
		contador = 0;
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
		if (!getVenenos().isEmpty()) {
			System.out.println("venenos: " + getVenenos().size());
			for (int i = 0; i < getVenenos().size(); i++) {
				diminuicao = quantidadeVenenoDigerido(i);
				if (diminuicao >= 3) {
					getVenenos().remove(i);
					getCelula().setTamanho(getCelula().getTamanho() - diminuicao);
				}
			}
		}
		if (!getInimigos().isEmpty()) {
			System.out.println("inimigos: " + getInimigos().size());
			for (int i = 0; i < getInimigos().size(); i++) {
				diminuicao = quantidadeInimigoDigerido(i);
				if (diminuicao >= 3) {
					getInimigos().remove(i);
					getCelula().setTamanho(getCelula().getTamanho() - diminuicao);
				}
			}
		}
	}

	public void verificarCrescimento() {
		int aumento;
		if (!getComidas().isEmpty()) {
			System.out.println("comidas: " + getComidas().size());
			for (int i = 0; i < getComidas().size(); i++) {
				aumento = quantidadeComidaDigerida(i);
				if (aumento >= 3) {
					getComidas().remove(i);
					getCelula().setTamanho(getCelula().getTamanho() + aumento);
				}
			}
		}
	}

	public int quantidadeComidaDigerida(int i) {
		return getComidas().get(i).iteracaoComCelula(getCelula());
	}

	public int quantidadeVenenoDigerido(int i) {
		return getVenenos().get(i).iteracaoComCelula(getCelula());
	}

	public int quantidadeInimigoDigerido(int i) {
		return getInimigos().get(i).iteracaoComCelula(getCelula());
	}

	public void carregarNovosItens() {
		for (int i = 0; i < qtdNovasComidas; i++) {
			addComida();
		}
		for (int i = 0; i < qtdNovosVenenos; i++) {
			addVeneno();
		}
		for (int i = 0; i < qtdNovosInimigos; i++) {
			addInimigo();
		}
	}

	public void addComida() {
		Comida comida = new Comida();
		comidas.add(comida);
	}

	public void addVeneno() {
		Veneno veneno = new Veneno();
		venenos.add(veneno);
	}

	public void addInimigo() {
		Inimigo inimigo = new Inimigo();
		inimigos.add(inimigo);
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

	public ArrayList<Inimigo> getInimigos() {
		return inimigos;
	}

	public void setInimigos(ArrayList<Inimigo> inimigos) {
		this.inimigos = inimigos;
	}

	public void desenharVenenos(Graphics g) {
		for (int i = 0; i < venenos.size(); i++) {
			venenos.get(i).desenha(g);
		}
	}

	public void desenharInimigos(Graphics g) {
		for (int i = 0; i < inimigos.size(); i++) {
			inimigos.get(i).desenha(g);			
			inimigos.get(i).andar();			
		}
	}

	public void desenharComidas(Graphics g) {
		for (int i = 0; i < comidas.size(); i++) {
			comidas.get(i).desenha(g);
		}
	}

	public void desenha(Graphics g) {
		celula.desenha(g);
		desenharComidas(g);
		desenharVenenos(g);
		desenharInimigos(g);
	}

}
