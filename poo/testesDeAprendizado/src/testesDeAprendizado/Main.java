package testesDeAprendizado;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String nome = in.next();

		System.out.println(nome.compareTo("alcides"));

		for (int i = nome.length()-1; i > nome.length()-4; i--) {
			System.out.println(nome.charAt(i));
		}
	}
}
