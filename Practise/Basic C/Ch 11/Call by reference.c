#include <stdio.h>
#include <conio.h>
void exchance(int *,int *);
void main()
{
    int x,y;
    x=100;
    y=200;
    printf("Before exchange x = %d y = %d\n\n",x,y);
    exchange(&x,&y);
    printf("After exchange x = %d y = %d\n\n",x,y);
}
exchange(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}
