/*#include <stdio.h>
int main(){
    int a[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    int(*p)[4]=a;
    int i,j;
   // p=a;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++) printf("%2d  ",*(*(p+i)+j));
        printf("\n");
    }
    return 0;
}*/

/*#include "stdio.h"
//#include "stdbool.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
 
void getMemory(char **p)
{
	//char *p = str
	*p = (char *)malloc(100);
	strcpy(*p,"hello world");
	printf("p:%s\n",*p);
}
 
int main()
{
	printf("Enter main...\n");
	char *str = NULL;
	printf("str:%p\n",str);
	getMemory(&str);
	
	printf("%s\n",str);
	
	if(str != NULL)
		free(str);
	
    return (0);
}
*/
#include <stdio.h>
#include <string.h>
//#include "f_gets.h"
char *f_gets(char *st, int n);
void clean(void);
#define SUM 50
#define MAX 10
struct stu
{
	char *name;	 //姓名
	int num;	 //学号
	int age;	 //年龄
	char group;	 //所在小组
	float score; //成绩
} stus[SUM] = {[0 ... 12] = {"lala", 12, 23, 'a', 23}}, *ps = stus;
/* {"Zhou ping", 5, 18, 'C', 145.0},
    {"Zhang ping", 4, 19, 'A', 130.5},
    {"Liu fang", 1, 18, 'A', 148.5},
    {"Cheng ling", 2, 17, 'F', 139.0},
    {"Wang ming", 3, 17, 'B', 144.5}}*/
int main()
{
	printf("please input a name:\nPress [enter] at the start of a line to stop.\n");
	int count = 0;
	for (int i = 0; i < SUM && f_gets(stus[i].name, MAX) != NULL && stus[i].name[0] != '\0'; i++, count++)
	{
		printf("the num is:\n");
		scanf("%d", &stus[i].num);
		clean();
		printf("the age is:\n");
		scanf("%d", &stus[i].age);
		clean();
		printf("the group is:(between 'A' and 'F'\n");
		scanf("%c", &stus[i].group);
		clean();
		printf("the score is:\n");
		scanf("%e", &stus[i].score);
		clean();
		printf("please input next name:\n");
	}
	printf("Name\tNum\tAge\tGroup\tScore\t\n");
	ps = stus; //重新指向数组开头
	for (int i = 0; i < count; ps++, i++)
	{
		printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
	}
	return 0;
}
void clean(void)
{
	while (getchar() != '\n')
		continue;
}
char *f_gets(char *st, int n)
{
	char *ver;
	char *find;
	ver = fgets(st, n, stdin);
	if (ver)
	{
		find = strchr(st, '\n'); // 查找换行符
		if (find)				 // 如果地址不是 NULL,
			*find = '\0';		 // 在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue; //处理输入行中剩余的字符
	}
	return ver; //返回字符串指针
}
