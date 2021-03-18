#include <stdio.h> 
//#include <string.h>
#include "f_gets.h"
//char *s_gets(char *st, int n);
#define MAXTITL 41 /* 书名的最大长度 + 1 */
#define MAXAUTL 31 /* 作者姓名的最大长度 + 1*/
struct book
{ /* 结构模版：标记是 book */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}; /* 结构模版结束 */
int main(void)
{
    struct book library; /* 把 library 声明为一个 book 类型的变量 */
    printf("Please enter the book title.\n");
    f_gets(library.title, MAXTITL); /* 访问title部分*/
    printf("Now enter the author.\n");
    f_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");
    return 0;
}