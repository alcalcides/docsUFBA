package testesDeAprendizado;

public class Main {

	public static <T> T soma (T a, T b){

		return a;
//		return a+b;
	}
	
	public static void main(String[] args) {
		Integer a, b;
		a = 5;
		b = 6;
		System.out.println(soma(a, b));
	}
}