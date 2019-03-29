typedef struct ponto{
	float x;
	float y;
} Ponto;

/*Esta função cria um vetor de Pontos 
com tamanho num(entrada), num >= 1,
e devolve o ponteiro para a estrutura criada.
O vetor é alocado dinamicamente, logo deve 
ser liberado pela função posterior liberaPonto */
Ponto* criaPontos(int num){
	printf("funcao criaPontos\n");
	int i;
	Ponto* ptos = (Ponto*)malloc(num*sizeof(Ponto));
		if(ptos == NULL) exit(1);

	for (i = 0; i < num; i++){
		printf("ponto %d = ", i+1);
		scanf("%f %f", &ptos[i].x, &ptos[i].y);
	}
	return ptos;
}

void liberaPontos(Ponto *ptos){
	printf("Liberando %d\n", ptos);
	free(ptos);
}

void exibePonto(Ponto* pto){
	printf("Valores do ponto\n");
	printf("%d\t%d\n", pto->x, pto->y);
}