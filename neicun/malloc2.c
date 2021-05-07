/*
 *           佛曰:  
 *                   写字楼里写字间，写字间里程序员；  
 *                   程序人员写程序，又拿程序换酒钱。  
 *                   酒醒只在网上坐，酒醉还来网下眠；  
 *                   酒醉酒醒日复日，网上网下年复年。  
 *                   但愿老死电脑间，不愿鞠躬老板前；  
 *                   奔驰宝马贵者趣，公交自行程序员。  
 *                   别人笑我忒疯癫，我笑自己命太贱；  
 *                   不见满街漂亮妹，哪个归得程序员？
 * @Author: fengsc
 * @Date: 2021-03-21 10:47:42
 * @LastEditTime: 2021-03-21 13:55:51
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main(void)
{
    int sum;
    char *words[sum]; //, *word;
    //word=malloc(MAX);
    puts("How many words do you wish to enter?");
    scanf("%d", &sum);
    printf("Enter %d words now:", sum);
    for (int i = 0; i < sum; i++)
    {
        words[i] = (char *)malloc(MAX * sizeof(char));
        if (words[i] == NULL)
        {
            puts("Memory allocation failed");
            exit(1);
        }
        scanf("%s", words[i]);
    }
    puts("Here are your words:");
    for (int i = 0; i < sum; i++)
    {
        printf("%s\t", words[i]);
        free(words[i]);//!注意释放动态内存
    }
    printf("\n");
    return 0;
}
