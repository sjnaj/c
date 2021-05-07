/*
 * @Author: fengsc
 * @Date: 2021-04-23 10:56:40
 * @LastEditTime: 2021-04-30 11:34:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
clock_t start,end;
#define SIZE 20
char input[SIZE];
int count = 0;
typedef struct film
{
    char title[SIZE];
    int rating;
    struct film *next; // !链表的核心
} link;
link *insertElem(link *p, int add);                          //插入
link *delElem(link *p, int add);                             //删除
int findElem(link *p, char *title);                          //查找
link *modifyElem(link *p, int add, char *title, int rating); //修改
link *reverseElem(link *p);
link *reverseElem1(link *p);
link *reverseElem2(link *p);
char *s_gets(char *st, int n); //安全输入
int main(void)
{
    link *head = (link *)malloc(sizeof(link)); //初始化头节点
    link *prev = head, *current;
    char c1;
    int flag = 1; //输出标志
    while (1)
    {

        printf("\e[1;40;33mA.create new link  B.insertelem\t\tC.delelem\tD.findelem\nE.modify\t  F.save in a file\tG.open the file saved.\tH.I.J.reverselink.\nElse.quit\n\e[0m");
        scanf("%c", &c1);
        getchar();
        switch (c1)
        {
        case 'A':
        {
            /* 收集并储存信息 */ printf("\e[1;40;34mEnter first subject title:\n\e[0m");
            while (s_gets(input, SIZE) != NULL && input[0] != '\0')
            {
                current = (link *)malloc(sizeof(link));
                prev->next = current;
                current->next = NULL;
                strcpy(current->title, input);
                printf("\e[1;40;36mEnter your rating <0-10>:\n\e[0m");
                scanf("%d", &current->rating);
                getchar();
                printf("\e[1;40;32mEnter next subject title (empty line to stop):\n\e[0m");
                prev = current;
                count++;
            }
        }
        break;
        case 'B': //插入节点
        {
            char c;
            int n;
            printf("where do you want to insert(from 1 to %d):\n", count + 1); //*可插入位置比节点数量多一个
            scanf("%d", &n);
            getchar();
            insertElem(head, n);
        }
        break;
        case 'C': //删除节点
        {
            int n;
            printf("which elem do u want to del(from 1 to %d):\n", count);
            scanf("%d", &n);
            getchar();
            delElem(head, n);
        }
        break;
        case 'D': //查找元素
        {
            while (1)
            {
                printf("\e[1;40;31mplease input the title you want to find(empty line to main dir)\n");
                if (s_gets(input, SIZE) && input[0])
                {
                    int result = findElem(head, input);
                    if (result)
                        printf("the rating of %s is %d\n", input, result);
                    else
                        printf("havn't found\n");
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            break;
        }
        case 'E': //修改元素
        {
            while (1)
            {
                printf("which one do you want to modify:(from 1 to %d. press 0 to main dir):\n", count);
                int n, rat;
                scanf("%d", &n);
                getchar();
                if (n)
                {
                    printf("new tltle:\n");
                    s_gets(input, SIZE);
                    printf("new rating:\n");
                    scanf("%d", &rat);
                    getchar();
                    modifyElem(head, n, input, rat);
                }
                else
                    break;
            }
            break;
        }
        case 'F': //!保存到文件（切勿用数据块读取，太坑了）
        {
            FILE *fp0, *fp;
            fp0 = fopen("/home/fengsc/Desktop/c/datastu/chart", "w"); //覆盖并写入表头
            fputs("num\ttitle\trating\n", fp0);
            fclose(fp0);
            if (!(fp = fopen("/home/fengsc/Desktop/c/datastu/chart", "a"))) //追加内容
            {
                printf("fail to open file,u can retry or quit(empty to main dir\n");
                s_gets(input, SIZE);
                if (!input[0])
                {
                    flag = 0;
                    break;
                }
            }
            current = head->next;
            int i = 1; //序号
            while (current != NULL)
            {
                fprintf(fp, "%-6d%-8s%-4d\n", i, current->title, current->rating);
                current = current->next;
                i++;
            }
            printf("save successfully\n");
            flag = 0;
            fclose(fp);
            break;
        }
        case 'G': //读取文件
        {
            FILE *fp1;
            if (!(fp1 = fopen("/home/fengsc/Desktop/c/datastu/chart", "r")))
            {
                printf("please create link first\n");
                flag = 0;
                break;
            }
            int temp;
            int n, m;
            printf("how many:\n");
            scanf("%d", &n);
            getchar();
            rewind(fp1);
            fseek(fp1, 17, SEEK_SET); //!跨过表头,长度比字符串少1
            char s[SIZE];
            for (int i = 0; i < n; i++)
            {
                fscanf(fp1, "%d %s %d\n", &temp, s, &m);
                printf("%d %s %d\n", temp, s, m);
            }
            fclose(fp1);
            flag = 0;
            break;
        }
        case 'H':
        {
            head = reverseElem(head);
            break;
        }
        case 'I':
        {
            head = reverseElem1(head); //递归，需要直接传首元节点
            break;
        }
        case 'J':
        {
            head = reverseElem2(head);
            break;
        }
        default:
        {
            printf("bye\n");
            return 0;
        }
        }
        if (flag)
        {
            if (head->next == NULL) /* 显示书籍列表 */
                printf("No data entered.\n ");

            else
                printf("Here is the list:\n");
            current = head->next;
            int sequence = 1;
            while (current != NULL)
            {
                printf("\e[1;40;31m%d:subject: %s Rating: %d\n\e[0m", sequence++, current->title, current->rating);
                current = current->next;
            }
        }
    }
    /* 完成任务，释放已分配的内存 */
    current = head->next;
    while (head != NULL) //用head作中间量防止current丢失
    {
        current = head;
        head = current->next;
        free(current);
    }
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理剩余输入行
    }
    return ret_val;
}
link *insertElem(link *p, int add) //插入函数
{
    link *temp = p;                         //创建临时结点temp
    link *c = (link *)malloc(sizeof(link)); //创建插入结点c

    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++)
    {
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    printf("new title:\n");
    s_gets(input, SIZE);
    strcpy(c->title, input);
    printf("new rating:\n");
    scanf("%d", &c->rating);
    getchar();
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    count++;
    return p;
}
link *delElem(link *p, int add) //删除函数
{
    link *temp = p;
    link *del = NULL;
    //temp指向被删除结点的上一个结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    del = temp->next;              //单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     //手动释放该结点，防止内存泄漏
    return p;
}
int findElem(link *p, char *title)
{
    //新建一个指针t，初始化为头指针 p
    link *t = p;
    while (t->next)
    {
        t = t->next;
        if (!strcmp(t->title, title))
        {
            return t->rating;
        }
    }
    //程序执行至此处，表示查找失败
    return 0;
}
link *modifyElem(link *p, int add, char *title, int rating)
{
    link *temp = p;
    temp = temp->next; //在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    strcpy(temp->title, title);
    temp->rating = rating;
    return p;
}
link *reverseElem(link *p) //迭代反转
{
    if (p->next == NULL || p->next->next == NULL) //如果没有头节点则对应的两项为p和p->next.
        return p;
    link *pre = NULL; //逆转后的结束标志
    link *cur = p->next;
    link *temp;
    while (1)
    {
        temp = cur->next; //暂存下个节点的位置
        cur->next = pre;  //将下个节点改为前一个
        if (!temp)
        {
            temp = (link *)malloc(sizeof(link)); //*为最后的temp分配空间，因为它此时没有得到属于原链表的空间
            temp->next = cur;
            return temp;
        }
        pre = cur; /*右移*/
        cur = temp;
    }
}
link *reverseElem1(link *p) 
{
    p= p->next;
    if (p->next == NULL || p == NULL)//递归进入的终点和节点过少无需逆转的情况
    {
        link *newhead = (link *)malloc(sizeof(link));//新建头节点
        newhead->next = p;
        return newhead;
    }
    else
    {
        link *reverse = reverseElem1(p);//逐层进入
        /*逐层退出*/
        p->next->next = p;//逆转下一个节点的指向
        p->next = NULL;//逆转后最后一个节点的指向
        return reverse;//*返回值一直是newhead
    }
}

link *reverseElem2(link *p)//和迭代反转是等价的
{

    if (p->next == NULL || p->next->next == NULL)
        return p;
    p = p->next;
    link *beg = p;
    link *end = p->next;
    while (1)
    {
        //将 end 从链表中摘除
        beg->next = end->next;
        //将 end （按顺序）移动至链表头
        end->next = p;
        p = end;
        //调整 end 的指向，另其指向 beg 后的一个节点，为反转下一个节点做准备
        end = beg->next;
        if (end == NULL)
        {
            end = (link *)malloc(sizeof(link));
            end->next = p;
            return end;
        }
    }
}