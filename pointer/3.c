/*#include <stdio.h>
int main(){
    char *str[3] = {
        "c.biancheng.net",
        "C语言中文网",
        "C Language"
    };
    printf("%c\n%d\n%c\n%d\n", str[0][0], *str[1], *str[2],'c');
    return 0;
}*/
/*#include <stdio.h>
int main(){
    int a[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    //int(*p)[4];
    int i,j;
    //p=a;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++) printf("%2d  ",*(*(a+i)+j));
        printf("\n");
    }
    return 0;
}*/
#include <stdio.h>
//返回两个数中较大的一个
int max(int a, int b){
    return a>b ? a : b;
}
int main(){
    int x, y, maxval;
    //定义函数指针
    int (*pmax)(int, int) = max;  //也可以写作int (*pmax)(int a, int b)
    printf("Input two numbers:");
    scanf("%d %d", &x, &y);
    maxval = (*pmax)(x, y);
    printf("Max value: %d\n", maxval);
    return 0;
}