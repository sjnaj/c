/*
 *                                |~~~~~~~|
 *                                |       |
 *                                |       |
 *                                |       |
 *                                |       |
 *                                |       |
 *     |~.\\\_\~~~~~~~~~~~~~~xx~~~         ~~~~~~~~~~~~~~~~~~~~~/_//;~|
 *     |  \  o \_         ,XXXXX),                         _..-~ o /  |
 *     |    ~~\  ~-.     XXXXX`)))),                 _.--~~   .-~~~   |
 *      ~~~~~~~`\   ~\~~~XXX' _/ ';))     |~~~~~~..-~     _.-~ ~~~~~~~
 *               `\   ~~--`_\~\, ;;;\)__.---.~~~      _.-~
 *                 ~-.       `:;;/;; \          _..-~~
 *                    ~-._      `''        /-~-~
 *                        `\              /  /
 *                          |         ,   | |
 *                           |  '        /  |
 *                            \/;          |
 *                             ;;          |
 *                             `;   .       |
 *                             |~~~-----.....|
 *                            | \             \
 *                           | /\~~--...__    |
 *                           (|  `\       __-\|
 *                           ||    \_   /~    |
 *                           |)     \~-'      |
 *                            |      | \      '
 *                            |      |  \    :
 *                             \     |  |    |
 *                              |    )  (    )
 *                               \  /;  /\  |
 *                               |    |/   |
 *                               |    |   |
 *                                \  .'  ||
 *                                |  |  | |
 *                                (  | |  |
 *                                |   \ \ |
 *                                || o `.)|
 *                                |`\\) |
 *                                |       |
 *                                |       |
 */
/*
 * @Author: fengsc
 * @Date: 2021-03-13 21:06:45
 * @LastEditTime: 2021-03-16 00:25:24
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "f_gets.h"
char *f_gets(char *st, int n);
void clean(void);
#define SUM 20
#define MAX 10
struct stu
{
    char name[MAX]; //姓名 //!不能用字符指针，未初始化会报错，初始化后只读，不能写入
    int num;        //学号
    int age;        //年龄
    char group;     //所在小组
    float score;    //成绩
} stus[SUM], stus1[SUM], swap, *ps = stus, *ps1 = stus1;
int main()
{
    printf("please input a name:\nPress [enter] at the start of a line to stop.\n");
    int count = 0;float temp=0,sum=0;
    for (int i = 0; i < SUM && f_gets((ps + i)->name, MAX) != NULL && ps[i].name[0] != '\0'; i++, count++)
    {
        printf("the num is:\n");
        scanf("%d", &(ps + i)->num);
        getchar();
        printf("the age is:\n");
        scanf("%d", &ps[i].age);
        getchar();
        printf("the group is:(between 'A' and 'F':\n");
        scanf("%c", &ps[i].group);
        getchar();
        for (int i = 0; i < 5; i++)
        {
            if (ps[i].group < 'A' || ps[i].group > 'F')
            {
                printf("Please input a letter between 'A' and 'F':\n");
                scanf("%c", &ps[i].group);
                getchar();
            }
            else
                break;
        }
        printf("the score is:\n");
        scanf("%f", &ps[i].score);
        getchar();
        printf("please input next name:\n");
    }
    /*printf("Name\tNum\tAge\tGroup\tScore\t\n");//*普通输出(1)
    for (int i = 0; i < count; ps++, i++)
    {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
    }return 0;
    */

    FILE *fp;
    if ((fp = fopen("/home/fengsc/Desktop/c/file/student", "w+")) == NULL) //打开文件
    {
        printf("Fail to open file!\n");
        exit(0); //退出程序
    }
    /*fwrite(ps, sizeof(struct stu), count, fp);//*读取数据块&&与文件交互(2)
    rewind(fp);
    fread(stus1, sizeof(struct stu), count, fp);
    rewind(fp);
    fputs("Name\tNum\tAge\tGroup\tScore\t\n", fp);
    fclose(fp);
    printf("Name\tNum\tAge\tGroup\tScore\t\n");
    for (int i = 0; i < count; ps++, i++)//*输出内容与文件内容不一致，因为文件内容没有格式化
    {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
    }
    return 0;
}*/
for (int i = 0; i < count - 1; i++)//Babble Sort
    {
        for (int j = i + 1; j < count; j++)
        {
            if ((ps[i].group) > (ps[j].group))
            {
                swap = ps[i];
                ps[i] = ps[j];
                ps[j] = swap;
            }
        }
    }
    for (int i = 0; i <count; i++)//求最高分和平均分
    {
        if(ps[i].score>temp)
        temp =ps[i].score;
        sum+=ps[i].score;
    }
    fputs("Name\tNum   age   Group   Score\n", fp);
    for (int i = 0; i < count; i++, ps++) //*格式化读取数据&&与文件交互(3)
    {
        fprintf(fp, "%-8s%-6d%-6d%-8c%-.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score); //!使数据左对齐
    }
    fprintf(fp,"the highest score is %.2f \nthe average score is %.2f \n",temp,(float)sum/count);
    fseek(fp, 31, SEEK_SET); //*移动位置指针到第二行开头，第一行字符串储存长度是32(光标悬浮可直接显示），但这里不用考虑\0,
    for (int i = 0; i < count; i++, ps1++)
    {
        fscanf(fp, "%s%d%d %c%f\n", ps1->name, &ps1->num, &ps1->age, &ps1->group, &ps1->score); //*%s对应字符串指针，不用&
    }                                                                                           //!读取除字符以外的类型时会自动跳过数据间的间隔，格式可以连续书写，但%c前需要加空格（即读取下一个非空字符）
    //rewind(fp);fputs("Name\tNum\tAge\tGroup\tScore\t\n", fp);//!以此方式写入会覆盖第一行，只能修改或附加，不能插入
    printf("\e[1;40;31mName\tNum\tAge\tGroup\tScore\n\e[0m");
    ps1 = stus1; //!指针从头读写时要“归零”，切记
    for (int i = 0; i < count; i++, ps1++) //
    {
        printf("\e[1;40;35m%s\t%d\t%d\t%c\t%.1f\n\e[0m", ps1->name, ps1->num, ps1->age, ps1->group, ps1->score);
    }      
     printf("the highest score is %.2f \nthe average score is %.2f \n",temp,sum/count);     //可惜前景色不能用变量。
    fclose(fp); //关闭文件
    return 0;
}
char *f_gets(char *st, int n) //*自定义字符串输入函数
{
    char *ver;
    char *find;
    ver = fgets(st, n, stdin); //st需要有写入权限
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
