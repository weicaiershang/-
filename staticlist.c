#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 6

typedef struct{
    int data;
    int cursor;
}StaticList;

/**
 * @brief reserveArr    将结构体数组中的所有分量连接到备用链表中
 * @param sList
 */
void reserveArr(StaticList *sList);

/**
 * @brief initArr   初始化静态链表
 * @param sList
 * @return
 */
int initArr(StaticList *sList);

/**
 * @brief displayArr
 * @param sList
 * @param body
 */
void displayArr(StaticList *sList, int body);

/**
 * @brief mallocArr 从备用链表上摘下空闲节点
 * @param sList
 * @return
 */
int mallocArr(StaticList *sList);

/**
 * @brief insertArr 向静态链表中插入元素
 * @param sList 要插入的链表
 * @param body  起始下标
 * @param value 要插入的值
 * @param index 要插入的位置
 */
void insertArr(StaticList *sList, int body, int value, int index);

/**
 * @brief freeArr 将某一内存放回备用链表
 * @param sList 要处理的链表
 * @param index 要放回的下标
 */
void freeArr(StaticList *sList, int index);

/**
 * @brief deleteArr 删除链表中的某一个元素
 * @param sList 要处理的链表
 * @param body  首元节点下标
 * @param value 要删除的值
 */
void deleteArr(StaticList *sList, int body, int value);

/**
 * @brief selectElem 查找元素
 * @param sList 要查找的链表
 * @param body  首元节点下标
 * @param value  要查找的值
 * @return
 */
int selectElem(StaticList *sList, int body, int value);

/**
 * @brief amendElem 修改某一元素的值
 * @param sList 要处理的链表
 * @param body  首元节点下标
 * @param oldValue  旧值
 * @param newValue  新值
 */
void amendElem(StaticList *sList, int body, int oldValue, int newValue);

/*************************************************************/
int main(){
    StaticList sList[MAX_SIZE];
    memset(sList, 0, sizeof (StaticList)*MAX_SIZE);
    int body = initArr(sList);
    printf("Static List is:\n");
    displayArr(sList, body);

    //在3的位置上插入3
    printf("Inset 3 in position 3:\n");
    insertArr(sList, body, 17, 1);
    displayArr(sList, body);

    return 0;
}

void reserveArr(StaticList *sList){
    for(int i=0; i<MAX_SIZE; i++)
    {
        sList[i].cursor = i+1;
    }
    sList[MAX_SIZE - 1].cursor = 0;
}

int mallocArr(StaticList *sList){
    /**备用链表摘除节点最简单的方法是摘除a[0]的直接后继节点；同样，向备用链表中添加空闲节点也是
    添加作为a[0]新的直接后继节点*/
    int i = sList[0].cursor;
    if(sList[0].cursor){        //不为0，说明还有存储空间
        sList[0].cursor = sList[i].cursor;
    }
    return i;
}

int initArr(StaticList *sList){
    reserveArr(sList);
    int body = mallocArr(sList);
    //声名一个变量，把它当指针，指向链表的最后一个节点，应为链表为空，所以和头节点重合
    int temp = body;
    int tempBody = temp;
    for (int i=1; i<4; i++) {
        tempBody = temp;
        sList[temp].data = i;
        int j = mallocArr(sList);
        sList[temp].cursor = j;
        temp = j;
    }
    sList[tempBody].cursor = 0;
    return body;
}

void displayArr(StaticList *sList, int body)
{
    int tempBody = body;
    while (sList[tempBody].cursor) {
        printf("%d, %d;\t", sList[tempBody].data, sList[tempBody].cursor);
        tempBody = sList[tempBody].cursor;
    }
    printf("%d, %d\n", sList[tempBody].data, sList[tempBody].cursor);
}

void insertArr(StaticList *sList, int body, int value, int index){
    int tempBody = body;
    for(int i=1; i<index; i++){
        tempBody = sList[tempBody].cursor;
    }
    int insert = mallocArr(sList);
    sList[insert].data = value;
    sList[insert].cursor = sList[tempBody].cursor;
    sList[tempBody].cursor = insert;
}

void freeArr(StaticList *sList, int index){
    sList[index].cursor = sList[0].cursor;
    sList[0].cursor = index;
}

void deleteArr(StaticList *sList, int body, int value){
    int tempBody = body;
    int beforeTempBody = tempBody;
    while (sList[tempBody].data != value) {
        beforeTempBody = tempBody;
        tempBody = sList[tempBody].cursor;
        if(tempBody == 0){
            printf("Static List has no %d\n", value);
            return;
        }
    }

    //运行到此，说明链表中含有value
    sList[beforeTempBody].cursor = sList[tempBody].cursor;
    freeArr(sList, tempBody);
}

int selectElem(StaticList *sList, int body, int value){
    int tempBody = body;
    while (sList[tempBody].cursor != 0) {
        if(sList[tempBody].data == value)
            return tempBody;
        tempBody = sList[tempBody].cursor;
    }
    return -1;
}

void amendElem(StaticList *sList, int body, int oldValue, int newValue){
    int index = selectElem(sList, body, oldValue);
    if(-1 == index){
        printf("There is no value %d in StaticList\n", oldValue);
        return;
    }
    sList[index].data = newValue;
}
