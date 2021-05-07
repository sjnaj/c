/*
 * @Author: fengsc
 * @Date: 2021-04-10 17:18:11
 * @LastEditTime: 2021-04-15 22:06:45
 */
#include <stdio.h>

/*int fib(int n);
void PrintFN(int m, int n);

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
void PrintFN( int m, int n ){
  int flag = 0;
  for (int i = 1;fib(i)<=n ; i++) {
    if(fib(i)>=m && fib(i)<=n) {
      if(!flag) printf("%d", fib(i));
      else printf(" %d", fib(i));
      flag = 1;
    }
  }
  if(!flag) printf("No Fibonacci number\n");
}*/
void dectobin( int n );

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}

void dectobin( int n )
{
   if (n <2)
		printf("%d",n);
	else
	{
		dectobin(n/2);
		printf("%d", n%2);
	}

    
}
