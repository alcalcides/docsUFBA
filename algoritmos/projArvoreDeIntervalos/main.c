#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int a, b;
}interval;


struct node{
    interval v;
    int hight;
    struct node *left, *right;
};
typedef struct node iTree;

void dump_node(iTree *node){
    printf("node %p\n", node);
    printf("intervalo [%d, %d]\n", node->v.a, node->v.b);
    printf("left %p\n", node->left);
    printf("right %p\n", node->right);
}

iTree* set_new_void_tree(iTree *arvore){
    arvore = (iTree*)malloc(1*sizeof(iTree));
    if(arvore){
        arvore->hight = -1;
        arvore->left = arvore->right = NULL;
        arvore->v.a = 0;
        arvore->v.b = 0;
    }
    return arvore;
}

iTree* newNode(){
    iTree *novo;
    novo = set_new_void_tree(novo);
    if(novo){
        novo->hight = 0;
    }
    return novo;
}

iTree* getMaior(iTree* r){
    iTree *cursor = r;
    while(cursor){
        if(cursor->right != NULL){
            cursor = cursor->right;
        }
    }
    return cursor;
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
    if(r == NULL){
        r = newNode();
        if(r){
            r->v = *x;
        }
        return r;
    }
    else if(r->v.a > x->a){
        r->left = iTree_insert(x, r->left);
        return rebalance(r);
    }
    else if(r->v.a < x->a){
        r->right = iTree_insert(x, r->right);
        return rebalance(r);
    }
}

void iTree_display (iTree *r){
    if(r->hight == 0){
        printf("[%d, %d]", r->v.a, r->v.b);
    }
    else{
        int i;
        for (i = 0; i < r->hight; i++) 
            printf("\t");
        printf("[%d, %d]", r->v.a, r->v.b);
        for (i = 0; i < r->hight; i++) 
            printf("\t");
        printf("\n");
        iTree_display(r->left);
        for (i = 0; i <= r->hight; i++) 
            printf("\t");
        iTree_display(r->right);
    }
    printf("\n");
}

int main() {
    int op;
    iTree *arvore = NULL;
    interval *x = NULL;
    arvore = set_new_void_tree(arvore);

    do{
        printf("Escolha uma operacao 1-5: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                x = (interval*) malloc(1*sizeof(interval));
                if(x){
                    printf("novo intervalo a = ");
                    scanf("%d", &(x->a));
                    printf("b = ");
                    scanf("%d", &(x->b));
                    iTree_insert(x, arvore);
                    free(x); 
                }
                else {
                    printf("MEMORY FULL");
                }
            break;
            case 2:
                x = (interval*) malloc(1*sizeof(interval));
                if(x){
                    printf("intervalo a ser excluido a = ");
                    scanf("%d", &(x->a));
                    printf("b = ");
                    scanf("%d", &(x->b));
                    iTree_delete(x, arvore);
                    free(x);
                }
                else {
                    printf("MEMORY FULL");
                }
            break;
            case 5:
                iTree_display(arvore);
            break;
            default:
                break;
            }
    } while (op > 0 && op < 6);
    

    free(arvore);
    return 0;
}