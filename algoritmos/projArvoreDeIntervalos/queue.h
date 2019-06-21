//Implementação de fila


#include "listaEncHead.h"

typedef struct queue_t{
    Cell *head;
    int qtd_nodes;
    Cell *last;
}Queue;

/*Cria uma nova fila e configura os valores iniciais.
Retorna o ponteiro para a fila criada ou NULL no fracasso */
Queue* newVoidQueue(){
    Queue* freshman = (Queue*) malloc(1*sizeof(Queue));
    if(freshman){
        freshman->head = newCell(NULL);
        if(freshman->head){
            freshman->qtd_nodes = 0;
            freshman->last = NULL;
        }
        else {
            free(freshman);
            freshman = NULL;
        }  
    }
    return freshman;
}

/*Recebe o ponteiro para uma fila exibe o endereço alocado, 
seu tamanho e todos os seus elementos */
void showQueue(Queue *queue){
    printf("Fila alocada em %p\n", queue);
    printf("Tamanho da fila: %d\n", queue->qtd_nodes);
    if(queue->qtd_nodes > 0)
        showList(queue->head);
}

/*Recebe o conteúdo e o ponteiro para a fila e enfileira. 
Retorna o ponteiro para o último elemento da fila ou NULL no fracasso */
Cell* enqueue(iTree *r, Queue *queue){
    Cell *temp;
    if(temp = insertValueTail(r, queue->head), temp != NULL){
        queue->qtd_nodes++;
        queue->last = temp;
    }
    return temp;
}

/*Recebe o ponteiro para uma fila e retorna seu primeiro elemento
ou NULL casa a fila esteja vazia */
Cell* getFirstElto(Queue *queue){
    return queue->head->next;
}

/*Recebe o ponteiro para uma fila e 
ou 1 se estiver vazia ou 0 caso contrário */
int isEmptyQueue(Queue *queue){
    int empty;
    empty = (queue->qtd_nodes == 0) ? 1 : 0;
    return empty;
}


/*Recebe o ponteiro para uma fila e retorna seu elemento mais antigo.
Retorna NULL se a fila estiver vazia */
iTree* dequeue(Queue *queue){
    Cell* one = NULL;
    if(!isEmptyQueue(queue)){
        queue->qtd_nodes--;
        one = queue->head->next;
        delCell(queue->head);
    }
    return one->r;    
}

/*Recebe ponteiro para uma fila e a esvazia
Retorna o ponteiro para a lista já esvaziada */
Queue* emptyQueue(Queue *queue){
    while (!isEmptyQueue(queue))
        dequeue(queue);
    return queue;    
}

/*Recebe o ponteiro para uma fila, esvazia e desaloca.
Retorna NULL a ser atribuído no escopo do cliente */
Queue* killQueue(Queue *queue){
    emptyList(queue->head);
    free(queue);
}