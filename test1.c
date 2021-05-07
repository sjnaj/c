/*
 * @Author: fengsc
 * @Date: 2021-02-28 12:05:15
 * @LastEditTime: 2021-03-26 23:55:21
 */
#define __STDC_LIB_EXT1__ 1

#include <stdio.h>

#define L 4
//void PRINT(int *,int);
void PRINT(int **, int);
int *a[L];
int main()
{
    int i, j, k;
    int *p[L] = {&i, &j, &k};
    //PRINT(a[0],L);
    //PRINT(a[0],L);
    scanf_s("%d", &i);
    PRINT(a, L);
    //PRINT(p,L);

    return 0;
}
void PRINT(int *s[], int n)
//void PRINT(int **s,int)
{
    for (int i = 0; i < n; i++)
        printf("%p", s[i]);
    //printf("%p",(*s)+4*i);
    printf("\n");
}
