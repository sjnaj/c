/*
 * @Author: fengsc
 * @Date: 2021-04-20 10:00:38
 * @LastEditTime: 2021-05-07 22:15:48
 */
/*#include<stdio.h>
#include<stdlib.h>
void func(int n,int *arr)
{
    int count=1;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    *(arr+n*i+j) =count++;
}

int main()
{
int n;scanf("%d",&n);
    int *arr;
    arr=(int*)malloc(n*n*sizeof(int));
    func(n,arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",*(arr+n*i+j));
        }
        printf("\n");
    }
    return 0;

}*/
/*#include<stdio.h>
int main()
{
    int n,l=1,m=1;scanf("%d",&n);
    int arr[n],len[n],k=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    for(int j=0;j<n;j++)
    {
         int temp=arr[j];
       for(int k=j+1;k<n;k++)
       {
           if(arr[k]==temp+1)
           { l++;temp+=1;}
           
       }
        len[k++]=l;l=1;
    }
    for(int i=0;i<k;i++)
    {
      if(len[i]>m)
        m=len[i];
    }
    printf("%d\n",m);
    return 0;
        
}*/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[80];int len,count=0;
    scanf("%[^\n]",s);
    len=strlen(s);
    while(len--)
    {
        if(s[len]>'A'&&s[len]<='Z'&&s[len]!='E'&&s[len]!='I'&&s[len]!='O'&&s[len]!='U')
            count++;
    }
    printf("%d",count);
    return 0;
}

