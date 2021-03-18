#include <stdio.h>
//int READ( int, int，int[*][*]);//变长数组声明方式,注意顺序和形式
void READ(int row, int col, int mat[row][col])
//void READ(int **p, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printf("please input the number of row%d:\n", i);
        for (int j = 0; j < col; j++)
            //scanf("%d", (int *)p + col * i + j);
            scanf("%d", &mat[i][j]);
    }
}
int main()
{
    int row1, row2, col1, col2;
    printf("please input the row and col of first matrix like:4 3:\n");
    scanf("%d %d", &row1, &col1);
    int mat1[row1][col1];
    READ(row1, col1, mat1);
    //READ((int **)mat1, row1, col1);
    printf("please input the row and col of second matrix like:3 4:\n");
    scanf("%d %d", &row2, &col2);
    int mat2[row2][col2], mat3[row1][col2];
    for (int i = 0; i < row1; i++) //初始化变长数组，不能直接初始化
    {
        for (int j = 0; j < col2; j++)
            mat3[i][j] = 0;
    }
    READ(row2, col2, mat2);
    //READ((int **)mat2, row2, col2);
    if (col1 == row2)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                for (int k = 0; k < col1; k++)
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    else
    {
        printf("col1 should be equal to row2\n");
        return 1;
    }
    printf("results are as follows:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
            printf("%-5d", mat3[i][j]);
        printf("\n");
    }
    return 0;
}