/*#include <stdio.h>
int main()
{
    int a[10], i, j,k;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);//输入
    for (j = 0; j < 9; j++)//一般算法，需要n-1轮比较
    {
        for (i = 0; i < 9; i++)//注意i+1的范围，否则会越界
        {
            if (a[i] > a[i + 1])
            {
                k=a[i+1];
                a[i+1]=a[i];
                a[i]=k;//进行数值交换
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);

    }
    printf("\n");
    return 0;
}*/
/*#include <stdio.h>
int main(){
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int i, j, temp, isSorted;
   
    //优化算法：最多进行 n-1 轮比较
    for(i=0; i<10-1; i++){
        isSorted = 1;  //假设剩下的元素已经排序好了
        for(j=0; j<10-1-i; j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                isSorted = 0;  //一旦需要交换数组元素，就说明剩下的元素没有排序好
            }
        }
        if(isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
    }
    for(i=0; i<10; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
   
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    //srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {

        printf("%ld\n", 
    }
    return 0;
}