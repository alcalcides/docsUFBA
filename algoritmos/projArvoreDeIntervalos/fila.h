/*
Implementação de fila
*/

#include"listaEncHead.h"

typedef struct fila{
    Cell *head;
    int qtd_nodes;
}Fila;

Fila* newFile(){
    Fila* freshman = (Fila*) malloc(1*sizeof(Fila));
    if(freshman){
        interval x;
        x.a = x.b = 0;
        freshman->head = newCell(x);
    }
}

