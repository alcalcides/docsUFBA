/*
Implementação de lista encadeada simples 
SEM head
*/

#include <stdlib.h>

typedef struct elto Elto;
typedef struct list List;
List* newListVazia();

struct elto {
    int content;
    Elto* next;
};

struct list {
    int numEltos;
    Elto* firstElto;
};

Elto* newElto(int id, int numServ);
Elto* delElto(Elto* ant);


/*
A função newElto recebe os valores que compõem um nó e
cria um nó com esses valores e retorna um ponteiro para o nó criado
*/
Elto* newElto(int content){
    Elto* node = (Elto*)malloc(1*sizeof(Elto));
    if(node){
        node->content = content;
        node->next = NULL;
    }
    return node;
}

/*
A função delElto recebe um nó e exclui o nó logo à frente
e retorna o ponteiro para esse nó anterior ou, 
no caso de não haver nó à frente, ele exclui o próprio nó
e retorna NULL
*/
Elto* delElto(Elto* ant){
    if(ant->next == NULL){
        free(ant);
    }
    else{
        Elto* temp = ant->next->next;
        free(ant->next);
        ant->next = temp;
    }
    return ant;
}

/*
A função newListVazia cria uma lista vazia e
retorna o ponteiro para a lista criada
*/
List* newListVazia(){
    List* lista = (List*)malloc(1*sizeof(List));
    lista->numEltos = 0;
    lista->firstElto = NULL;
    return lista;
}

/*
A função insereEltoLista recebe ponteiro do 
elemento a ser inserido na lista, o ponteiro da lista
e a posição e retorna...
*/
