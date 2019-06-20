/*
Implementação de lista encadeada simples 
Com head
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct cell Cell;

typedef struct {
    int a, b;
}interval;

struct cell {
    interval content;
    Cell *next;
};


Cell* newCell(interval content);
void dumpCell(Cell *cell);
void showCell(Cell *cell);
Cell* killCell(Cell *cell);
void dumpList(Cell *head);
void showList(Cell *head);
Cell* searchFor(interval content, Cell *head);
int listSize(Cell *head);
Cell* lookAtPos(interval pos, Cell *head);
int whatsPos(interval content, Cell *head);
Cell* lastCell(Cell *head);
Cell* insertCellPos(Cell *mirror, Cell *freshman);
Cell* insertValuePos(Cell *mirror, interval content);
Cell* insertValueTop(interval content, Cell *head);
Cell* insertValueTail(interval content, Cell *head);
Cell* insert(interval content, interval pos, Cell *head);
Cell* delCell(Cell *mirror);
Cell* delValue(interval content, Cell *head);
Cell* emptyList(Cell *head);
Cell* killList(Cell *head);

//Recebe um valor, cria uma célula e, com sucesso,
//retorna um ponteiro para ela ou NULL no fracasso
Cell* newCell(interval content){
    Cell *cell = (Cell*) malloc(1*sizeof(Cell));
    if(cell){
        cell->content = content;
        cell->next = NULL;
    }
    return cell;
}

//Recebe o ponteiro para uma célula e mostra seus valores armazenados
void dumpCell(Cell *cell){
    printf("Rented in: %p\n", cell);
    printf("Content is: [%d, %d]\n", cell->content.a, cell->content.b);
    printf("Next is: %p\n", cell->next);
}

//Recebe o ponteiro para uma célula e mostra seu conteúdo
void showCell(Cell *cell){
    printf("[%d, %d]\n", cell->content.a, cell->content.b);
}

//Recebe o ponteiro para uma célula e a desaloca
//Retorna NULL
Cell* killCell(Cell *cell){
    free(cell);
    return NULL;
}

//Recebe o ponteiro para uma lista(head) e mostra tudo sobre ela
void dumpList(Cell *head){
    while(head){
        dumpCell(head);
        head = head->next;
    }
    
}

//Recebe o ponteiro para uma lista(head) e mostra seu conteúdo
void showList(Cell *head){
    int i = 1;
    while(head->next){
        printf("Cell %d\t==>\t", i);
        showCell(head->next);
        head = head->next;
        i++;
    }
}

//Recebe um valor e uma lista(head),
//procura uma ocorrência do valor nela e
//retorna o ponteiro para a célula anterior à achada
//ou NULL caso não haja o valor na lista ou ela esteja vazia
Cell* searchFor(interval content, Cell *head){
    Cell *cursor = head;
    while(cursor->next && cursor->next->content != content){
        cursor = cursor->next;
    }
    if(cursor->next == NULL)
        cursor = NULL;
    return cursor;    
}

//Recebe uma lista(head) e retorna quantos itens há
int listSize(Cell *head){
    int i;
    for (i = 0; head->next; i++){
        head = head->next;
    }
    return i;
}

//Recebe o ponteiro para uma lista(head) e uma posição(pos).
//Retorna o ponteiro para a célula que ocupa posição pos na lista
//ou retorna NULL se não houver tal posição.
Cell* lookAtPos(int pos, Cell *head){
    for(int i = 0; i < pos; i++ )
        head = head->next;
    return head;
}

//Recebe um valor(content) e um lista(head) e retorna a posição
//da célula que contém o valor ou -1 se o valor não pertence à lista
int whatsPos(int content, Cell *head){
    int i = 1;
    while(head->next && head->next->content != content){
        i++;
        head = head->next;
    }
    if(head->next == NULL) 
        i = -1;
    return i;
}

//Recebe uma lista(head) e retorna ponteiro para a última célula.
//Para lista vazia, retorna ponteiro para a cabeça
Cell* lastCell(Cell *head){
    Cell *cursor = head;
    while(cursor->next){
        cursor = cursor->next;
    }
    return cursor;
}

//Recebe o ponteiro para a célula anterior à mudança e uma nova célula
//Retorna o ponteiro para a célula inserida
Cell* insertCellPos(Cell *mirror, Cell *freshman){
    freshman->next = mirror->next;
    mirror->next = freshman;
    return freshman;
}

//Recebe um valor e um ponteiro para a célula precedente(mirror).
//Cria uma célula para o valor, insere afrente de mirror e
//retorna o ponteiro a célula inserida ou NULL caso haja fracasso
Cell* insertValuePos(Cell *mirror, interval content){
    Cell *freshman = newCell(content);
    if(freshman){
        insertCellPos(mirror, freshman);
    }
    return freshman;
}

//Recebe um valor e uma lista(head),
//insere nova célula no topo da lista com o valor passado e
//retorna o ponteiro para a célula criada ou NULL no fracasso
Cell* insertValueTop(interval content, Cell *head){
    Cell *freshman = insertValuePos(head, content);
    return freshman;
}

//Recebe um valor e uma lista, insere nova célula no final da lista e
//retorna ponteiro para a a célula inserida ou NULL no fracasso.
Cell* insertValueTail(interval content, Cell *head){
    Cell *freshman = insertValuePos(lastCell(head), content);
    return freshman;
}

//Recebe um valor(content), uma posição(pos) e uma lista(head).
//Insere nova célula com o valor passado na posição especificada.
//Retorna NULL no fracasso ou um ponteiro para a célula inserida
Cell* insert(interval content, int pos, Cell *head){
    int i;
    if(pos>0){
        for(i = 0; i < pos-1; i++){
            head = head->next;
        }
        head = insertValuePos(head, content);
    }
    return head;
}

//Recebe o ponteiro para a célula anterior à que será excluída
//Retorna o ponteiro para a célula anterior à que foi removida 
//ou NULL no fracasso
Cell* delCell(Cell *mirror){
    Cell *temp = mirror->next->next;
    killCell(mirror->next);
    mirror->next = temp;
    return mirror;
}

//Recebe um valor a ser removido de uma lista(head)
//Retorna o ponteiro para a célula anterior a célula removida
//ou NULL se a lista é vazia ou não possui o valor em suas células
Cell* delValue(inter content, Cell *head){
    Cell *mirror = searchFor(content, head);
    if(mirror){
        delCell(mirror);
    }
    return mirror;
}

//Recebe uma lista e a esvazia. Retorna ponteiro para a lista vazia
Cell* emptyList(Cell *head){
    while(head->next){
        delCell(head);
    }
    return head;
}

//Recebe uma lista(head), desaloca todos as células e o head. 
//Retorna sempre NULL
Cell* killList(Cell *head){
    emptyList(head);
    killCell(head);
    return NULL;
}