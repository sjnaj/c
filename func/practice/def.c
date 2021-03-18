/*#include <stdio.h>
//不同的平台下引入不同的头文件
#if _WIN32  //识别windows平台
#include <windows.h>
#elif __linux__//识别linux平台
#include <unistd.h>
#endif
int main() {
    //不同的平台下调用不同的函数
    #if _WIN32  //识别windows平台
    Sleep(5000);
    #elif __linux__  //识别linux平台
    sleep(5);
    #endif
    puts("http://c.biancheng.net/");
    return 0;
}*/
/*#include <stdio.h>
int main() {
printf("Date : %s\n", __DATE__);
printf("Time : %s\n", __TIME__);
printf("File : %s\n", __FILE__);
printf("Line : %d\n", __LINE__);
return 0;
}*/
#include <stdio.h>
int main(){
    #if WIN32
        system("color 0c");
        printf("http://c.biancheng.net\n");
    #elif linux
        printf("\e[33mhttp://c.biancheng.net\e[0m\n");
    #else
        printf("http://c.biancheng.net\n");
    #endif
    return 0;
}
/*#if linux
#error This programme cannot compile at Windows Platform
#endif
#include <stdio.h>
int main()
{
    printf("lalala");
    return 0;}*/