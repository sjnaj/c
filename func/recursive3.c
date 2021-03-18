/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void reverse(char *str, int start, int end) 
{
	int t;
	for(t = 0; str[t] != '\0'; t++); //计算字符串的长度
	//也可以 t = strlen(str);
	char temp; //中间变量
	if(end > t) 
	//当给的end超过字符串长度时，end直接变为t-1，end是下标所以减一
		end = t - 1;
	if(end <= start)
	{
		return; //递归终点
	}
	else
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;  //交换字符
		reverse(str, start + 1, end - 1); //递归调用
	}
}
int main( )
{	char str[100];
	int start, end;
	fgets(str,100,stdin);//注意末尾的换行符
	scanf("%d %d", &start, &end);
	reverse( str, start, end );
	printf("%s", str);
	return 0;
}*/
#include <stdio.h>
#include <string.h>
char arr[10000] = {0};
int palindrome(int low, int high, char *str, int length) // n是代表字符串长度的参数
{
	if (length == 1 || length == 0)//(length<=1)
		return 1;
	else
	{
		if (arr[low] == arr[high]) //判断对应位置的字符是否相同
		{
			return (palindrome(low + 1, high - 1, str, length - 2));
			//这里返回的是下一次调用的返回值，这样只有当所有对应字符相同时才返回 1。
		}
		else
			return 0;
	}
}
int main()
{
	int length, low = 0, high;
	fgets(arr, 10000, stdin);
	length = strlen(arr);
	high = length - 2; //注意fgets
	//if (arr[length - 1] == '\n')
	//	arr[length - 1] = '\0';//对此程序无影响，但最好加上
	if (palindrome(low, high, arr, length))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
