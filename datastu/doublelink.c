/*
 * @Author: fengsc
 * @Date: 2021-04-30 18:21:15
 * @LastEditTime: 2021-04-30 22:42:15
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    struct link *prev;
    struct link *next;
    int data;
} link;
link *init(link *head);
link *insert(link *head, int n);
link *delete (link *head, int n);
int main()
{
    link *head = NULL;
    head = init(head);
    int n;
    scanf("%d", &n);
    head = insert(head, n);
    head=delete(head,n+1);
    link *head2 = head;
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
    while (head2->next)
        head2 = head2->next;
    while (head2)
    {
        printf("%d", head2->data);
        head2 = head2->prev;
    }
    return 0;
}

link *init(link *head)
{
    link *pre = NULL;
    for (int i = 1; i <= 5; i++)
    {
        link *cur = (link *)malloc(sizeof(link));
        if (!head)
            head = cur;
        else
            pre->next = cur;
        cur->next = NULL;
        cur->data = i;
        cur->prev = pre;
        pre = cur;
    }
    //返回新创建的链表
    return head;
}
link *insert(link *head, int n)
{
    link *nhead = (link *)malloc(sizeof(link)), *temp; //新建头节点以实现任意位置插入
    nhead->prev = NULL;
    nhead->next = head;
    head->prev = nhead;
    temp = nhead; //暂存新头节点以返回首元节点
    for (int i = 0; i < n - 1; i++)
    {
        nhead = nhead->next;
    }
    link *cur = (link *)malloc(sizeof(link));
    cur->next = nhead->next;
    nhead->next->prev = cur;
    cur->prev = nhead;
    nhead->next = cur;
    cur->data = 666;
    temp->next->prev = NULL; //将首元节点的前置节点改为NULL
    return temp->next;
}
link *delete (link *head, int n)
{
    link *nhead = (link *)malloc(sizeof(link)), *temp; //新建头节点以实现任意位置插入
    nhead->prev = NULL;
    nhead->next = head;
    head->prev = nhead;
    temp = nhead; //暂存新头节点以返回首元节点
    for (int i = 0; i < n - 1; i++)
    {
        nhead = nhead->next;
    }
    nhead->next = nhead->next->next;
    nhead->next->prev = nhead;
    temp->next->prev = NULL;
    return temp->next;
}
