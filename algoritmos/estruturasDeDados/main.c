#include <stdio.h>
#include "listaEncHead.h"

int main(){
	Cell *head = newCell(-1);

	if(head && insertValueTop(5, head) && insertValueTop(6, head) && insertValueTop(10, head)){
		showList(head);
	}

	printf("\n");
	insert(100, 1, head);
	showList(head);
	
	printf("%d\n", whatsPos(-1, head));
	

	head = killCell(head);
		
	return 0;    
}