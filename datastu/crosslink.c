/*
 * @Author: fengsc
 * @Date: 2021-05-15 11:12:39
 * @LastEditTime: 2021-05-15 21:28:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CLnode //节点结构体
{
    int r, c, ele;
    //位置和元素
    struct CLnode *prow, *pcol; //行链指针，列链指针
} CLnode, *Clink;
typedef struct //矩阵信息
{
    int row, col, sum;    //总行数，总列数，非零元素数；
    Clink *rhead, *chead; //!行列头指针动态数组
} *Crosslist;
void init(Crosslist *, int, int, int);//初始化
void assign(Crosslist *, int, int, int);//赋值
void print(Crosslist);//打印
int find(Crosslist, int, int); //查找
int main()
{
    int m, n, t;
    Crosslist M;
    while (1)
    {
        printf("输入矩阵的行数、列数和非0元素个数：");
        scanf("%d%d%d", &m, &n, &t);
        if (m > 0 && n > 0 && t >= 0 && t <= m * n) //矩阵大小条件，循环输入直到符合条件
        {
            M->row = m;
            M->col = n;
            M->sum = t;
            break;
        }
    }
    init(&M,m,n,t);
    assign(&M, m, n,t);
    print(M);
    printf("please input the loc\n");
    scanf("%d%d", &m, &n);
    printf("%d\n",find(M, m, n)) ;
    return 0;
}
void init(Crosslist *N, int m, int n, int t)
{
    Crosslist M = *N;

    //*因为下标从1开始，所以头结点指针多分配一个内存
    if (!(M->rhead = (Clink *)malloc((m + 1) * sizeof(Clink))) || !(M->chead = (Clink *)malloc((n + 1) * sizeof(Clink))))
    {
        printf("初始化矩阵失败\r\n");
        exit(0);
    }
    // 初始化行头指针向量;各行链表为空链表
    for (int i = 1; i <= m; i++)
    {
        M->rhead[i] = NULL;
    }
    // 初始化列头指针向量;各列链表为空链表
    for (int j = 1; j <= n; j++)
    {
        M->chead[j] = NULL;
    }
}
void assign(Crosslist *N, int m, int n, int t)
{
    Crosslist M = *N;
    Clink p, q;
    while (M->sum) //*计数循环
    {
        scanf("%d%d%d", &m, &n, &t);
        if (m < 1 || n < 1 || m > M->row || n > M->col) //*位置条件
        {
            printf("please correct the location:\n");
            continue;
        }
        if (!(p = (Clink)malloc(sizeof(CLnode)))) //初始化节点
        {
            printf("Initital failure,u can try again\n");
            continue;
        }
        p->r = m, p->c = n;
        p->ele = t;
        if (!(M->rhead[m]) || n <= M->rhead[m]->c) //!在（首）节点前插入
        {
            p->prow = M->rhead[m];
            M->rhead[m] = p;//首指针重新指向第一列
        }
        else
        {
            q = M->rhead[m];
            while (q)
            {

                if (!(q->prow) || q->prow->c >= n) //!在节点后插入,注意条件顺序，这样只有在非空的时候才会判断第二个条件
                {
                    p->prow = q->prow;
                    q->prow = p;
                }
                q = q->prow;
            }
        }
        if (!(M->chead[n]) || !(M->chead[n]->r >= m))
        {
            p->pcol = M->chead[n];
            M->chead[n] = p;
        }
        else
        {
            q = M->chead[n];
            while (q)
            {
                if (!(q->pcol) || (q->pcol->r >= m))
                {
                    p->pcol = q->pcol;
                    q->pcol = p;
                }
                q = q->pcol;
            }
        }
        M->sum--;
    }
}
void print(Crosslist M)
{
    int flag;
    Clink p;
    for (int i = 1; i <= M->row; i++)
    {
        for (int j = 1; j <= M->col; j++)
        {
            p = M->rhead[i];
            flag = 1;
            while (p)
            {
                if (p->r == i && p->c == j)
                {
                    printf("%d ", p->ele);
                    flag = 0;
                    break;
                }
                p = p->prow;
            }
            if (flag)
                printf("0 ");
        }
        printf("\n");
    }
   
}
int find(Crosslist M, int r, int c)
{
    Clink p = M->rhead[r];
    while (p)
    {
        if (p->c == c)
        {
            return p->ele;
        }
        p = p->prow;
    }
    return 0;
}
