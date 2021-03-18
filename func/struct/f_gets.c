#include "f_gets.h"
char *f_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // 查找换行符
		if (find)				 // 如果地址不是 NULL,
			*find = '\0';		 // 在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue; //处理输入行中剩余的字符
	}
	return ret_val;//返回字符串指针
}
