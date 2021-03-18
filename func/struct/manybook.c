#include <stdio.h>
#include <string.h>
#include "f_gets.h"//弥补了scanf()函数遇到空格和换行符就结束 读取的问题
#define MAXTITL 40
#define MAXAUTL 40 
#define MAXBKS 100/* 书籍的最大数量 */
struct book
{ /* 简历 book 模板 */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(void)
{
    struct book library[MAXBKS]; /* book 类型结构的数组 */
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && f_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        f_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);//将count++整合在这里
        while (getchar() != '\n')
            continue; /* 清理输入行*/
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
}