/*
 * @Author: fengsc
 * @Date: 2021-05-14 23:01:05
 * @LastEditTime: 2021-05-15 10:51:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int row, col; //行，列
    int ele;      //元素
} triple;
typedef struct
{
    triple data[20]; //三元组
    int n, m, num;   //长，宽，非零元素数量
    int index[20];   //首个非零元素位置
} stu;
int main()
{
    stu matrix;
    matrix.num = 0;
    scanf("%d%d", &matrix.m, &matrix.n);
    int temp, i, j, flag, value, l;
    for (i = 1; i <= matrix.m; i++)
    {
        flag = 1;
        matrix.index[i] = matrix.num; // *首个非零元素位置初始位置是行首
        for (j = 1; j <= matrix.n; j++)
        {
            scanf("%d", &temp);
            if (temp)
            {
                matrix.data[matrix.num].row = i;
                matrix.data[matrix.num].col = j;
                matrix.data[matrix.num++].ele = temp;

                if (flag)
                {
                    matrix.index[i] = matrix.num - 1;
                    flag = 0;
                }
            }
        }
    }
    matrix.index[i] = matrix.num;//最后一行行首
    for (i = 1; i <= matrix.m; i++)
    {

        for (j = 1; j <= matrix.n; j++)
        {
            value = 1;
            for (int k = matrix.index[i]; k < matrix.index[i + 1]; k++) //!重点:分布是连续的,之间的元素就是本行的非零元素
            {
                if (matrix.data[k].row == i && matrix.data[k].col == j)
                {
                    printf("%d ", matrix.data[k].ele);
                    value = 0;
                    break;
                }
            }
            if (value)
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
