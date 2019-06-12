package br.ufba.mata55.celular;

public class Inimigo extends Veneno {
	private int passo;
	private Direcao direcao;
	private boolean sentidoPositivo;

	public Inimigo() {
		passo = getGerador().nextInt(8) + 1;
		direcao = (getGerador().nextBoolean()) ? Direcao.HORIZONTAL : Direcao.VERTICAL;
	}

	public void andar() {
		if (direcao == Direcao.HORIZONTAL && isSentidoPositivo()) {
			setX(getX() + passo);
			if (getX() >= (Painel.LARGURA - getTamanho() / 2)) {
				setSentidoPositivo(false);
			}
		}
		else if (direcao == Direcao.HORIZONTAL && !isSentidoPositivo()) {
			setX(getX() - passo);
			if (getX() <= getTamanho() / 2) {
				setSentidoPositivo(true);
			}
		}
		else if (direcao == Direcao.VERTICAL && isSentidoPositivo()) {
			setY(getY() + passo);
			if (getY() >= (Painel.ALTURA - getTamanho() / 2)) {
				setSentidoPositivo(false);
			}
		}
		else if (direcao == Direcao.VERTICAL && !isSentidoPositivo()) {
			setY(getY() - passo);
			if (getY() <= getTamanho() / 2) {
				setSentidoPositivo(true);
			}
		}
	}

	public int getPasso() {
		return passo;
	}

	public void setPasso(int passo) {
		this.passo = passo;
	}

	public Direcao getDirecao() {
		return direcao;
	}

	public void setDirecao(Direcao direcao) {
		this.direcao = direcao;
	}

	public boolean isSentidoPositivo() {
		return sentidoPositivo;
	}

	public void setSentidoPositivo(boolean sentidoPositivo) {
		this.sentidoPositivo = sentidoPositivo;
	}

}
