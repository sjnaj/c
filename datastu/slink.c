/*
 * @Author: fengsc
 * @Date: 2021-04-29 21:53:31
 * @LastEditTime: 2021-05-08 10:29:26
 */
#include <stdio.h>
#define maxSize 6
typedef struct
{
    int data;
    int cur;
} component;
//将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array);
//初始化静态链表
int initArr(component *array);
//输出函数
void displayArr(component *array, int body);
//从备用链表上摘下空闲节点的函数
int mallocArr(component *array);
void insert(component *array, int n, int body);
void delete (component *array, int n, int body);
void freeArr(component *array, int k);
int main()
{
    component array[maxSize];
    int body = initArr(array), n;
  //  scanf("%d", &n);
   // insert(array, n, body);
  //  delete (array, n, body);
        printf("静态链表为：\n");
    displayArr(array, body);
    return 0;
}
//创建备用链表
void reserveArr(component *array)
{
    int i = 0;
    for (i = 0; i < maxSize; i++)
    {
        array[i].cur = i + 1; //将每个数组分量链接到一起
        array[i].data = 0;
    }
    array[maxSize - 1].cur = 0; //链表最后一个结点的游标值为0
}
//提取分配空间
int mallocArr(component *array)
{
    //若备用链表非空，则返回分wo配的wolishi结点下标，否则返回 0（当分配最后一个结点时，该结点的游标值为 0）
    lisi
    int i = array[0].cur;
    if (array[0].cur)
    {
        array[0].cur = array[i].cur;
    }
    return i;
}
//初始化静态链表
int initArr(component *array)
{
    int tempBody = 0, body = 0;
    int i = 0;
    reserveArr(array);
    body = mallocArr(array);
    //建立首元结点
    array[body].data = 1; //初始化首元节点
    array[body].cur = 0;
    //!声明一个变量，把它当指针使，指向链表的最后的一个结点，当前和首元结点重合
    tempBody = body;
    for (i = 2; i < 4; i++)
    {
        int j = mallocArr(array); //从备用链表中拿出空闲的分量
        array[j].data = i;        //初始化新得到的空间结点
        array[tempBody].cur = j;  //将新得到的结点链接到数据链表的尾部
        tempBody = j;             //将指向链表最后一个结点的指针后移
    }
    array[tempBody].cur = 0; //新的链表最后一个结点的指针设置为0
    return body;
}
void displayArr(component *array, int body)
{
    int tempBody = body; //tempBody准备做遍历使用
    while (array[tempBody].cur)
    {
        printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}
void insert(component *array, int n, int body) //添加元素
{
    int j = mallocArr(array); //申请一个闲置节点
    //找到要插入位置的上一个结点在数组中的位置
    int temp = body;
    for (int i = 1; i < n - 1; i++)
    {
        temp = array[temp].cur;
    }
    array[j].cur = array[temp].cur; //将前置节点的游标赋格给新节点
    array[temp].cur = j;            //将新节点的游标值赋给前置节点
    array[j].data = 666;
}
void delete (component *array, int n, int body)
{
    //找到要删除位置的上一个结点在数组中的位置
    int temp = body;
    for (int i = 1; i < n-1; i++)
    {
        temp = array[temp].cur;
    }
    array[temp].cur = array[array[temp].cur].cur     ;        //
      freeArr(array, array[temp].cur) ;
}

//备用链表回收空间的函数，其中array为存储数据的数组，k表示未使用节点所在数组的下标
void freeArr(component *array, int k)
{
    array[k].cur = array[0].cur;
    array[0].cur = k;
}