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