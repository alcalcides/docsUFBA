#include <stdio.h>
#include "fila.h"

int main(){
	Fila* sonhos;
	sonhos = newVoidFile();
	enqueue(2, sonhos);
	enqueue(30, sonhos);
	enqueue(454, sonhos);

	showFila(sonhos);
		
	return 0;    
}