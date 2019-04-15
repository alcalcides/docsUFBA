package br.ufba.mata55.lista2.exercicio2;

import br.ufba.mata55.lista2.exercicio1.Aluno;

public class Operacoes {	
	static double media(Aluno[] aluno){
		double somatorio = 0;
		int num = 0, i;
		for (i = 0; i<aluno.length; i++){
			if(aluno[i].getNota() > 0){
				num++;
				somatorio += aluno[i].getNota();
			}
		}
				
		return somatorio/num;
	}
}
