#include <stdio.h>
#include <stdlib.h>
#include "intervalTree.h"

int main() {
    int op;
    iTree *tree;
    set_new_void_tree(tree);
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
            break;
            case 5:
                iTree_display(tree);
            break;
            default:
                break;
            }
    } while (op > 0 && op < 6);

    free(tree);

    return 0;
}