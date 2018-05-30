/*Power of 2*/
#include <stdio.h>
int main()
{
    long int p;
    int n;
    double q;
    printf("===========================================\n");
    printf("2 to power n        n        2 to power -n\n");
    printf("===========================================\n");
    for (p=1,n=0;n<=20;++n)
    {
        if(n==0)
            p = 1;
        else
            p = p*2;
        q = 1.0/(double)p;
        printf("%10ld %10d %20.12lf\n",p,n,q);
    }
    printf("===========================================\n");
}
