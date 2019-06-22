#include "queue.h"

void dump_node(iTree *node){
    printf("node em %p\n", node);
    printf("intervalo [%d, %d]\n", node->v.a, node->v.b);
    printf("supremo %d\n",node->max);
    printf("subtree left em %p\n", node->left);
    printf("subtree right em %p\n", node->right);
}

iTree* set_new_void_tree(iTree *r){
    r = (iTree*)malloc(1*sizeof(iTree));
    if(r){
        r->hight = -1;
        r->left = r->right = NULL;
        r->v.a = 0;
        r->v.b = 0;
        r->max = 0;
    }
    return r;
}

//Esta função retorna 1 se a árvore estiver vazia e 0 caso contrário
int isEmptyTree(iTree* r){
    if(r->hight == -1) return 1;
    else return 0;
}

iTree* newNode(interval *v){
    iTree *novo;
    novo = set_new_void_tree(novo);
    if(novo){
        novo->hight = 0;
        novo->v = *v;
        novo->max = v->b;
    }
    return novo;
}

iTree* getMaior(iTree* r){
    if(r == NULL) return NULL;
    if(r->right == NULL) return r;
    else return getMaior(r->right);
}

int iTree_height(iTree *r){
    if(r == NULL) return -1;
    else return r->hight;
}

int maxH(int h1, int h2){
    int max = h1;
    if(max < h2)
        max = h2;
    return max;
}

iTree* iTree_rotateLeft(iTree* top){
    iTree *ntop = top->right;
    top->right = ntop->left;
    ntop->left = top;
    top->hight = 1 + maxH(iTree_height(top->left), iTree_height(top->right));
    ntop->hight = 1 + maxH(iTree_height(ntop->left), iTree_height(ntop->right));
    return ntop;
}

iTree* iTree_rotateRight(iTree* top){
    iTree *ntop = top->left;
    top->left = ntop->right;
    ntop->right = top;
    top->hight = 1 + maxH(iTree_height(top->left), iTree_height(top->right));
    ntop->hight = 1 + maxH(iTree_height(ntop->left), iTree_height(ntop->right));
    return ntop;
}

iTree* rebalance(iTree* r){
    int lh = iTree_height(r->left);
    int rh = iTree_height(r->right);
    int f = lh - rh;
    r->hight = 1 + maxH(lh, rh);
    
    if(f == 2){
        if(-1 == (iTree_height(r->left->left)-iTree_height(r->left->right)))
            r->left = iTree_rotateLeft(r->left);
        r = iTree_rotateRight(r);
    }
    else if(f == -2){
        if(1 == (iTree_height(r->right->left)-iTree_height(r->right->right)))
            r->right = iTree_rotateLeft(r->right);
        r = iTree_rotateLeft(r);
    }
    
    iTree *temp = getMaior(r);
    r->max = temp->max;
    temp = NULL;

    return r;
}

iTree* iTree_delete(interval *x, iTree *r){
    iTree* temp;
    if(r == NULL) return r;
    else{
        if(r->v.a < x->a){
            r->right = iTree_delete(x, r->right);
        }
        else if(r->v.a > x->a){
            r->left = iTree_delete(x, r->left);
        }
        else{
            if(r->left == NULL){//r sem filhos à esquerda
                temp = r;
                r = r->right;
                free(temp);
            }
            else if(r->right == NULL){//r sem filhos à direita
                temp = r;
                r = r->left;
                free(temp);
            }
            else{//r com dois filhos
                temp = getMaior(r->left);
                r->v = temp->v;
                r->left = iTree_delete(&(temp->v), r->left);
            }
        }
        if(r) return rebalance(r);
        else return NULL;
    }
}

iTree* iTree_insert(interval *x, iTree *r){
    if(r == NULL || isEmptyTree(r)){
        r = newNode(x);
        return r;
    }
    else{
        if(x->a < r->v.a)
            r->left = iTree_insert(x, r->left);
        else 
            r->right = iTree_insert(x, r->right);
        
        if(r->max < x->b) 
            r->max = x->b;
        
        return rebalance(r);    }
}

void showContentGraphicaly(iTree* r, Queue* nodes){
    int i;
    for(i = 0; i < r->hight; i++)
        printf("\t");
    printf("[%d, %d], m=%d, h=%d", r->v.a, r->v.b, r->max, r->hight);
    // printf("[%d, %d]", r->v.a, r->v.b);
    for(i = 0; i < r->hight; i++)
        printf("\t");
    if(nodes->qtd_nodes == 0){
        printf("\n");
    }
    // else{
        if(nodes->qtd_nodes > 0 && nodes->head->next->r->hight != r->hight){
            printf("\n");   
        }
    // }
    if(r->left == NULL && r->right != NULL){
        for(i = 0; i < r->hight; i++)
            printf("\t");
    }
}

void iTree_display (iTree *r){
    Queue *nodes;
    nodes = newVoidQueue();
    Cell *cursor = NULL;
    if(r && !isEmptyTree(r) && nodes){
        enqueue(r, nodes);
        while (!isEmptyQueue(nodes)) {
            cursor = dequeue(nodes);
            showContentGraphicaly(cursor->r, nodes);
            if(cursor->r->left){
                enqueue(cursor->r->left, nodes);
            }
            if(cursor->r->right){
                enqueue(cursor->r->right, nodes);
            }
        }        
    }
    killQueue(nodes);

}


interval* iTree_search(interval *v, iTree* r){
    Queue* fila = (Queue*) malloc(sizeof(Queue));
    fila = newVoidQueue(); 
    enqueue(r, fila);
    while(!isEmptyQueue(fila)){
        Cell *temp = dequeue(fila);
        iTree *t = temp->r;
        if(t->v.a < v->a && t->v.b >= v->a){
            showContent(t);
            fila = killQueue(fila);
            return v;
        }
        if(t->v.a == v->a){
            showContent(t);
            fila = killQueue(fila);
            return v;
        }
        if(t->v.a > v->a && t->v.a <= v->b){
            showContent(t);
            fila = killQueue(fila);
            return v;
        }
        if(t->left){
            enqueue(t->left, fila);
        }
        if(t->right)
            enqueue(t->right, fila);
    }
    fila = killQueue(fila);
}


void iTree_overlap_list(interval *v, iTree* r){
    Queue* fila = (Queue*) malloc(sizeof(Queue));
    fila = newVoidQueue(); 
    enqueue(r, fila);
    while(!isEmptyQueue(fila)){
        Cell *temp = dequeue(fila);
        iTree *t = temp->r;
        if(t->v.a <= v->b && v->a <= t->v.b){
            showContent(t);
        }
        if(t->left){
            enqueue(t->left, fila);
        }
        if(t->right)
            enqueue(t->right, fila);
    }
    fila = killQueue(fila);
}