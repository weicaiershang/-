/***
 * @Discription 描述了数据结构中链表是如何工作的
 * @头指针：一个普通的指针，它的特点是永远指向链表第一个节点的位置（第一个节点的地址）
 * @头结点：其实就是一个不存任何数据的空节点，通常作为链表的第一个节点。对于链表来说，头结点不是必须的，他的作用是为了方便解决某些问题
 * @首元结点：由于头结点是空节点的缘故，首元结点只是对链表中第一个存有数据节点的一个称谓，没有实际意义
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct List{
    int value;
    struct List *next;
}List;

/**
 * @brief initList 创建一个链表
 * @return 返回链表头指针
 */
List *initList(){
    List *p = (List *)malloc(sizeof (List)); //创建头结点{使用头结点容易操作}

    List *temp = p;

    //从第二个节点开始创建
    for(int i=1; i<5; i++){
        List *a = (List *)malloc(sizeof (List));
        a->value = i;
        a->next = NULL;
        temp->next = a; //将temp节点与新建立的a节点建立逻辑关系
        temp = a;       //temp指针是种植险新链表的最后一个节点
    }
    return p;
}

/**
 * @brief insetItem 向链表中插入元素，插入时要先连接后继节点，在处理前驱节点，否则后面的数据丢失
 * @param p 要操作的链表
 * @param value 要插入的值
 * @param index 要插入的位置 0对应头结点 1为首元结点
 * @return 插入后的链表的头指针
 */
List *insetItem(List *p, int value, int index){
    List *temp = p;
    for(int i=1; i<index; i++){
        if(temp->next == NULL){
            printf("Insert position is valid\n");
            return p;
        }
        temp = temp->next;
    }
    List *c = (List *)malloc(sizeof (List));
    c->value = value;
    c->next = temp->next;
    temp->next = c;
    return p;
}

/**
 * @brief deleteItem 删除元素
 * @param p 要处理的链表
 * @param index 下标 0对应头结点 1为首元结点
 * @return
 */
List *deleteItem(List *p, int index){
    List *temp = p;

    //判断index是否合理，教程上是没有判断的
    for(int i=0; i<index; i++){
        if(temp->next == NULL){
            printf("Delete position is valid\n");
            return p;
        }
        temp = temp->next;
    }

    temp = p;
    for(int i=1; i<index; i++){
        temp = temp->next;
    }
    List *del = temp->next;
    temp->next = temp->next->next;
    free(del);

    return p;
}

/**
 * @brief selectElem    查找链表元素
 * @param p 要查找的链表
 * @param elem  要查找的元素
 * @return  元素的下标
 */
int selectElem(List *p, int elem){
    List *t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if(t->value == elem){
            return i;
        }
        i++;
    }
    return -1;
}

/**
 * @brief amendElem 修改某元素的值
 * @param p 要修改的链表
 * @param index 要修改的下标
 * @param newValue 新的值
 * @return 修改后的链表
 */
List *amendElem(List *p, int index, int newValue){
    List *temp = p;

    //判断index是否合理，教程上是没有判断的
    for(int i=0; i<index; i++){
        if(temp->next == NULL){
            printf("Change position is valid\n");
            return p;
        }
        temp = temp->next;
    }
    temp->value = newValue;
    return p;
}

/**
 * @brief display 显示链表
 * @param p
 */
void display(List *p){
    List *temp = p;
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->value);
    }
    printf("\n");
}

int main(){
    //初始化链表为 1 2 3 4
    printf("List init as:\n");
    List *p = initList();
    display(p);

    //在位置4插入值5
    printf("Insert value 5 in position 4: \n");
    p = insetItem(p, 5, 4);
    display(p);

    //删除位置3上的元素
    printf("Delete elem in position 3:\n");
    p = deleteItem(p, 3);
    display(p);

    //查找元素2的位置
    printf("Select elem value 2:\n");
    int index = selectElem(p, 2);
    if(-1 == index){
        printf("No such elem\n");
    }
    else{
        printf("Elem value in position: %d\n", index);
    }

    //修改元素值
    printf("Amend position 3 value to 7:\n");
    p = amendElem(p, 3, 7);
    display(p);
    return 0;
}
