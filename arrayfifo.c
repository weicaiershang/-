#include <stdio.h>

#define QUEUE_SIZE 5

int enQueue(int *a, int front, int rear, int data){
    if((rear + 1) % QUEUE_SIZE == front){
        printf("Full Queue!\n");
        return rear;
    }
    a[rear % QUEUE_SIZE] = data;
    rear++;
    return rear;
}

int deQueue(int *a, int front, int rear){
    if(front == rear % QUEUE_SIZE){
        printf("Empty Queue!\n");
        return front;
    }
    printf("%d ", a[front]);
    front = (front + 1) % QUEUE_SIZE;
    return front;
}

int main(){
    int a[QUEUE_SIZE];
    int front, rear;
    front = rear = 0;
    rear = enQueue(a, front, rear, 1);
    rear = enQueue(a, front, rear, 2);
    rear = enQueue(a, front, rear, 3);
    rear = enQueue(a, front, rear, 4);
    front = deQueue(a, front, rear);
    rear = enQueue(a, front, rear, 5);
    front = deQueue(a, front, rear);
    rear = enQueue(a, front, rear, 6);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
}
