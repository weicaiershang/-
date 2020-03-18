#include <stdio.h>
#include <stdlib.h>

typedef struct ListStack{
    float data;
    struct ListStack *next;
}ListStack;

ListStack *push(ListStack *stack, float elem){
    ListStack *node = (ListStack *)malloc(sizeof (ListStack));
    node->data = elem;
    node->next = stack;
    stack = node;
    return stack;
}

ListStack *pop(ListStack *stack){
    if(stack){
        ListStack *p = stack;
        stack = stack->next;
        printf("Pop elem:%f;\n", p->data);
        if(stack){
            printf("The new top elem is: %f;\n", stack->data);
        }else {
            printf("The stack is empty\n");
        }
        free(p);
    }
    else {
        printf("This is an empty stack\n");
    }
    return  stack;
}

int main(){
    ListStack *stack = NULL;
    stack = push(stack, 12.0f);
    stack = push(stack, 78.0f);
    stack = push(stack, 56.0f);
    stack = push(stack, 85.0f);

    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
}
