package br.ufba.mata55.celular;

import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Random;

public class Terreno {
	private Celula celula;
	private ArrayList<Comida> comidas = new ArrayList<Comida>();
	private ArrayList<Veneno> venenos = new ArrayList<Veneno>();
	private ArrayList<Inimigo> inimigos = new ArrayList<Inimigo>();
	private Collection<Entidade> vizinhos = new ArrayList<Entidade>();
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
			for (int i = 0; i < getVenenos().size(); i++) {
				diminuicao = quantidadeVenenoDigerido(i);
				if (diminuicao >= 3) {
					getVenenos().remove(i);
					getCelula().setTamanho(getCelula().getTamanho() - diminuicao);
				}
			}
		}
		if (!getInimigos().isEmpty()) {
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
	
	public void removeVeneno(Veneno veneno) {
		venenos.remove(veneno);
	}

	public void addInimigo() {
		Inimigo inimigo = new Inimigo();
		inimigos.add(inimigo);
	}

	public void addVizinhos(Entidade vizinho) {
		vizinhos.add(vizinho);
	}

	public void removeVizinhos(Entidade vizinho) {
		vizinhos.remove(vizinho);
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

	public Collection<Entidade> getVizinhos() {
		return vizinhos;
	}

	public void setVizinhos(Collection<Entidade> vizinhos) {
		this.vizinhos = vizinhos;
	}

	public void acionarPoder() {
		cadastrarVizinhos(comidas, venenos, inimigos);
		
		System.out.println("qtd vizinhos: " + vizinhos.size());
		celula.getPoder()[celula.getPoderAtivo() - 1].acionar(celula, vizinhos);
		System.out.println("qtd vizinhos: " + vizinhos.size());
		
		switch (celula.getPoderAtivo()) {
			case 1:
				System.out.println("Implemente poder 1");
				break;
			case 2:
				System.out.println("Implemente poder 2");
				break;
			case 3:
				for(Entidade entidade : vizinhos) {
					if(venenos.contains(entidade)) {
						venenos.remove(entidade);
					}
				}
				celula.setTamanho(celula.getTamanho() - 3);
				break;
		}
		
		descadastrarVizinhos();

	}

	private void descadastrarVizinhos() {
			vizinhos.clear();
	}

	private void cadastrarVizinhos(ArrayList<Comida> comidas, ArrayList<Veneno> venenos, ArrayList<Inimigo> inimigos) {
		for (Comida comida : comidas) {
			if (comida.distanciaParaCelula(celula) <= (comida.mediaDosTamanhos(celula) + 50)) {
				vizinhos.add(comida);
				System.out.println("comida vizinha");
			}
		}
		for (Veneno veneno : venenos) {
			if (veneno.distanciaParaCelula(celula) < (veneno.mediaDosTamanhos(celula) + 50)) {
				vizinhos.add(veneno);
				System.out.println("veneno vizinho");
			}
		}
		for (Inimigo inimigo : inimigos) {
			if (inimigo.distanciaParaCelula(celula) <= (inimigo.mediaDosTamanhos(celula) + 50)) {
				vizinhos.add(inimigo);
				System.out.println("inimigo vizinho");
			}
		}
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
