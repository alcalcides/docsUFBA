#include <stdio.h>
#include "listaEncadeadaSimples.h"

int main(){
    List* idades;
    idades = newListVazia();
    printf("lista %p\n", idades);
    printf("lista.numEltos %d\n", idades->numEltos );
    printf("lista.firstElto %p\n", idades->firstElto);

    return 0;    
}