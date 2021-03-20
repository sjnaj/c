/*#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)
int main()
{
    int a, b;
    scanf("%d,%d",&a,&b);
    printf("the max is %d\n]",max(a,b));
    return 0;
}*/
#include <stdio.h>
#define SQ(y) ((y)*(y))
int main(){
    int i=1;
    while(i<=5){
        printf("%d^2 = %d\n", i, SQ(i++));
    }
    return 0;
}