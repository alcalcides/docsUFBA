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
    Queue* queue = (Queue*) malloc(1*sizeof(Queue));
    if(queue){
        queue->head = newCell(NULL);
        queue->last = queue->head->next; //NULL
        queue->qtd_nodes = 0;  
    }
    return queue;
}

/*Recebe o ponteiro para uma fila e 
retorna 1 se estiver vazia ou 0 caso contrário */
int isEmptyQueue(Queue *queue){
    int empty;
    empty = (queue->qtd_nodes == 0) ? 1 : 0;
    return empty;
}

//Recebe uma fila e mostra suas configurações
void dumpQueue(Queue *queue){
    printf("Fila alocada em: %p\n", queue);
    printf("Tamanho da fila: %d\n", queue->qtd_nodes);
    printf("Head lives in: %p\n", queue->head);
    printf("Last point to: %p\n\n", queue->last);
}

/*Recebe o ponteiro para uma fila exibe o endereço alocado, 
seu tamanho e todos os seus elementos */
void showQueue(Queue *queue){
    printf("Fila alocada em %p\n", queue);
    printf("Tamanho da fila: %d\n", queue->qtd_nodes);
    if(!isEmptyQueue(queue)){
        showList(queue->head);
    }
}

/*Recebe o conteúdo e o ponteiro para a fila e enfileira. 
Retorna o ponteiro para o último elemento da fila ou NULL no fracasso */
Cell* enqueue(iTree *r, Queue *queue){
    Cell *temp = insertValueTail(r, queue->head);
    if(temp != NULL){
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
/*Recebe o ponteiro para uma fila e retorna seu elemento mais antigo.
Retorna NULL se a fila estiver vazia */
// Cell* dequeue(Queue *queue){
//     if(queue->qtd_nodes<1) return NULL;
//     Cell *alvo = queue->head->next;
//     Cell *temp = queue->head->next->next;
//     queue->head->next = alvo->next;
//     queue->qtd_nodes--;
//     return alvo;
// }

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
    queue->head = killList(queue->head);
    free(queue);
    return NULL;
}