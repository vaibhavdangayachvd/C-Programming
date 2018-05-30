#include <stdio.h>
#include <conio.h>
void exchange(int *,int *);
void main()
{
    int x=3,y=5;
    exchange(&x,&y);
    printf("%d %d",x,y);
}
void exchange(int *x,int *y)
{
    int t;
    t = *x;
    *x=*y;
    *y=t;
    return;
}
