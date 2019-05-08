#include <stdio.h>
#include "listaEncadeadaSimples.h"

int main(){
	Elto *aluguel, *passagem;
	List *despesas;

	aluguel = newElto(350);
	displayElto(aluguel);
	passagem = newElto(50);
	displayElto(passagem);
	
	despesas = newList();
	
	insertEltoTopLista(despesas, passagem);
	insertElto(despesas, passagem, aluguel);
	displayList(despesas);
	removerTopo(despesas);
	displayList(despesas);



	
	despesas = delList(despesas);
	delElto(aluguel);
	delElto(passagem);

	return 0;    
}