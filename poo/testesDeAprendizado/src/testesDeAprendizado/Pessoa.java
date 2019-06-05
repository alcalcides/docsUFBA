package testesDeAprendizado;

class Pessoa extends Mamifero {
	private String nome = "pessoa";
	public static int idade = 10;
	
	public Pessoa(){
		System.out.println("Pessoa");
	}
	
	public void cumprimenta() {
		System.out.println("Oi, eu sou " + nome);
	}
	
}
