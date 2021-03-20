#include <stdio.h>
int main()
{
    /* char c;
    char d [10],e [10];
    gets(d);c=getchar();
    fgets(e,10,stdin);
    printf("%c\n%s\n%s",c,d,e);*/

    int a = 0, b = 0, d;
    int c;
    printf("%d %d",'A','a');
    scanf("a=%d", &a);
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("b=%d", &b);
    printf("a=%d, b=%d\n,c=%c(%d)\n", a, b, c, c);
    getchar();
    getchar();

    return 0;
}