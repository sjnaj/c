/*#include <stdio.h>
int main()
{
    char a,b,c,d,e;
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    a=a+4,b=b+4,c=c+4,d=d+4,e=e+4;
    printf("%c%c%c%c%c\n",a,b,c,d,e);
    putchar(a),putchar(b),putchar(c),putchar(d),putchar(e);
    return 0;

}*/
/*#include <stdio.h>
int main()
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;char c;
    printf("please input :\n");
    for(i; (c=getchar()) != '\n';i++)
    {
        
        
        if (c >= '0' && c <= '9')
            j++;
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            k++;
        else if (c == ' ')
            l++;
        else
            m++;
    } 

    printf("total has %d characters\nhas %d digits\nhas %d letters\nhas %d space\nhas %d other characters\n", i, j, k, l, m);
    return 0;
}*/
/*
#include <stdio.h>

int main(){
    char c;  //用户输入的字符 
    int letters=0,  // 字母数目 
        space=0,  // 空格数目 
        digit=0,  // 整数数目 
        others=0;  // 其他字符数目

    printf("输入一些字符：");
    while((c=getchar())!='\n'){  // 每次读取一个字符，回车时结束
        if(c>='a'&&c<='z'||c>='A'&&c<='Z')
            letters++;
        else if(c==' ')
            space++;
        else if(c>='0'&&c<='9')
            digit++;
        else
            others++;
    }
    
    printf("\n统计结果:\n英文字母=%d\n空格=%d\n整数=%d\n其他字符=%d\n\n", letters, space, digit, others);

    return 0;
}*/
#if 0

// 0#include <stdio.h>
int main()
{
    int i, j;
    float money;
    printf("how much\n");
    scanf("%f", &money);
    /* for (i = 0; i <= money / 0.05; i++)
    {
        for (j = 0; j <= (money - 0.05 * i) / 0.02; j++)
            printf("%4.2f元可分为%d个五分%d个二分%d个一分\n", money, i, j, (int)(100 * money - 5 * i - 2 * j));
    }*/
    for (i = 20; i >= 0; i--)
    {
         for(j=(money*100-5*i)/2; j>=0; j--)
          {
            printf("%4.2f元可分为%d个五分%d个二分%d个一分\n", money, i, j, (int)(100 * money - 5 * i - 2 * j));
    }
    }

    return 0;
}
#endif 
#include <stdio.h>
int main()
{
    int i=1, j;
    j=i++;printf("%d %d\n",i,j);
    return 0;
    
}