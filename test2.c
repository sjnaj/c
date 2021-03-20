/*#include <stdio.h>
#include <string.h>

#define MAXN 10

int even( int n );
int OddSum( int List[], int N );

int main()
{    
    int List[MAXN], N, i;

    scanf("%d", &N);
    printf("Sum of ( ");
    for ( i=0; i<N; i++ ) {
        scanf("%d", &List[i]);
        if ( even(List[i])==0 )
            printf("%d ", List[i]);
    }
    printf(") = %d\n", OddSum(List, N));

    return 0;
}
int even(int n)
{
    if(n%2==0)
        return 1;else
            return 0;
}
int OddSum( int List[], int N )
{int sum=0;
    for(int i=0; i<N;i++)
    {
        if(even(List[i])==0)
            sum+=List[i];
    }
 return sum;
        
}
*/
#include <stdio.h>
char *a;
char *b[10];
int main()
{
    char *p;
    char *q[10];
    printf("%p,%p,%p,%p",a,b[0],p,q[0]);
    return 0;

}