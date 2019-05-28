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
//Recebe o ponteiro para uma célula e a desaloca
//Retorna NULL
Cell* killCell(Cell *cell);
//Recebe o ponteiro para o head de uma lista e mostra suas células
void showList(Cell *head);
//Recebe um valor e uma lista(head) e insere nova célula na lista
//Retorna o ponteiro para a célula criada ou NULL no fracasso
Cell* insert(int content, Cell* head);


Cell* newCell(int content){
    Cell *cell = (Cell*) malloc(1*sizeof(Cell));
    if(cell){
        cell->content = content;
        cell->next = NULL;
    }
    return cell;
}

Cell* killCell(Cell *cell){
    free(cell);
    return NULL;
}

void showList(Cell *head){
    int i = 1;
    while(head->next){
        printf("Cell %d\t=>\t%d\n", i, head->next->content);
        head->next = head->next;
        ++i;
    }
}

Cell* insert(int content, Cell* head){
    Cell* freshman = newCell(content);
    if(freshman){
        freshman->next = head->next;
        head->next = freshman;
    }
    return freshman;
}