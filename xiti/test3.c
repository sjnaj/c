/*
 * @Author: fengsc
 * @Date: 2021-03-07 13:48:24
 * @LastEditTime: 2021-04-02 20:02:50
 */
/*#include <stdio.h>
int prime(int num)
{
    int n;
    if (num == 2 || num == 3)
        return 1;
    for (int i = 2; i <= num / 2; i++)
    {
        n = num % i;
        if (n == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a, b, length = 0;
    scanf("%d%d", &a, &b);
    int num[1000] = {0};
    if (a >= b)
    {
        printf("error\n");
        return 0;
    }
    for (int i = 0; i < b - a - 1; i++)
    {
        if (prime(a + i + 1))
        {
            num[length] = a + i + 1;
            length++;
        }
    }
    if (length == 0)
    {
        printf("error\n");
        return 0;
    }
    for (int i = 0, temp = 0; i < length - 1; i++)
    {
        if (num[i] > num[i + 1])
        {
            temp = num[i + 1];
            num[i + 1] = num[i];
            num[i] = temp;
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}*/
