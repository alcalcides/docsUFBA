package lista1;

public class ListaInt {
	private int[] valores;
	private int capacidade;
	private int tam;
	private boolean lotado;
	
	public ListaInt (int capacidade) {
		setCapacidade(capacidade);
		setTam(0);
		setValores(capacidade);
		if(getTam()<getCapacidade())
			setLotado(false);
		else
			setLotado(true);
	}

	public void setValores(int capacidade){
		this.valores = new int[capacidade];
	}
	
	public int[] getValores(){
		return valores;
	}

	public boolean insiraElemento(int valor){
		boolean inserido = false;
		if(!isLotado()){
			valores[getTam()] = valor;
			setTam(getTam()+1);
			if(getTam() == getCapacidade()) 
				setLotado(true);
			inserido = true;
		}
		else{
			System.out.println("Sem espaco para inserir");
		}
		return inserido;
	}

	public int obtemElemento(int index){
		int q;
		if (index <= getCapacidade() - 1 && index >= 0) q = valores[index];
		else q = -1;
		return q;
	}
	
	public void listeValores(){
		for (int i = 0; i < getCapacidade(); i++) {
			System.out.println("[" + i + "] = " + Integer.toString(obtemElemento(i)));
		}
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
	
	public int obtemTamanho(){
		return getTam();
	}

	public boolean isLotado() {
		return lotado;
	}

	public void setLotado(boolean estourado) {
		this.lotado = estourado;
	}

//		public static void main(String[] args) {
//		ListaInt lll = new ListaInt(3);
//		System.out.println("Capacidade: " + lll.getCapacidade());
//		System.out.println("Tamanho: " + lll.obtemTamanho());
//		lll.listeValores();
//		lll.insiraElemento(2);
//		System.out.println("Tamanho: " + lll.obtemTamanho());
//		lll.listeValores();
//		lll.insiraElemento(4);
//		System.out.println("Tamanho: " + lll.obtemTamanho());
//		lll.listeValores();
//		lll.insiraElemento(6);
//		System.out.println("Tamanho: " + lll.obtemTamanho());
//		lll.listeValores();
//		lll.insiraElemento(8);
//		System.out.println("Tamanho: " + lll.obtemTamanho());
//		lll.listeValores();
//		System.out.println(Integer.toString(lll.obtemElemento(-1)));
//	}
}
