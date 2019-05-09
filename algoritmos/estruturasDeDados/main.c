#include <stdio.h>
#include "listaEncadeadaSimples.h"

int main(){
	Elto *aluguel, *passagem, *alimentacao;
	List *despesas;

	aluguel = newElto(350);
	passagem = newElto(50);
	alimentacao = newElto(38);

	
	despesas = newList();
	
	insertEltoTopLista(despesas, passagem);
	insertElto(despesas, passagem, aluguel);
	insertElto(despesas, aluguel, alimentacao);
	displayList(despesas);
	esvaziarList(despesas);
	displayList(despesas);
		
	displayElto(lookFor(despesas, 50));

	despesas = delList(despesas);
	delElto(aluguel);
	delElto(passagem);

	return 0;    
}