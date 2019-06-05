package testesDeAprendizado;

public class Mam {
	public Mamifero vaca;
	
	public static void main(String[] args) {
		Mam mmm = new Mam();
		mmm.vaca = new Mamifero();
		mmm.vaca.nome = "vaquinha";
		System.out.println(mmm.vaca.nome);
		
	}
}
