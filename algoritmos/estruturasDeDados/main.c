#include <stdio.h>
#include "listaEncHead.h"

int main(){
	Cell *head = newCell(-1);
	
	if(head)
		showList(head);
	
	if(insert(5, head))
		showList(head);
	if(insert(6, head))
		showList(head);

	killCell(head->next->next);
	killCell(head->next);
	head = killCell(head);

	return 0;    
}