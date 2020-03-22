typedef struct BiTNode
{
    int data;
    struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

#include <stdio.h>
#include <stdlib.h>

void createBiTree(BiTree *t){
    *t = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->data = 1;
    (*t)->lChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->lChild->data = 2;
    (*t)->rChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->rChild->data = 3;
    (*t)->rChild->lChild = NULL;
    (*t)->rChild->rChild = NULL;
    (*t)->lChild->lChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->lChild->rChild = NULL;
    (*t)->lChild->lChild->data = 4;
    (*t)->lChild->lChild->lChild = NULL;
    (*t)->lChild->lChild->rChild = NULL;
}

int main(){
    BiTree Tree;
    createBiTree(&Tree);
    printf("%d\n", Tree->lChild->lChild->data);
    printf("sssss\n");
    return 0;
}