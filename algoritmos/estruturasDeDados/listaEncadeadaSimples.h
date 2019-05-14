/*
Implementação de lista encadeada simples 
SEM head
*/

#include <stdlib.h>
#include <stdbool.h>

typedef struct elto Elto;
typedef struct list List;
//typedef struct content Content;

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
bool insertEltoTopList(List *lista, Elto *pioneiro);
bool insertElto(List *lista, Elto* anterior, Elto* calouro);
void displayList(List *lista);
bool clearList(List *lista);
bool delEltoList(List *lista, Elto *antAlvo);
bool delTop(List *lista);
bool delValue(List *lista, int value);
List* delList (List *lista);
Elto* seek(List *lista, unsigned int pos);
Elto* lookFor(List *lista, int value);
Elto* lookForAnt(List *lista, int value);
bool belong(List* lista, int value);

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
bool insertEltoTopList(List *lista, Elto *pioneiro){
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
bool clearList(List *lista){
    bool esvaziou = false;
    while(!isEmptyList(lista)){
        delTop(lista);
    }
    esvaziou = lista->numEltos == 0 ? true : false;
    return esvaziou;
}

/*
Recebe um ponteiro para uma lista com pelo menos dois elementos
e um ponteiro para o elemento anterior ao elemento alvo, 
remove o elemento alvo e retorna true se bem sucedido.
*/
bool delEltoList(List *lista, Elto *antAlvo){
    bool removeu = false;
    if(lista->numEltos > 1){
        Elto *temp = antAlvo->next->next;
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
bool delTop(List *lista){
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
Recebe um ponteiro para uma lista e 
um valor a ser removido dela.
Retorna true se houve a remoção ou
false caso não haja item com conteúdo igual a value
*/
bool delValue(List *lista, int value){
    bool removeu = false;
    Elto* antAlvo;
    if(!isEmptyList(lista)){
        if(lista->firstElto->content == value){
            removeu = delTop(lista);
        }
        else{
            antAlvo = lookForAnt(lista, value);
            if(antAlvo){
                removeu = delEltoList(lista, antAlvo);
            }
        }
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
    while(!isEmptyList(lista)){
        delTop(lista);
    }    
    free(lista);
    return NULL;
}

/*
Recebe um ponteiro para uma lista e um inteiro pos que significa 
uma posição do elemento na lista, de zero a [lista->numElto - 1],
Retorna o ponteiro da célula que está na posição pos da lista ou
NULL caso a lista seja menor do que infere pos
*/
Elto* seek(List *lista, unsigned int pos){
    int i;
    Elto *alvo = lista->firstElto;
    if(pos >= lista->numEltos)
        alvo = NULL;
    else{
        for(i = 0; i < pos; i++){
            alvo = alvo->next;
        }               
    }
    return alvo;
}

/*
Recebe um ponteiro para uma lista e um valor.
Retorna NULL caso não contenha um nó com o valor fornecido
ou o ponteiro para o nó encontrado.
*/
Elto* lookFor(List *lista, int value){
    Elto *temp = lista->firstElto;
    if(!isEmptyList(lista)){
        while(temp && temp->content != value){
            temp = temp->next;
        }
    }
    return temp;
}

/*
Recebe um ponteiro para uma lista e um valor.
Se houver o valor na lista e ele não estiver no primeiro nó, 
retorno o ponteiro para o nó anterior. 
Caso contrário, retorna NULL.
*/
Elto* lookForAnt(List *lista, int value){
    Elto *anterior = lista->firstElto;
    if(!isEmptyList(lista)){
        if(lista->numEltos == 1){
            if(anterior->content != value)
                anterior = NULL;
        }
        else{
            //o alvo pode ser o elto de índice 0
            if(anterior->content == value){
                anterior = NULL;
            }
            //ou ser o elto de índice 1 ou maior
            else{
                while(anterior->next && anterior->next->content != value){
                    anterior = anterior->next;
                }
                //o alvo pode não estar na lista
                if(!anterior->next){
                    anterior = NULL;
                }
            }
        }
    }
    return anterior;
}

/*
Recebe um ponteiro para uma lista e um valor.
Se houver elemento esse conteúdo, retorna true
se não, retorna false
*/
bool belong(List* lista, int value){
    bool existe;
    Elto* antAlvo = lookFor(lista, value);
    existe = antAlvo ? true : false;
    return existe;
}