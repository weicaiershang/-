
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *head;              //顺序表的头
    int length;             //顺序表的长度
    int size;               //顺序表所占的内存
}Table;

#define SIZE 10

Table initTable(){
    Table t;
    t.head = (int *)malloc(SIZE * sizeof (int));
    if(!t.head)
    {
        printf("Init Err");
        exit(0);
    }
    t.length = 0;
    t.size = SIZE;
    return  t;
}

/**
 * @brief insertTable 向顺序表中插入元素
 * @param t 要插入的表
 * @param elem 要插入的值
 * @param index 要插入的位置
 * @return
 */
Table insertTable(Table t, int elem, int index){
    if(index < 1 || index > t.length + 1)
    {
        printf("Inset position err");
        return t;
    }

    //做插入操作时，需要看看顺序表是否有多余的空间供给插入的元素，如果没有，需要申请
    if(t.length == t.size)
    {
        t.head = (int *)realloc(t.head, (t.size+1)*sizeof (int));
        if(!t.head)
        {
            printf("realloc err");
            return t;
        }
        t.size += 1;
    }

    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    for(int i = t.length-1; i >= index-1; i--){
        t.head[i+1] = t.head[i];
    }
    t.head[index-1] = elem;
    t.length++;
    return t;
}

/**
 * @brief selectTable 查找顺序表
 * @param t 要查找的表
 * @param elem 要查找的元素
 * @return
 */
int selectTable(Table t, int elem){
    for(int i=0; i<t.length; i++){
        if(elem == t.head[i])
            return i+1;
    }
    return -1;
}

/**
 * @brief amendTable 修改表中的元素
 * @param t 要修改的表
 * @param elem 要修改的元素
 * @param newElement 新的元素
 * @return
 */
Table amendTable(Table t, int elem, int newElement){
    int index = selectTable(t, elem);
    t.head[index - 1] = newElement;
    return t;
}

/**
 * @brief delTable 删除表元素
 * @param t 要删除的表
 * @param index 要删除元素的下标
 * @return
 */
Table delTable(Table t, int index){
    if(index < 1 || index > t.length){
        printf("Delete Position err");
        return t;
    }

    //删除操作
    for(int i = index; i<t.length; i++)
    {
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;
}

void displayTable(Table t){
    for(int i=0; i<t.length; i++){
        printf("%d ", t.head[i]);
    }
    printf("\n");
}

int main(){
    Table t = initTable();
    for(int i=0; i<SIZE; i++){
        t.head[i] = i+1;
        t.length++;
    }
    printf("Table Elem is: \n");
    displayTable(t);

    //删除元素
    printf("Delete elem index 2:\n");
    t = delTable(t, 2);
    displayTable(t);

    //插入元素
    printf("Insert elem 15 in indef of 2:\n");
    t = insertTable(t, 15, 2);
    displayTable(t);

    //查找元素15的位置
    int index = selectTable(t, 15);
    printf("The index of 15 is %d\n", index);

    //将元素15改为2
    printf("Amend elem 15 to 2\n");
    t = amendTable(t, 15, 2);
    displayTable(t);

    return 0;
}
