package lista1;

public class ListaInt {
	private int valores[];
	private int capacidade;
	private int tam;
	private boolean estourou;
	
	public int[] getValores() {
		return valores;
	}


	public void setValores(int[] valores) {
		this.valores = valores;
	}


	public int getCapacidade() {
		return capacidade;
	}


	public void setCapacidade(int capacidade) {
		this.capacidade = capacidade;
	}


	public int getTam() {
		return tam;
	}


	public void setTam(int tam) {
		this.tam = tam;
	}


	public boolean isEstourou() {
		return estourou;
	}


	public void setEstourou(boolean estourou) {
		this.estourou = estourou;
	}
	
	public ListaInt (int capacidade) {
		setCapacidade(capacidade);
		setTam(0);
		if(this.tam <= capacidade) { //Daqui
			this.estourou = true;
		}
		else { 
			this.estourou = false;
		}
	}
	
	
	public static void main(String[] args) {
		ListaInt l = new ListaInt(2);
		System.out.println("Tamanho do vetor criado: " + l.valores.length);
	}
}
