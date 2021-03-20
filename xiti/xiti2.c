/*#include <stdio.h>//my answer
#include <stdlib.h>
int main()
{
    int year, month;
    printf("please input a time like 2020 01:\n");
    scanf("%d %d", &year, &month);
    if (year <= 0 || month <= 0 || month >= 12)
        printf("error\n");
    return(1);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        if (month == 2)
        {
            printf("it has 29 days\n");
            return(2);
        }

        else
        {
        }
    else if (month == 2)

    {
        printf("it has 28 days\n");
        exit(3);
    }

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("it has 31 day\n");
        break;
    default:
        printf("it has 30 days\n");
    }

    return 0;
}*/
#include <stdio.h>//standard answer
#include <stdlib.h>

void main(){ 
    int year, month, days;
    
    printf("输入年份：");
    scanf("%d",&year);
    printf("输入月份："); 
    scanf("%d", &month);

    switch(month){
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10: 
        case 12:
            days=31;
            break; 
        case 4: 
        case 6: 
        case 9: 
        case 11:
            days=30;
            break; 
        case 2:
            // 判断闰年
            if(year%4==0 && year%100!=0 || year%400==0)
                days=29; 
            else
                days=28; 
            break; 
        default:
            printf("月份输入错误！\n");
            exit(1);
            break; 
    } 
    printf("天数：%d\n", days); 
}
/*#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, disc, x1, x2, realpart, imagpart;
    printf("please input a equation like ax^2+bx+c=0\n");
    scanf("%lfx^2%lfx%lf=0", &a, &b, &c);
    printf("the equation ");
    if (fabs(a) <= 1e-6)
    {
        printf("is not a quadratic\n");
    }
    else
    {
        disc = (b * b - 4 * a * c);

        if (fabs(disc) <= 1e-6)
            printf("two equal roots:x1=x2=%8.4f\n", -b / (2 * a));
        else if (disc > 1e-6)
        {
            x1 = (-b + sqrt(disc)) / (2 * a);
            x2 = (-b - sqrt(disc)) / (2 * a);
            printf("has distinct real roots ： x1=%8.4f,x2=%8.4f\n", x1, x2);
        }
        else if (disc < 1e-6)
        {
            realpart = -b / (2 * a);
            imagpart = sqrt(-disc);
            printf("has two complex roots:x1=%8.4f+%8.4fi,x2=%8.4f-%8.4fi\n", realpart, imagpart, realpart, imagpart);
        }
    }
    printf("the disc is %8.4f\n", disc);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
int main()
{

    bool a, b, c, d;
    int e, f;
    a = 3 > 4, b = 4 > 3, c = e = 2, d = f = 0;
    printf("%d %d %d %d\n", a, b, c, d);
    if (a == false && b == true)
        printf("yes");
    return 0;
}
#include <stdio.h>
int main()
{
    int grade;
    printf("please input a grade:\n");
    scanf("%d", &grade);
    switch ((int)(grade / 10))
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("%d is rank E\n", grade);
        break;
    case 6:
        printf("%d is rank D\n", grade);
        break;
    case 7:
        printf("%d is rank C\n", grade);
        break;
    case 8:
        printf("%d is rank B\n", grade);
        break;
    case 9:
    case 10:
        printf("%d is rank A\n", grade);
        break;
    }
    return 0;
}
*/
