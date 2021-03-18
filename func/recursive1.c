#include <stdio.h>
long factorial(int);
long sum(int);
int main()
{
    int n;
    scanf("%d", &n);
    printf("从1到%d的阶乘之和为%ld\n", n, sum(n));
    return 0;
}
long factorial(int n)
{
    long result = 1;
    for (; n >= 1; n--)
        result *= n;
    return result;
}
long sum(int n)
{
    long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += factorial(i);
    return sum;
}
