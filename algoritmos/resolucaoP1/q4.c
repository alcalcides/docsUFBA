#include <stdio.h>
#include <stdlib.h>

/*Esta função dá vários 
erros em tempo de execução*/
int main(){
	int i = 3, **p1, *p2;
	
	**p1 = 10;
	p1 = &p2;
	*p2 = 5;
	p2 = &i;
	(**p1)++;
}