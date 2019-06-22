#include <stdio.h>
#include <stdlib.h>
#include "intervalTree.h"

int main() {
    int op;
    iTree *tree;
    tree = set_new_void_tree(tree);
    interval *v = NULL;

    do{
        printf("Escolha uma operacao 1-5: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                v = (interval*) malloc(1*sizeof(interval));
                if(v){
                    printf("novo intervalo a = ");
                    scanf("%d", &(v->a));
                    printf("b = ");
                    scanf("%d", &(v->b));
                    tree = iTree_insert(v, tree);
                    v = NULL; 
                }
                else {
                    printf("MEMORY FULL");
                }
            break;
            case 2:
                if(!isEmptyTree(tree)){
                    v = (interval*) malloc(1*sizeof(interval));
                    if(v){
                        printf("intervalo a ser excluido a = ");
                        scanf("%d", &(v->a));
                        printf("b = ");
                        scanf("%d", &(v->b));
                        tree = iTree_delete(v, tree);
                        free(v);
                        v = NULL;
                    }
                    else {
                        printf("MEMORY FULL");
                    }
                }
            break;
            case 3:
                if(!isEmptyTree(tree)){
                    v = (interval*) malloc(1*sizeof(interval));
                    if(v){
                        printf("intervalo a ser procurado a = ");
                        scanf("%d", &(v->a));
                        printf("b = ");
                        scanf("%d", &(v->b));
                        iTree_search(v, tree);
                        free(v);
                        v = NULL;
                    }
                    else {
                        printf("MEMORY FULL");
                    }
                }
            break;
            case 4:
                if(!isEmptyTree(tree)){
                    v = (interval*) malloc(1*sizeof(interval));
                    if(v){
                        printf("intervalo a ser procurado a = ");
                        scanf("%d", &(v->a));
                        printf("b = ");
                        scanf("%d", &(v->b));
                        iTree_overlap_list(v, tree);
                        free(v);
                        v = NULL;
                    }
                    else {
                        printf("MEMORY FULL");
                    }
                }
            break;
            case 5:
                if(!isEmptyTree(tree)){
                    iTree_display(tree);
                }                
            break;
            default:
                break;
            }
    } while (op > 0 && op < 6);

    free(tree);

    return 0;
}