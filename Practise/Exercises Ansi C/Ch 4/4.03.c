/*Round Off*/
#include <stdio.h>
int main()
{
    int p,i;
    float a;
    printf("Enter Given Numbers\n->");
    for (i=1;i<=4;++i)
    {
        scanf("%f",&a);
        if(a>=0)
        p = a+0.5;
        else
        p = a-0.5;
        printf("Nearest int to %.2f is %d\n",a,(int)p);
    }
}

