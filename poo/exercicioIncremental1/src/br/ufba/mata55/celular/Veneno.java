package br.ufba.mata55.celular;

public class Veneno {
	private int x;
	private int y;
	private int tamanho;
	private Cor cor;
	private boolean ativo;

	/**
	 * 
	 */
	public Veneno() {
		super();
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



	public void setCor(Cor cor) {
		this.cor = cor;
	}



	public Cor getCor() {
		return cor;
	}



	public boolean isAtivo() {
		return ativo;
	}



	public void setAtivo(boolean ativo) {
		this.ativo = ativo;
	}
	
	public void desenha(Graphics g){

	}
}
