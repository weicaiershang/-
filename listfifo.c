#include <stdio.h>
#include <stdlib.h>

typedef struct _QNode{
    int value;
    struct _QNode *next;
}QNode;

QNode *initQueue(){
    QNode *queue = (QNode *)malloc(sizeof (QNode));
    queue->next = NULL;
    return queue;
}

QNode *enQueue(QNode *rear, int data){
    QNode *enElem = (QNode *)malloc(sizeof (QNode));
    enElem->value = data;
    enElem->next = NULL;
    rear->next = enElem;
    rear = enElem;
    return rear;
}

QNode *deQueue(QNode *top, QNode *rear){
    if(top->next == NULL){
        printf("Empty fifo!\n");
        return rear;
    }
    QNode *p = top->next;
    printf("%d\n", p->value);
    top->next = p->next;
    if(rear == p){
        rear = top;
    }
    free(p);
    return rear;
}

int main(){
    QNode  *top, *rear;
    top = rear = initQueue();
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);

    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);

    rear = deQueue(top, rear);
}
