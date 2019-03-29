#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
#include "poly.h"

int main(int argc, char const *argv[]){
	int numPontos;
	printf("Quantos pontos? ");
	scanf("%d", &numPontos);
	
	Ponto* cadeiaDePontos;
	cadeiaDePontos = criaPontos(numPontos);
	printf("Endereco da cadeia de pontos: %d\n", cadeiaDePontos);
	
	Poly* poligono;
	poligono = criaPoly(numPontos, cadeiaDePontos);
	
	dumpPoly(poligono);
	printf("Perimetro = %f\n", perimetroPoly(poligono));

	liberaPoly(poligono);
	return 0;
}