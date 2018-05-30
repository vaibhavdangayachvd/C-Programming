#include <stdio.h>
#include <conio.h>
int sum(int[]);
void main()
{
    int x,a[5]={4,5,6,3,5};
    x = sum(a);
    printf("%d\n",x);
    for(x=0;x<5;++x)
    {
        printf("%d\n",a[x]);
    }
}
int sum(int a[])
{
    int sum=0,i;
    for(i=0;i<5;++i)
    {
        sum+=a[i];
    }
    a[0]=2;
    return(sum);
}
