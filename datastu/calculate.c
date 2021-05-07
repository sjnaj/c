/*
 * @Author: fengsc
 * @Date: 2021-05-01 20:11:52
 * @LastEditTime: 2021-05-01 20:12:12
 */
#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false = 0,
    true = 1
} bool;
#define MAXSIZE 50
// 字符栈
typedef struct
{
    char data[MAXSIZE];
    int top;
} Stack;

void InitStack(Stack **s)
{
    *s = (Stack *)malloc(sizeof(Stack));
    (*s)->top = -1;
}

bool Push(Stack *s, char e)
{
    if (s->top == MAXSIZE - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(Stack **s, char *e)
{
    if ((*s)->top == -1)
        return false;
    *e = (*s)->data[(*s)->top];
    (*s)->top--;
    return true;
}

bool GetTop(Stack **s, char *e)
{
    if ((*s)->top == -1)
        return false;
    *e = (*s)->data[(*s)->top];
    return true;
}

bool StackEmpty(Stack **s)
{
    if ((*s)->top == -1)
        return true;
    return false;
}

// 将中缀表达式转换成后缀表达式
void trans(char *exp, char postexp[])
{
    int i = 0;
    char e;
    Stack *Optr;
    InitStack(&Optr); //初始化操作符栈，为存储后缀表达式做准备

    while (*exp != '\0') // 对每个字符进行判断处理
    {
        switch (*exp)
        {
        //单独处理括号
        //如果是左括号，直接入栈
        case '(':
            Push(Optr, '(');
            exp++;
            break;
        //如果为右括号，一直出栈操作，直到将 ( 也出栈
        case ')':
            Pop(&Optr, &e);
            while (e != '(')
            {
                postexp[i++] = e;
                Pop(&Optr, &e);
            }
            exp++;
            break;
        // + - 优先级相同，当做同一种情况处理
        case '+':
        case '-':
            //由于 + - 的优先级只比 ( 大，所有只要栈顶字符不为 ( 就一直出栈；反之，则将 + - 入栈。
            while (!StackEmpty(&Optr))
            {
                GetTop(&Optr, &e);
                if (e == '(')
                    break;
                else
                {
                    postexp[i++] = e;
                    Pop(&Optr, &e);
                }
            }
            //最后将 + - 入栈
            Push(Optr, *exp);
            exp++;
            break;
        case '*':
        case '/':
            // * / 优先级比 * / ^ ! 小，所有如果栈顶运算符是它们，就出栈；反之就将 * / 入栈
            while (!StackEmpty(&Optr))
            {
                GetTop(&Optr, &e);
                if (e == '/' || e == '*' || e == '^' || e == '!') // * / 的优先级仅仅低于它前面的 * /，高于前面的 + -，所以要将前面的 * / 弹出栈；+ - 保留，因为新的 * / 会放在栈低，优先级高。
                {
                    postexp[i++] = e;
                    Pop(&Optr, &e);
                }
                else
                    break; // 其他情况（ + - 左括号 ）退出，
            }
            //最后将 / * 入栈
            Push(Optr, *exp);
            exp++;
            break;
        case '^':
            // ^ 优先级仅比 ^ ! 小，如果栈顶运算符是它们，则出栈；反之将 ^ 入栈
            while (!StackEmpty(&Optr))
            {
                GetTop(&Optr, &e);
                if (e == '^' || e == '!')
                {
                    postexp[i++] = e;
                    Pop(&Optr, &e);
                }
                else
                    break; // 其他情况（ + - * / ( ）退出，
            }
            Push(Optr, *exp); //最后将 ^ 入栈
            exp++;
            break;
        case '!':
            // ! 优先级仅比 ! 小，所有如果栈顶运算符为 !,则将其出栈；反之，将 ! 入栈
            while (!StackEmpty(&Optr))
            {
                GetTop(&Optr, &e);
                if (e == '!')
                {
                    postexp[i++] = e;
                    Pop(&Optr, &e);
                }
                else
                    break; // 其他情况（ + - * / ^ ( ）退出，
            }
            //最后将 ! 入栈
            Push(Optr, *exp);
            exp++;
            break;
        default:
            while (*exp > '0' && *exp < '9') //循环判断是否为数字字符，如果是则保存到postexp，循环判断是因为可能是多位数字
            {
                postexp[i++] = *exp;
                exp++;
            }
            //以#分隔各个数字字符
            postexp[i++] = '#';
        }
    }
    while (!StackEmpty(&Optr)) //扫描完exp后，操作符栈可能还有操作符，将其存到postexp
    {
        Pop(&Optr, &e);
        postexp[i++] = e;
    }
    postexp[i] = '\0'; //结束字符串
    free(Optr);        //销毁栈
}

//将字符形式的后缀表达式，转换成数字形式的表达式并进行计算
typedef struct
{
    double data[MAXSIZE];
    int top;
} Stack_num;

void InitStack_num(Stack_num **s)
{
    *s = (Stack_num *)malloc(sizeof(Stack_num));
    (*s)->top = -1;
}

bool Push_num(Stack_num **s, double e)
{
    if ((*s)->top == MAXSIZE - 1)
        return false;
    (*s)->top++;
    (*s)->data[(*s)->top] = e;
    return true;
}

bool Pop_num(Stack_num **s, double *e)
{
    if ((*s)->top == -1)
        return false;
    *e = (*s)->data[(*s)->top];
    (*s)->top--;
    return true;
}

//计算后缀表达式的值
double compvalue(char *postexp)
{
    Stack_num *num;
    int i = 1;
    double result;
    double a, b;
    double c;
    double d;
    InitStack_num(&num);
    while (*postexp != '\0')
    {
        switch (*postexp)
        {
        case '+':
            Pop_num(&num, &a);
            Pop_num(&num, &b);
            //计算 b+a 的值
            c = b + a;
            Push_num(&num, c);
            break;
        case '-':
            //计算 b-a 的值
            Pop_num(&num, &a);
            Pop_num(&num, &b);
            c = b - a;
            Push_num(&num, c);
            break;
        case '*':
            Pop_num(&num, &a);
            Pop_num(&num, &b);
            //计算 b*a 的值
            c = b * a;
            Push_num(&num, c);
            break;
        case '/':
            Pop_num(&num, &a); // a是除数
            Pop_num(&num, &b);
            //计算 b/a 的值
            if (a != 0)
            {
                c = b / a;
                Push_num(&num, c);
            }
            else
            {
                printf("除0错误！\n");
                exit(0);
            }
            break;
        case '^':
            Pop_num(&num, &a); // a是指数
            Pop_num(&num, &b);
            //计算 b^a 的值
            if (a != 0)
            {
                i = 1;
                c = 1;
                while (i <= a)
                {
                    c = c * b;
                    i++;
                }
            }
            else if (b != 0)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }
            Push_num(&num, c);
            break;
        case '!':
            Pop_num(&num, &a);
            //计算 a! 的值
            c = 1;
            i = a;
            while (i != 0)
            {
                c = c * i;
                i--;
            }
            Push_num(&num, c);
            break;
        default:
            //如果不是运算符，就只能是字符形式的数字，将其转换成对应的整数
            d = 0;
            while (*postexp >= '0' && *postexp <= '9')
            {
                d = 10 * d + (*postexp - '0');
                postexp++;
            }
            Push_num(&num, d);
        }
        postexp++; //继续下一个字符
    }
    Pop_num(&num, &result);
    return result;
}
//检查用户输入的表达式的正误
bool test(char *exp)
{
    int i = 0;
    Stack *s;
    char e;
    //判断是否包含非法字符
    for (; exp[i] != '\0'; i++)
    {
        if (!((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '!' || exp[i] == '^' || exp[i] == '+' || exp[i] == '-' ||
              exp[i] == '*' || exp[i] == '/' || exp[i] == '(' || exp[i] == ')'))

            return false;
    }
    //如果表达式中包含括号，验证括号的完整性
    InitStack(&s);
    for (i = 0; exp[i] != '\0'; i++)
    {
        switch (exp[i])
        {
        case '(':
            Push(s, exp[i]);
            break;
        case ')':
            if (Pop(&s, &e))
            {
                if (exp[i] == ')' && e == '(')
                    return true;
                else
                    return false;
            }
            else
                return false;
            break;
        }
    }
    //栈为空表示括号匹配成功
    if (s->top != -1)
        return false;
    else
        return true;
    return true;
}

int main()
{
    //存储用户输入的中缀表达式
    char exp[MAXSIZE];
    //用于存储转换后的后缀表达式
    char postexp[MAXSIZE];
    while (true)
    {
        printf("输入表达式：");
        scanf("%s", exp);
        if (!test(exp))
        {
            printf("存在非法字符或者括号不匹配！\n");
            continue;
        }
        trans(exp, postexp);
        printf("后缀表达式:%s\n", postexp);
        printf("结果:%lf\n", compvalue(postexp));
    }
    return 0;
}