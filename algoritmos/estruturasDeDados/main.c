#include <stdio.h>
#include "fila.h"

int main(){
	Queue* sonhos;
	sonhos = newVoidQueue();
	enqueue(2, sonhos);
	enqueue(30, sonhos);
	enqueue(454, sonhos);
	enqueue(678, sonhos);
	

	showQueue(sonhos);	
	showCell(dequeue(sonhos));
	showCell(dequeue(sonhos));
	showQueue(sonhos);
	
	sonhos = killQueue(sonhos);
	
	return 0;    
}