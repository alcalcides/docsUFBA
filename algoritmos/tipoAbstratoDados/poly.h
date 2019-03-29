typedef struct poly {
	int numPontos;
	Ponto* cadeiaNos;
} Poly;

/*Esta função recebe a quantidade de pontos 
numPontos>=3 que formam o polígono e o vetor de 
pontos cadeiaNos que guardam as coordenadas dos pontos.
Esta função devolve o endereço de memória polyTal
que aponta para a estrutura criada, alocada dinamicamente,
logo, para liberar a memória, use a 
função posterior liberaPoly */
Poly* criaPoly(int numPontos, Ponto* cadeiaNos){
	Poly* polyTal;
	polyTal = (Poly*) malloc(sizeof(Poly));
		if(polyTal == NULL) exit(1);

	polyTal->numPontos = numPontos;
	polyTal->cadeiaNos = cadeiaNos;
	return polyTal;
}

/*Esta função exibe os pontos do polígono polyTal*/
void exibaPoly(Poly* polyTal){
	printf("Pontos do poligono\n");
	int i;
	for(i = 0; i < polyTal->numPontos; i++){
		printf("Ponto %d\tx = %7f\ty=%7f\n", 
			i + 1, polyTal->cadeiaNos[i].x, polyTal->cadeiaNos[i].y);
	}
}

void dumpPoly(Poly* polyTal){
	printf("Endereco do Poly: %d\n", polyTal);
	printf("Num de pontos: %d\n", polyTal->numPontos );
	printf("Endereco do vetor de pontos: %d\n", polyTal->cadeiaNos);
	exibaPoly(polyTal);
}

void liberaPoly(Poly* polyTal){
	printf("Liberando cadeia de pontos %d\n", polyTal->cadeiaNos);
	liberaPontos(polyTal->cadeiaNos);
	printf("Liberando Poly %d\n", polyTal);
	free(polyTal);
}

/*Esta função calcula a distancia entre dois pontos*/
float distPontos(Ponto* p1, Ponto* p2){
	float dist;
	dist = sqrt(
		pow(p2->x - p1->x,2) 
		+ 
		pow(p2->y - p1->y,2));
	return dist;
}

/*Esta função recebe um polígono com numero de 
pontos maior que 2 e retorna seu perímetro*/
float perimetroPoly(Poly* polyTal){
	float per = 0;
	int i = polyTal->numPontos;
	if(i < 3){
		printf("Quantidade insuficiente de pontos\n");
		per = -1;
	}
	else{
		for(i = 0; i < polyTal->numPontos - 1; i++)
			per += distPontos(&polyTal->cadeiaNos[i], &polyTal->cadeiaNos[i+1]);
		per += distPontos(&polyTal->cadeiaNos[i], &polyTal->cadeiaNos[0]);
	}
	return per;
}