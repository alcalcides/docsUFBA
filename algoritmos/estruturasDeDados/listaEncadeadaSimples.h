/*
Implementação de lista encadeada simples 
SEM head
*/

#include <stdlib.h>
#include <stdbool.h>

typedef struct elto Elto;
typedef struct list List;

struct elto {
    int content;
    Elto *next;
};


struct list {
    int numEltos;
    Elto *firstElto;
};

Elto* newElto(int content);
void displayElto(Elto *elto);
Elto* delElto(Elto *elto);
List* newList();
bool isEmptyList(List *lista);
bool insertEltoTopLista(List *lista, Elto *pioneiro);
bool insertElto(List *lista, Elto* anterior, Elto* calouro);
void displayList(List *lista);
bool esvaziarList(List *lista);
bool remover(List *lista, Elto *antAlvo);
bool removerTopo(List *lista);
List* delList (List *lista);
Elto* seek(List *lista, int pos);
Elto* lookFor(List *lista, int value);

/*
A função newElto recebe os valores que compõem um nó e
cria um nó com esses valores e retorna um ponteiro para o nó criado
*/
Elto* newElto(int content){
    Elto *node = (Elto*)malloc(1*sizeof(Elto));
    if(node){
        node->content = content;
        node->next = NULL;
    }
    return node;
}

/*
Exibe os campos de um elemento
Se o elemento não existir, exibe mensagem específica
*/
void displayElto(Elto *elto){
    if(elto){
        printf("Alocado em: %p\n", elto);
        printf("Conteudo: %d\n", elto->content);
        printf("Proximo elemento: %p\n\n", elto->next);
    }
    else{
        printf("Elemento nulo\n");
    }
}

/*
A função delElto recebe o ponteiro para um nó e o desaloca
Retorna o valor NULL a ser atribuído, facultativamente, ao ponteiro.
*/
Elto* delElto(Elto *elto){    
    free(elto);
    return NULL;
}

/*
A função newListVazia cria uma lista vazia e
retorna o ponteiro para a lista criada
*/
List* newList(){
    List *lista = (List*)malloc(1*sizeof(List));
    lista->numEltos = 0;
    lista->firstElto = NULL;
    return lista;
}
/*
verifica se a lista está vazia
*/
bool isEmptyList(List* lista){
    bool vazio;
    vazio = lista->numEltos == 0 ? true : false;
    return vazio;
}


/*
Recebe um ponteiro para uma lista vazia e um 
ponteiro para a primeira célula.
Retorna true para indicar que houve inserção.
*/
bool insertEltoTopLista(List *lista, Elto *pioneiro){
    bool inseriu = false;
    pioneiro->next = lista->firstElto;   
    lista->firstElto = pioneiro;
    lista->numEltos++;
    inseriu = true;
    return inseriu;
}

/*
Recebe um ponteiro para uma lista não vazia, um ponteiro para uma célula e 
um inteiro para a posição da célula anterior à célula a ser inserida.
Retorna true para indicar que houve inserção.
*/
bool insertElto(List *lista, Elto* anterior, Elto* calouro){
    bool inseriu = false;
    if(!isEmptyList(lista)){
        calouro->next = anterior->next;
        anterior->next = calouro;
        lista->numEltos++;
        inseriu = true;
    }
    return inseriu;
}

/*
Recebe um ponteiro para uma lista e 
navega por ela mostrando seus elementos
*/
void displayList(List *lista){
    int i;
    Elto *alvo = lista->firstElto;
    if(isEmptyList(lista)){
        printf("Lista %p vazia\n", lista);
    }
    else{
        printf("Lista tem %d elementos:\n", lista->numEltos);
        for(i = 0; i < lista->numEltos; i++){
            displayElto(alvo);
            alvo = alvo->next;
        }
    }
}

/*
Recebe um ponteiro para uma lista e 
exclui todos os seus elementos.
Retorna true se houver sucesso
*/
bool esvaziarList(List *lista){
    bool esvaziou = false;
    while(!isEmptyList(lista)){
        removerTopo(lista);
    }
    esvaziou = lista->numEltos == 0 ? true : false;
    return esvaziou;
}

/*
Recebe um ponteiro para uma lista com pelo menos dois elementos
e um ponteiro para o elemento anterior ao elemento alvo, 
remove o elemento alvo e retorna true se bem sucedido.
*/
bool remover(List *lista, Elto *antAlvo){
    bool removeu = false;
    if(lista->numEltos > 1){
        Elto *temp = antAlvo->next->next;
        printf("Guardando %p\n", temp);
        printf("Deletando %p\n", antAlvo->next);
        delElto(antAlvo->next);
        antAlvo->next = temp;
        lista->numEltos--;
        removeu = true;
    }
    return removeu;
}

/*
Recebe um ponteiro para uma lista e
remove o primeiro elemento e 
retorna true se bem sucedido.
*/
bool removerTopo(List *lista){
    bool removeu = false;
    if(!isEmptyList(lista)){
        Elto *temp = lista->firstElto->next;
        delElto(lista->firstElto);
        lista->firstElto = temp;
        lista->numEltos--;
        removeu = true;
    }
    return removeu;
}

/*
Esta função recebe um ponteiro para uma lista,
desaloca todos os seus elementos da primeira posição para a última
e, por fim, desaloca a lista e retorna NULL para, 
facultativamente, atribuir no escopo pai
*/
List* delList (List *lista){
    if(!isEmptyList(lista)){
        Elto *alvo;
        while(lista->numEltos > 0){
            alvo = lista->firstElto;
            lista->firstElto = alvo->next;
            lista->numEltos--;
            delElto(alvo);
        }    
    }
    free(lista);
    return NULL;
}

/*
Recebe um ponteiro para uma lista e um inteiro pos que significa uma posição
Retorna o ponteiro da célula que está na posição pos da lista
*/
Elto* seek(List *lista, int pos){
    Elto *alvo = lista->firstElto;
    int contador = 0;
    while(contador < pos){
        contador++;
        alvo = alvo->next;
    }
    return alvo;
}

/*
Recebe um ponteiro para uma lista e um valor
a ser procurado na lista. 
Retorna NULL caso não contenha um nó com o valor fornecido
ou o ponteiro para o nó anterior ao nó encontrado.
*/
Elto* lookFor(List *lista, int value){
    Elto *temp = lista->firstElto;
    if(!isEmptyList(lista)){
        while(temp->content != value && temp->next){
            temp = temp->next;
        }
        if(temp->content != value)
            temp = NULL;
    }
    else{
        temp = NULL;
    }
    return temp;
}