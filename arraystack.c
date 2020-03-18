#include <stdio.h>

int push(int *a, int top, int elem){
    a[++top] = elem;
    return  top;
}

int pop(int *a, int top){
    if(-1 == top){
        printf("Stack is empty\n");
        return -1;
    }
    printf("%d", a[top]);
    top--;
    return top;
}

int main(){
    int a[64] = {0};
    int top = -1;
#if 0   //测试栈
    top = push(a, top, 12);
    top = push(a, top, 13);
    top = push(a, top, 14);
    top = push(a, top, 15);

    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
#else   //使用顺序栈进行进制转换
    int numInput = 0;
    printf("Input a num to change:");
    scanf("%d", &numInput);
    int order = 10;
    printf("Input a orderNum:");
    scanf("%d", &order);

    while (numInput) {
        top = push(a, top, numInput % order);
        numInput = numInput / order;
    }

    while (top != -1) {
        top = pop(a, top);
    }
    printf("\n");
#endif

}
