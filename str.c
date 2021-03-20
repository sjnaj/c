#include <stdio.h>
#include <string.h>
int main()
{
    char str1[3][20],str[20];
    for(int i=0;i<3;i++)
    fgets(str1[i],20,stdin);
    printf("%s",str1[0]);
    if(strcmp(str1[0],str1[1])>0)
    strcpy(str,str1[0]);
    else
    strcpy(str,str1[1]);
    if(strcmp(str1[2],str)>0)
    strcpy(str,str1[2]);
    printf("the largest str is %s\n",str);
    return 0;
    

}