/*  nmn,.
 * @Author: fengsc
 * @Date: 2021-04-14 20:35:24
 * @LastEditTime: 2021-04-16 19:44:34
 */

/*#include <stdio.h>
#define MAXN 20

void CountOff(int n, int m, int out[]);

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff(n, m, out);
    for (i = 0; i < n; i++)
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}
void CountOff(int n, int m, int out[])
{
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i ;
    }
    for (int k = 0, count; k < n; k++)
    {
        count = m - 1;
        while (count--) //判断后再--
        {
            int temp = a[0];
            for (int j = 0; j < n - k - 1; j++)
            {
                a[j] = a[j + 1];
            }
            a[n - k - 1] = temp;
        }
        out[a[0]] = k + 1;
        for (int l = 0; l < n - k - 1; l++)
        {
            a[l] = a[l + 1];
        }
    }
}
#include <stdio.h>
int main()
{
    char c[10];
    gets(c);
    puts(c);
    return 0;
}*/
/*#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}
#include<string.h>
char *match( char *s, char ch1, char ch2 )
{int i=0;
    for(;i<strlen(s);i++)
    {
        if(s[i]==ch1)
        {
            int j=i;
            for(;s[j]!=ch2&&j<strlen(s);j++)
         printf("%c",s[j]);
         printf("%c\n",s[j]);
         return s+i;
           /* if(s[j]!=0)
           printf("%c",s[j]);
                printf("\n");
                return s+i;*/
/*     }
        
    }
    printf("\n");
    return s+i;}*/
/* #include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

/*int main()
{
    char s[MAXS], t[MAXS], *pos;

  gets(s);
  gets(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}
#include <string.h>
char *search( char *s, char *t )
{
    for(int i=0;i<strlen(s);i++)
    {
          if(t[0]==s[i])
          {
            int begin=i;
              int j=0,count=0;
              while(t[j])
              {
                  if(t[j]==s[i+j])
                      count++;j++;
              }
              if(count==strlen(t))
                  return s+begin; 
          }
        
    }
        return NULL;
}*/
/*#include <stdio.h>
double p(int x, int n)
{
    double sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= x;
    return sum;
}
int main()
{
    int n;
    7 scanf("%d", &n);
    for (int i = p(10, n - 1), sum, temp; i <= p(10, n) - 1; i++)
    {
        sum = 0;
        temp = i;
        while (temp)
        {
            sum += p(temp % 10, n);
            temp /= 10;
        }

        if (sum == i)
            printf("%d\n", i);
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
void func(int *matrix, int x, int y, int start, int n)
{
    int i, j;
    if (n <= 0)
        return;
    if (n == 1)
    {
       *(matrix+x*n+y) = start;
        return;
    }
      for (i = x; i < x + n - 1; i++)
       *(matrix+n*y+i)= start++;
    for (j = y; j < y + n - 1; j++)
        *(matrix+n*j+x+n-1) = start++;
    for (i = x + n - 1; i > x; i--)
        *(matrix+n*(y+n-1)+i) = start++;
    for (j = y + n - 1; j > y; j--)
       *(matrix+n*j+x) = start++;
    func(matrix,x + 1, y + 1, start, n - 2);
}
int main()
{
    int n;
    scanf("%d", &n);
    
    int *matrix;
    matrix = (int *)malloc(n*n*sizeof(int));
    /*int **matrix;
    matrix=(int **)malloc(n*sizeof(int*));
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }*/
    func(matrix,0, 0, 1, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j)
                printf(" %2d", *(matrix+n*i+j));
            else
                printf("%2d", *(matrix+n*i+j));
        }
        printf("\n");
    }
    free(matrix);
  
    return 0;
}
