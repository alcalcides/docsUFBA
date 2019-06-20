/*
Implementação de fila
*/

#include"listaEncHead.h"

typedef struct fila_t{
    Cell *head;
    int qtd_nodes;
    Cell *first, *last;
}Fila;

/*Cria uma nova fila e configura os valores iniciais.
Retorna o ponteiro para a fila criada ou NULL no fracasso */
Fila* newVoidFile(){
    Fila* freshman = (Fila*) malloc(1*sizeof(Fila));
    if(freshman){
        freshman->head = newCell(-1);
        if(freshman->head){
            freshman->qtd_nodes = 0;
            freshman->first = freshman->head->next;
            freshman->last = freshman->head->next;
        }
        else {
            freshman = NULL;
            free(freshman);
        }  
    }
    return freshman;
}

/*Recebe o ponteiro para uma fila exibe o endereço alocado, 
seu tamanho e todos os seus elementos */
void showFila(Fila *fila){
    printf("Fila alocada em %p\n", fila);
    printf("Tamanho da fila: %d\n", fila->qtd_nodes);
    if(fila->qtd_nodes > 0)
        showList(fila->head);
}

/*Recebe o conteúdo e o ponteiro para a fila e enfileira. 
Retorna o ponteiro para o último elemento da fila ou NULL no fracasso */
Cell* enqueue(int content, Fila *fila){
    Cell *temp;
    if(temp = insertValueTail(content, fila->head), temp != NULL){
        fila->qtd_nodes++;
        fila->last = temp;
    }
    return temp;
}