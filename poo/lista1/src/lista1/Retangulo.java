package lista1;

public class Retangulo {
	private double largura;
	private double altura;
	
	public Retangulo(double largura, double altura) {
		this.largura = largura;
		this.altura = altura;
	}
	public Retangulo() {
		this.largura = 1;
		this.altura = 1;
	}
	
	public double getLargura() {
		return largura;
	}
	public void setLargura(double largura) {
		this.largura = largura;
	}
	public double getAltura() {
		return altura;
	}
	public void setAltura(double altura) {
		this.altura = altura;
	}
	
	public double calculaArea() {
		return this.altura*this.largura;
	}
	
	public double calculaPerimetro() {
		return 2*this.altura + 2*this.largura;
	}
//	public static void main(String[] args) {
//		Retangulo bege = new Retangulo();
//		System.out.println("Largura " + bege.largura);
//		System.out.println("Altura " + bege.altura);
//		System.out.println("Perimetro " + bege.calculaPerimetro());
//		System.out.println("Area " + bege.calculaArea());
//	}
}
