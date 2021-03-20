/*#include <stdio.h>//Fibonacci sequence
int main()
{
    int i,f[20]={1,1};
    for(i=2;i<20;i++)
    f[i]=f[i-1]+f[i-2];
    for(i=0;i<20;i++)
    {
        if(i%5==0)
        printf("\n");
        printf("%-10d",f[i]);
    }
    return 0;

}*/
/*#include <stdio.h>
int main(){
    int i, j;  //二维数组下标
    int sum = 0;  //当前科目的总成绩
    int average;  //总平均分
    int v[3];  //各科平均分
    int a[5][3];  //用来保存每个同学各科成绩的二维数组
    printf("Input score:\n");
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            scanf("%d", &a[j][i]);  //输入每个同学的各科成绩
            sum += a[j][i];  //计算当前科目的总成绩
        }
        v[i]=sum/5;  // 当前科目的平均分
        sum=0;
    }
    average = (v[0] + v[1] + v[2]) / 3;
    printf("Math: %d\nC Languag: %d\nEnglish: %d\n", v[0], v[1], v[2]);
    printf("Total: %d\n", average);
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a[2][3] = {{1,2,3}, {4,5,6}}, b[3][2];
    printf("array a:\n");
    for (int i = 0; i <2; i++)
    {
        for (int j = 0; j <3; j++)
        {
            b[j][i] = a[i][j];
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }
    printf("array b:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%-5d ", b[i][j]);
        printf("\n");
    }
    return 0;
}*/
/*#include <stdio.h>
int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {8, 9, 10, 11}}, max = 0, i, j, row, col;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
            row = i, col = j;
        }
    }
    printf("max element is a[%d][%d]:%d\n", i, j, max);
    return 0;
}*/
#include <stdio.h>
int main()
{
    char str[27]={0},c;//需要大于26，使后面的‘0’被识别从而输出字符串；
    int i;
    for(i=0,c=65; c<=90;i++,c++)
    {
        str[i] =c;
    }
    printf("%s\n",str);
    return 0;
}
