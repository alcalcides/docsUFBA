/*
Implementação de lista encadeada simples 
Com head
*/

#include <stdlib.h>
#include <stdbool.h>

typedef struct cell Cell;

struct cell {
    int content;
    Cell *next;
};

//Recebe um valor, cria uma célula e, com sucesso,
//retorna um ponteiro para ela ou NULL no fracasso
Cell* newCell(int content);
//Recebe o ponteiro para uma célula e mostra seus valores armazenados
void dumpCell(Cell *cell);
//Recebe o ponteiro para uma célula e mostra seu conteúdo
void showCell(Cell *cell);
//Recebe o ponteiro para uma célula e a desaloca
//Retorna NULL
Cell* killCell(Cell *cell);
//Recebe o ponteiro para uma lista(head) e mostra tudo sobre ela
void dumpList(Cell *head);
//Recebe o ponteiro para uma lista(head) e mostra seu conteúdo
void showList(Cell *head);
//Recebe um valor e uma lista(head) e insere nova célula na lista
//Retorna o ponteiro para a célula criada ou NULL no fracasso
Cell* insert(int content, Cell *head);
//Recebe um valor e uma lista(head), 
//procura uma ocorrência do valor nela e
//Retorna o ponteiro para a célula anterior à achada
//ou NULL caso não haja o valor na lista ou ela esteja vazia
Cell* searchFor(int content, Cell *head);
//Recebe um valor a ser removido de uma lista
//Retorna o ponteiro para a lista
//ou NULL se a lista não exite, é vazia ou não possui o valor em suas células
Cell* delValue(int content, Cell *head);


Cell* newCell(int content){
    Cell *cell = (Cell*) malloc(1*sizeof(Cell));
    if(cell){
        cell->content = content;
        cell->next = NULL;
    }
    return cell;
}

void dumpCell(Cell *cell){
    printf("Rented in: %p\n", cell);
    printf("Content is: %d\n", cell->content);
    printf("Next is: %p\n", cell->next);
}

void showCell(Cell *cell){
    printf("%d\n", cell->content);
}

Cell* killCell(Cell *cell){
    free(cell);
    return NULL;
}

void dumpList(Cell *head){
    while(head){
        dumpCell(head);
        head = head->next;
    }
    
}

void showList(Cell *head){
    int i = 1;
    while(head->next){
        printf("Cell %d\t==>\t", i);
        showCell(head->next);
        head->next = head->next->next;
        ++i;
    }
}

Cell* insert(int content, Cell *head){
    Cell *freshman = newCell(content);
    if(freshman){
        freshman->next = head->next;
        head->next = freshman;
    }
    return freshman;
}

Cell* searchFor(int content, Cell *head){
    Cell *cursor = head;
    while(cursor->next && cursor->next->content != content){
        cursor = cursor->next;
    }
    if(cursor->next == NULL)
        cursor = NULL;
    return cursor;    
}

Cell* delValue(int content, Cell *head){
    if(head){
        Cell *mirror = searchFor(content, head);
        if(mirror){
            Cell *temp = mirror->next->next;
            killCell(mirror->next);
            mirror->next = temp;
        }
        else
            head = mirror;
    }
    return head;
}