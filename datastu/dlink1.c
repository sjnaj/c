/*
 * @Author: fengsc
 * @Date: 2021-05-11 19:24:18
 * @LastEditTime: 2021-05-11 20:08:14
 */
#include <stdio.h>
#include <stdlib.h>
struct stu
{
    char c;
    struct stu *prev;
    struct stu *next;
};
typedef struct stu *link;
int main()  
{
    link head = NULL;
    link prev=NULL;
    link next;
    for (int i = 0; i < 26; i++)
    {
        link cur = (link)malloc(sizeof(struct stu));
        if (!head)
            head = cur;
        else
            prev->next =cur;
        cur->c = 'A' + i;
        head->prev=cur;
        cur->next =head;
        cur->prev=prev;
        prev = cur;
    }
    int n;
    scanf("%d", &n);
    if (n < 0)
    {
      n*=-1;  
        while (n--)
            head = head->prev;
    }
     if (n > 0)
    {
        while (n--)
            head = head->next;
    }
    
    for (int i = 0; i < 26; i++, head = head->next)
        printf("%c ", head->c);
    return 0;
}