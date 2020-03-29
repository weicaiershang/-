typedef struct BiTNode
{
    int data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

#include <stdio.h>
#include <stdlib.h>

int top = -1; //使用栈遍历二叉树的栈顶标志
int sTop = -1;
void createBiTree(BiTree *t)
{
    *t = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->data = 1;
    (*t)->lChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->rChild = (BiTNode *)malloc(sizeof(BiTNode));

    (*t)->lChild->data = 2;
    (*t)->lChild->lChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->lChild->rChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->lChild->rChild->data = 5;
    (*t)->lChild->rChild->lChild = NULL;
    (*t)->lChild->rChild->rChild = NULL;
    (*t)->rChild->data = 3;
    (*t)->rChild->lChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->rChild->lChild->data = 6;
    (*t)->rChild->lChild->lChild = NULL;
    (*t)->rChild->lChild->rChild = NULL;
    (*t)->rChild->rChild = (BiTNode *)malloc(sizeof(BiTNode));
    (*t)->rChild->rChild->data = 7;
    (*t)->rChild->rChild->lChild = NULL;
    (*t)->rChild->rChild->rChild = NULL;
    (*t)->lChild->lChild->data = 4;
    (*t)->lChild->lChild->lChild = NULL;
    (*t)->lChild->lChild->rChild = NULL;
}

void displayData(BiTNode *elem)
{
    printf("%d\n", elem->data);
}

void preOrderTraverse(BiTree tree)
{
    if (tree)
    {
        displayData(tree);
        preOrderTraverse(tree->lChild);
        preOrderTraverse(tree->rChild);
    }
}

void push(BiTNode **a, BiTNode *tree)
{
    a[++top] = tree;
}

BiTNode *pop(BiTNode **a)
{
    if (-1 == top)
    {
        return NULL;
    }
    BiTNode *p = a[top];
    top--;
    return p;
}

BiTNode *getTop(BiTNode **a)
{
    if (-1 == top)
    {
        return NULL;
    }
    BiTNode *p = a[top];
    return p;
}
/**
 * 先序遍历指的是先访问根节点，然后左子树，然后右子树。
 * 所以先访问根节点，然后将右子树入栈，然后访问左子树
 * 然后到叶节点之后，将栈中的右子树依次出栈，并作为根
 * 节点依次循环访问即可*/
void preOrderTraverseWithStack(BiTree tree)
{
    BiTNode *a[20] = {NULL};
    BiTNode *p = tree;
    push(a, tree);
    while (-1 != top)
    {
        p = pop(a);
        while (p)
        {
            displayData(p);
            if (p->rChild)
            {
                push(a, p->rChild);
            }
            p = p->lChild;
        }
    }
}

void inOrderTraverse(BiTree tree)
{
    if (tree)
    {
        inOrderTraverse(tree->lChild);
        displayData(tree);
        inOrderTraverse(tree->rChild);
    }
}

/**
 * 中序遍历指的是先访问左子树，然后根节点，然后右子树
 * 所以根节点先入栈，然后左子树当做根节点继续，直到叶子节点
 * 然后打印叶子节点，出栈到叶子节点的根节点，
 * 然后该根节点的右子树作为根节点重复遍历，直到结束。
 * */
void inOrderTraverseWithStack(BiTree tree)
{
    BiTNode *a[20] = {NULL};
    BiTNode *p = tree;
    while (-1 != top || p)
    {
        while (p)
        {
            push(a, p);
            p = p->lChild;
        }
        // if (-1 != top)
        {
            p = getTop(a);
            displayData(p);
            p = pop(a);
            p = p->rChild;
        }
    }
}

void reOrderTraverse(BiTree tree)
{
    if (tree)
    {
        reOrderTraverse(tree->lChild);
        reOrderTraverse(tree->rChild);
        displayData(tree);
    }
}

typedef struct
{
    int flag;
    BiTNode *node;
} SBiTNode;

void sPush(SBiTNode **a, SBiTNode *tree)
{
    a[++sTop] = tree;
}

SBiTNode *sPop(SBiTNode **a)
{
    if (-1 == sTop)
    {
        return NULL;
    }
    SBiTNode *p = a[sTop];
    sTop--;
    return p;
}

SBiTNode *sGetTop(SBiTNode **a)
{
    if (-1 == sTop)
    {
        return NULL;
    }
    SBiTNode *p = a[sTop];
    return p;
}

/**
 * 必须要借助标志位才能实现后序遍历
 * 其实现逻辑与中序遍历类似，只不过根节点答出栈要加个判断
 * 即左子树和右子树都出栈后，根节点才能出栈
 * **/
void reOrderTraverseWithStack(BiTree tree)
{
    SBiTNode *a[20] = {NULL};
    BiTNode *p = tree;
    SBiTNode *sdata;
    while (p || -1 != sTop)
    {
        while (p)
        {
            SBiTNode *data = (SBiTNode *)malloc(sizeof(SBiTNode));
            data->node = p;
            data->flag = 0;
            sPush(a, data);
            p = p->lChild;
        }

        sdata = sPop(a);
        if (0 == sdata->flag)
        {
            SBiTNode *data = (SBiTNode *)malloc(sizeof(SBiTNode));
            data->node = sdata->node;
            data->flag = 1;
            sPush(a, data);
            p = sGetTop(a)->node->rChild;
        }
        else
        {
            displayData(sdata->node);
        }
    }
}

int rear = 0;
int front = 0;

void enQuene(BiTree *a, BiTree node)
{
    a[rear++] = node;
}

BiTNode *deQuene(BiTNode **a)
{
    return a[front++];
}

/**
 * 层次遍历使用队列实现，逻辑上比较简单
 * 先将根节点入队，根节点出队时，将其左右
 * 子节点入队，然后再出队下一个节点，出对
 * 时也将其左右子节点入队，直到队列完全出队
 * 完毕
 * ***/
void levelTraverseWithStack(BiTree tree)
{
    BiTree a[20] = {NULL};
    BiTNode *p = tree;
    enQuene(a, tree);
    while (rear > front)
    {
        p = deQuene(a);
        displayData(p);
        if (p->lChild)
        {
            enQuene(a, p->lChild);
        }
        if (p->rChild)
        {
            enQuene(a, p->rChild);
        }
    }
}

int main()
{
    BiTree Tree;
    createBiTree(&Tree);
    levelTraverseWithStack(Tree);
    return 0;
}
