/*
 * @Author: fengsc
 * @Date: 2021-03-20 22:19:39
 * @LastEditTime: 2021-03-20 22:50:43
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double *ptd;//!指针都是char类型；
    int max, number,i=0;
    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    ptd = malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    } /* ptd 现在指向有max个元素的数组 */
    puts("Enter the values (q to quit):");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
        ++i;
    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; i++)
    {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)
            putchar('\n');
    }
    puts("Done.");
    free(ptd);
    return 0;
}
