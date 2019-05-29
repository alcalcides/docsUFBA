#include <stdio.h>
#include "listaEncHead.h"

int main(){
	Cell *head = newCell(-1);

	if(head && insert(5, head) && insert(6, head) && insert(10, head)){
		dumpList(head);
	}

	delValue(-1, head);
	dumpList(head);

	killCell(head->next->next->next);
	killCell(head->next->next);
	killCell(head->next);
	head = killCell(head);

	return 0;    
}