/*
 * @Author: fengsc
 * @Date: 2021-05-01 16:35:58
 * @LastEditTime: 2021-05-01 19:42:51
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int top = -1, a[100];
int func1(char *, int, int);
void push(int);
void pop(void);
int main()
{
    int n1, n2, base1, base2, temp;
    char num[100];
    printf("the num:\n");
    scanf("%s", num);
    printf("the oldbase:\n");
    scanf("%d", &base1);
    printf("the newbase:\n");
    scanf("%d", &base2);
    n2 = func1(num, (int)strlen(num), base1);
    while (n2 / base2)
    {
        push(n2 % base2);
        n2 /= base2;
    }
    push(n2);
    printf("the result is:\n");
    while (top != -1)
        pop();
    printf("\n");
}
int func1(char *a, int count, int base1)
{
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        if (a[i] >= 48 && a[i] <= 57)

            result += (a[i] - '0') * pow(base1, count - i - 1);
        else
            result += (a[i] - 55) * pow(base1, count - i - 1);
    }
    return result;
}
void push(int n)
{
    a[++top] = n;
}
void pop(void)
{
    if (a[top] < 10)
        printf("%d", a[top--]);
    else
        printf("%c", a[top--] + 55); //65-10
}
