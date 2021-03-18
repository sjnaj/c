#include <stdio.h>
#include <math.h>

int i = 0; //全局变量

int invert(int n)
{
    if (n == 0)
        return i;
    else
    {
        i *= 10;
        i += n % 10;
        invert(n / 10);
    }
}

int main(void)
{
    int a[10], b; //未初始化时
    for (int j = 0; j < 10; j++)
    {
        //scanf("%d", &a[j]);
        b = scanf("%d", &a[j]);
        switch (b)
        {
        case 0:
        {
            scanf("%*[^\n]%*c");
            printf("error\n");
            break;
        }
        case EOF:
            break ;
        default:
        {
            if (invert(a[j]) == a[j])
                printf("yes");
            else
                printf("no");
            printf("\n");
            i = 0;
        }
        return 0;
        }
     /*   if (b == 0)
        {
            //printf("%d\n",b);
            scanf("%*[^\n]%*c"); //清空缓冲区中的不能接收字符，重新打开输入流
            printf("error\n");
            continue; //if(scanf("%d",&a[j])==EOF)//用文件作为输入源时去除空行的影响
        }
        else if
        {
            if (invert(a[j]) == a[j])
                printf("yes");
            else
                printf("no");
            printf("\n");
            i = 0;
        }*/
    }
}
