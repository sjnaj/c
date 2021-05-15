/*
 * @Author: fengsc
 * @Date: 2021-04-20 10:00:38
 * @LastEditTime: 2021-05-10 17:49:40
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
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    double sum=1;
    for(int i=1;i<=n;i++)
    sum*=i;
    printf("%.f",sum);
    return 0;
}