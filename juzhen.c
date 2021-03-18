#include <stdio.h>

int main()
{
    int a1=1,a2=2,a3=3,b1=4,b2=5,b3=6,c1=7,c2=8,c3=9;
    double d=1;
    printf("%-6d %-6d %-6d\n",a1,a2,a3);
    printf("%-6d %-6d %-6d\n",b1,b2,b3);
    printf("%-6d %-6d %-6d\n",c1,c2,c3);
    printf("%20.10f %p",d,d);
    return 0;

}