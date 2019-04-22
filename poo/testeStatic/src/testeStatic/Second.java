package testeStatic;

public class Second {
	public void latir() {
		System.out.println("au au");
	}
	static void some(int a, int b) {
		System.out.println(a+b);
	}
	public static void main(String[] args) {
		Second dog = new Second();
		dog.latir();
		Second.some(5, 8);
	}
}
