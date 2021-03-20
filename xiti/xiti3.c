/*#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, i, j, k, half;
    printf("please input a odd number as the row:\n");
    scanf("%d", &row);
    if(row %2==0)
    {printf("error: invalid");
    exit(0);}
    half = (row + 1) / 2;
    for (i = 1; i <= row; i++)
    {
        if (i <= half)
        {
            for (j = 1; j <= half - i; j++)
            {
                printf(" ");
            }
            for (k = 1; k <= 2 * i - 1; k++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            for (j = 1; j <= i - half; j++)
            {
                printf(" ");
            }
            for (k = 1; k <= 2 * (2 * half - i) - 1; k++)//关键点：上下部分*数量差异
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}*/
/*
#include <stdio.h>
int main(){
	int N;//N=(row+1)/2
	printf("输入行数");
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N-i;j++){
			printf(" ");
		}
		for(int k=1;k<=2*i-1;k++){
			printf("*");
		}
		printf("\n");
	}
	for(int i=N-1;i>0;i--){//关键点：将下部行数转化为顺序相反的上部行数
		for(int j=N-i;j>0;j--){//上下部分内层for循环同义，遍历顺序相反
			printf(" ");
		}
		for(int k=2*i-1;k>0;k--){
			printf("*");
		}
		printf("\n");
	}
}*/
#include <stdio.h>
int main()
{
    int a,b,c=0;
    scanf("%d",&a);
    while(a>0){
        b=a%10;
        a=(a-b)/10;
        c=10*c+b;

    }
    printf("%d",c);
    return 0;
}