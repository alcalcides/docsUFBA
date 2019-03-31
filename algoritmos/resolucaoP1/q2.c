#include <stdio.h>
#include <stdlib.h>

/*Esta função ordena o vetor v 
da maneira mais ilegível que eu conheço*/
int main(){
	int n = 10;
	int k = 9;
	int v[10] = {5, 4, 2, 1, 9, 8, 1, 4, 2, 6};
	int i, b[10], c[9];
	for (i = 0; i < k; i++)	c[i] = 0;
	for (i = 0; i < n; i++)	c[v[i] - 1]++;
	for (i = 1; i < k; i++) c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--){
		b[c[v[i] - 1] - 1] = v[i];
		c[v[i] - 1]--;
	}
				
	for(i = 0; i < n; i++){
		v[i] = b[i];
		printf("v[%d] = %d\n", i, v[i]);
	}

}