/*#include<stdio.h>

int n;   //定义全局变量n，记录输入天数 

int Taozi( int day ) //递归函数。 
{
	int num;
	if( day == n )
	{
		return 1; //递归终点。 
	}
	else
	{
		num = 2 * ( Taozi( day + 1 ) + day ); //递推公式 
	}	 
	return num; //返回num的值 
}
int main()
{
	int num; //此处num是局部变量，与递归函数中的num 意义不同 
	scanf("%d", &n);  //输入全局变量n的值 
	num = Taozi( 1 ); //因为是从第一天开始算，传入的参数值为 1。 
	if(num > 1)
	printf("The monkey got %d peaches in first day.\n", num);
	else
	printf("The monkey got %d peach in first day.\n", num);//等于1的情况
}*/
#include <stdio.h>
#include <stdlib.h>
double plus(int x) // 这是一个返回值为浮点数的函数，写在后面的话要进行函数申明。
{
	double sum = 0;
	if(x == 1)  // 递归终点
	{
		return 1;
	}
	else
	{
		if(x % 2 == 0)  //当为偶数项时，符号为正
			sum = 1.0 / x + plus(x - 1);
		else  //当为奇数项时，符号为负（首项除外）
			sum = -1.0 / x + plus(x -1);
	}
	return sum;
}
int main()
{
	double sum = 0;
	int n = 0;
	scanf("%d", &n);
	sum = plus(n);
	printf("%06lf\n", sum);
	return 0;
}

