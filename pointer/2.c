/*#include <stdio.h>
int main(){
    int a =100;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
    printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
    printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
    printf(" &a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
    return 0;
}*/
//#define NDEBUG
#include <stdio.h>
#include <assert.h>
int main()
{
    double m, n, result;
    scanf("%lf %lf", &m, &n);
    assert(n);
    result = (m / n);
        printf("result = %f\n", result);
    return 0;
}