/*
 * @Author: fengsc
 * @Date: 2021-03-22 13:34:36
 * @LastEditTime: 2021-03-24 17:14:48
 */
/*#include <stdio.h>
#include <stdlib.h>
#define N 100
int main()
{
    FILE *fp, *fp1;
    char c;
    char str[N + 1];
    //判断文件是否打开失败
    if ((fp = fopen("./file/txt", "r")) == NULL || (fp1 = fopen("./file/txt1", "w+")) == NULL)
    {
        puts("Fail to open file!");
        exit(0);
    }
    //循环读取文件的每一行数据
    while ((c = fgetc(fp)) != EOF)
    {
        fputc(c, fp1);
        //printf("%c", c);
    }
    rewind(fp1); //!文件指针已经到了文件末尾，需要将指针移到开头
    while ((c = fgetc(fp1)) != EOF)
        printf("%c", c);
    //操作结束后关闭文件
    fclose(fp);
    fclose(fp1);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#define N 2
struct stu
{
    char name[10]; //姓名
    int num;       //学号
    int age;       //年龄
    float score;   //成绩
} boya[N], boyb[N], *pa, *pb;
int main()
{
    FILE *fp;
    int i;
    pa = boya;
    pb = boyb;
    if ((fp = fopen("./txt2", "wb+")) == NULL)
    {
        puts("Fail to open file!");
        exit(0);
    }
    //从键盘输入数据
    printf("Input data:\n");
    for (i = 0; i < N; i++, pa++)
    {
        scanf("%s %d %d %.1f", pa->name, &pa->num, &pa->age, &pa->score);
    }
    //将数组 boya 的数据写入文件
    fwrite(boya, sizeof(struct stu), N, fp);
    //将文件指针重置到文件开头
    rewind(fp);
    //从文件读取数据并保存到数据 boyb
    fread(boyb, sizeof(struct stu), N, fp);
    //输出数组 boyb 中的数据
    for (i = 0; i < N; i++, pb++)
    {
        printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
    }
    fclose(fp);
    return 0;
}