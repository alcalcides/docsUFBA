#include <stdio.h>
#include "listaEncadeadaSimples.h"

int main(){
	Elto *aluguel, *passagem, *alimentacao;
	List *despesas;

	aluguel = newElto(350);
	passagem = newElto(50);
	alimentacao = newElto(38);

	
	despesas = newList();
	insertEltoTopList(despesas, passagem);
	insertElto(despesas, passagem, aluguel);
	insertElto(despesas, aluguel, alimentacao);
	if(belong(despesas, 38))
		displayList(despesas);



	printf("%p\n", despesas->firstElto);
	despesas = delList(despesas);
	printf("%p\n", despesas);
	printf("%p\n", aluguel->next);
	
	//delElto(aluguel);
	//delElto(passagem);
	//delElto(alimentacao);
	return 0;    
}