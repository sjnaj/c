#include <stdio.h>
#include <string.h>
#define SIZE 20
#define NUM 10
int count = 0;
char p[NUM][SIZE] = {0};
int INPUT(char *, int);
int main(int argc, char **argv)
{
    printf("please input some str,empty line to quit:\n");
    for (int i = 0; INPUT(p[i], SIZE) == 1; i++)
    {
        if (argc > 1)
        {
            switch (argv[1][1])
            {
            case 'u':
            {
                for (int j = 0; j < strlen(p[i]); j++)
                {
                    if (p[i][j] >= 'a' && p[i][j] <= 'z')
                        p[i][j] = p[i][j] - 32;
                    else
                        continue;
                };
            }
            break;
            case 'l':
            {
                for (int j = 0; j < strlen(p[i]); j++)
                {
                    if (p[i][j] >= 'A' && p[i][j] <= 'Z')
                        p[i][j] = p[i][j] + 32;
                    else
                        continue;
                }
            }
            break;
            case 'p':
                break;
            //case :
            //   break;
            default:
                puts("please correct your command");
                return 0;
                break;
                ;
            }
        }
    }
    for (int i = 0; i < count; i++)
        puts(p[i]);
    return 0;
}
int INPUT(char *str, int S)
{
    int k = 0;
    fgets(str, 10, stdin); //用scanf则不能以空行退出
    if (str[0] == '\n')
        return 0;
    while ((str[k] >= 'A' && str[k] <= 'Z') || (str[k] >= 'a' && str[k] <= 'z') && k < strlen(str))
        k++;
    if (str[k] == '\n')
        str[k] = '\0'; //去除末尾换行符
    else if (str[k] == '\0')
    {
        while (getchar() != '\n')
            continue;
    }
    else
        return 0;
    count++;
    return 1;
}