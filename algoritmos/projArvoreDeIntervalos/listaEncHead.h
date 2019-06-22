//Implementação de lista encadeada simples com head

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
}interval;

typedef struct node iTree;
struct node{
    interval v;
    int max;
    iTree *left, *right;
    int hight;
};

typedef struct cell Cell;
struct cell {
    iTree *r;
    Cell *next;
};


Cell* newCell(iTree *r);
void showContent(iTree *i);
void showCell(Cell *cell);
void dumpCell(Cell *cell);
Cell* killCell(Cell *cell);
void showList(Cell *head);
void dumpList(Cell *head);
Cell* searchFor(iTree *r, Cell *head);
int listSize(Cell *head);
Cell* lookAtPos(int pos, Cell *head);
int whatsPos(iTree *r, Cell *head);
Cell* lastCell(Cell *head);
Cell* insertCellPos(Cell *mirror, Cell *freshman);
Cell* insertValuePos(Cell *mirror, iTree *r);
Cell* insertValueTop(iTree *r, Cell *head);
Cell* insertValueTail(iTree *r, Cell *head);
Cell* insert(iTree *r, int pos, Cell *head);
Cell* delCell(Cell *mirror);
Cell* delValue(iTree *r, Cell *head);
Cell* emptyList(Cell *head);
Cell* killList(Cell *head);

//Recebe um ponteiro para uma árvore, cria uma célula e, com sucesso,
//retorna um ponteiro para ela ou NULL no fracasso
Cell* newCell(iTree *r){
    Cell *cell = (Cell*) malloc(1*sizeof(Cell));
    if(cell){
        cell->r = r;
        cell->next = NULL;
    }
    return cell;
}

//Recebe o ponteiro para um nó da árvore e mostra seu conteúdo
void showContent(iTree *r){
    printf("[%d, %d], max = (%d), hight: %d\n", r->v.a, r->v.b, r->max, r->hight);
}

//Recebe o ponteiro para uma célula e mostra seu conteúdo
void showCell(Cell* cell){
    showContent(cell->r);
}

//Recebe o ponteiro para uma célula e mostra seus valores armazenados
void dumpCell(Cell *cell){
    printf("Living in: %p\n", cell);
    printf("Hight: %d\n", cell->r->hight);
    printf("Content is: ");
    showContent(cell->r);
    printf("Left son lives in: %p\n", cell->r->left);
    printf("Right son lives in: %p\n", cell->r->right);
    printf("Next lives in: %p\n\n", cell->next);
}

//Recebe o ponteiro para uma célula e a desaloca
//Retorna NULL
Cell* killCell(Cell *cell){
    free(cell);
    return NULL;
}

//Recebe o ponteiro para uma lista(head) e mostra seu conteúdo
void showList(Cell *head){
    int i = 1;
    Cell *cursor = head;
    while(cursor->next){
        printf("Cell %d\t==>\t", i);
        showCell(cursor->next);
        cursor = cursor->next;
        i++;
    }
}

//Recebe o ponteiro para uma lista(head) e mostra tudo sobre ela
void dumpList(Cell *head){
    Cell *cursor = head;
    while(cursor){
        dumpCell(cursor);
        cursor = cursor->next;
    }
    
}

//Recebe um ponteiro para um nó da arvare e a lista(head),
//procura a ocorrência desse ponteiro na lista. Caso exista na fila, 
//retorna o ponteiro anterior a ele ou NULL no fracasso
Cell* searchFor(iTree *r, Cell *head){
    Cell *cursor = head;
    while(cursor->next && cursor->next->r != r)
        cursor = cursor->next;
    if(cursor->next == NULL)
        cursor = NULL;
    return cursor;    
}

//Recebe uma lista(head) e retorna quantos itens há nela
int listSize(Cell *head){
    int i;
    Cell *cursor = head;
    for (i = 0; cursor->next; i++){
        cursor = cursor->next;
    }
    return i;
}

//Recebe uma posição(pos) e o ponteiro para uma lista(head).
//Retorna o ponteiro para a célula que ocupa a posição pos na lista
//ou retorna NULL se não houver tal posição.
Cell* lookAtPos(int pos, Cell *head){
    Cell *cursor = head;
    for(int i = 0; i < pos; i++ )
        cursor = cursor->next;
    return cursor;
}

//Recebe o ponteiro para um nó da árvore e uma lista(head).
//Retorna a posição do nó nessa lista ou -1 se não contiver
int whatsPos(iTree *r, Cell *head){
    int i = 1;
    Cell *cursor = head;
    while(cursor->next && cursor->next->r != r){
        i++;
        cursor = cursor->next;
    }
    if(cursor->next == NULL) 
        i = -1;
    return i;
}

//Recebe uma lista(head) e retorna ponteiro para a última célula.
//Para lista vazia, retorna ponteiro para a cabeça
Cell* lastCell(Cell *head){
    Cell *cursor = head;
    while(cursor->next)
        cursor = cursor->next;
    return cursor;
}

//Recebe o ponteiro para a célula anterior à mudança e uma nova célula
//Retorna o ponteiro para a célula inserida
Cell* insertCellPos(Cell *mirror, Cell *freshman){
    freshman->next = mirror->next;
    mirror->next = freshman;
    return freshman;
}

//Recebe um ponteiro para a célula precedente(mirror) à posição
//onde se quer criar e inserir nova célula com ponteiro r de um nó.
//retorna o ponteiro para a célula inserida ou NULL caso haja fracasso
Cell* insertValuePos(Cell *mirror, iTree *r){
    Cell *freshman = newCell(r);
    if(freshman){
        insertCellPos(mirror, freshman);
    }
    return freshman;
}

//Recebe o ponteiro para um nó r da árvore e uma lista de nós (head).
//Insere nova célula no topo da lista com o valor passado.
//Retorna o ponteiro para a célula criada ou NULL no fracasso
Cell* insertValueTop(iTree *r, Cell *head){
    Cell *freshman = insertValuePos(head, r);
    return freshman;
}

//Recebe um ponteiro para um nó da árvore e uma lista de nós (head).
//Cria nova célula com o ponteiro passado e insere no final da lista.
//Retorna ponteiro para a a célula inserida ou NULL no fracasso.
Cell* insertValueTail(iTree *r, Cell *head){
    return insertValuePos(lastCell(head), r);
}

//Recebe um ponteiro (r) para um nó da árvore, 
//uma posição (pos) na lista e a lista (head) de nós.
//Cria nova célula para r na posição especificada.
//Retorna o ponteiro para a célula inserida ou NULL no fracasso.
Cell* insert(iTree *r, int pos, Cell *head){
    int i;
    Cell *cursor = head;
    if(pos>0){
        for(i = 0; i < pos-1; i++){
            cursor = cursor->next;
        }
        cursor = insertValuePos(cursor, r);
    }
    return cursor;
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

//Recebe o ponteiro r a ser removido da lista(head).
//Retorna o ponteiro para a célula anterior a célula removida
//ou NULL se a lista é vazia ou se não há ocorrência de r. 
Cell* delValue(iTree *r, Cell *head){
    Cell *mirror = searchFor(r, head);
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