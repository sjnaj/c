/*
 * @Author: fengsc
 * @Date: 2021-03-25 12:36:22
 * @LastEditTime: 2021-03-26 12:52:39
 */
#include <stdio.h>
int main()
/*{
    int num[10]={1,2,4,5,8,10,20,25,40,50};float temp;
    for(int i=0;i<10;i++)
    {
        temp=1/num[i];
        if(temp>1/num[i])
        printf("%f is greater than %f",temp,1/num[i]);
         else if(temp<1/num[i])
         printf("%f is less than %f",temp,1/num[i]);
         else printf("%f is equal to %f",temp,1/num[i]);
    }
return 0;

    }*/
{
    float f;
    scanf("%f", &f);
    if (f < -459.67)
        printf("Invalid");
    return 0;
}
