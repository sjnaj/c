/*
 *                        .::::.
 *                      .::::::::.
 *                     :::::::::::
 *                  ..:::::::::::'
 *               '::::::::::::'
 *                 .::::::::::
 *            '::::::::::::::..
 *                 ..::::::::::::.
 *               ``::::::::::::::::
 *                ::::``:::::::::'        .:::.
 *               ::::'   ':::::'       .::::::::.
 *             .::::'      ::::     .:::::::'::::.
 *            .:::'       :::::  .:::::::::' ':::::.
 *           .::'        :::::.:::::::::'      ':::::.
 *          .::'         ::::::::::::::'         ``::::.
 *      ...:::           ::::::::::::'              ``::.
 *     ````':.          ':::::::::'                  ::::..
 *                        '.:::::'                    ':'````..
 */

/*
 * @Author: fengsc
 * @Date: 2021-03-13 21:06:45
 * @LastEditTime: 2021-03-16 00:25:24
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
    char name[MAX]; //姓名 //!不能用字符指针，未初始化会报错，初始化后只读，不能写入
    int num;        //学号
    int age;        //年龄
    char group;     //所在小组
    float score;    //成绩
} stus[SUM], *ps = stus;
 
int main()
{
    printf("please input a name:\nPress [enter] at the start of a line to stop.\n");
    int count = 0;
    for (int i = 0; i < SUM && f_gets((stus+i)->name, MAX) != NULL && stus[i].name[0] != '\0'; i++, count++)
    {
        printf("the num is:\n");
        scanf("%d", &(stus+i)->num);
        clean();
        printf("the age is:\n");
        scanf("%d", &stus[i].age);
        clean();
        printf("the group is:(between 'A' and 'F'\n");
        scanf("%c", &stus[i].group);
        clean();
        printf("the score is:\n");
        scanf("%f", &stus[i].score);
        clean();
        printf("please input next name:\n");
    }
    printf("Name\tNum\tAge\tGroup\tScore\t\n");
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
    ver = fgets(st, n, stdin);//st需要有写入权限
    if (ver)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL,
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; //处理输入行中剩余的字符
    }
    return ver; //返回字符串指针
}
