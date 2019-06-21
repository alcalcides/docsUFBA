/*
Implementação de fila
*/

#include"listaEncHead.h"

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
        freshman->head = newCell(-1);
        if(freshman->head){
            freshman->qtd_nodes = 0;
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
void showQueue(Queue *queue){
    printf("Fila alocada em %p\n", queue);
    printf("Tamanho da fila: %d\n", queue->qtd_nodes);
    if(queue->qtd_nodes > 0)
        showList(queue->head);
}

/*Recebe o conteúdo e o ponteiro para a fila e enfileira. 
Retorna o ponteiro para o último elemento da fila ou NULL no fracasso */
Cell* enqueue(int content, Queue *queue){
    Cell *temp;
    if(temp = insertValueTail(content, queue->head), temp != NULL){
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
retorna 0 se não há elementos na fila ou 
1 se estiver vazia */
int isEmptyQueue(Queue *queue){
    int empty;
    empty = (queue->qtd_nodes == 0) ? 1 : 0;
}


/*Recebe o ponteiro para uma fila e retorna seu elemento mais antigo.
Retorna NULL se a fila estiver vazia */
Cell* dequeue(Queue *queue){
    if(queue->qtd_nodes > 0){
        queue->qtd_nodes--;
        Cell *alvo = lookAtPos(1, queue->head);
        queue->head->next = alvo->next;
        return alvo;
    }
    else{
        return NULL;
    }
    
}

/*Recebe ponteiro para uma fila e a esvazia
Retorna o ponteiro para a lista já esvaziada */
Queue* emptyQueue(Queue *queue){
    while (queue->qtd_nodes > 0)
        dequeue(queue);
    return queue;    
}

/*Recebe o ponteiro para uma fila, esvazia e desaloca.
Retorna NULL a ser atribuído no escopo do cliente */
Queue* killQueue(Queue *queue){
    killList(queue->head);
    free(queue);
}