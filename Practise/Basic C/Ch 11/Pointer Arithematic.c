#include <stdio.h>
#include <conio.h>
void main()
{
    int a=12,b=4,*p1,*p2,x,y,z;
    p1=&a,p2=&b;
    x = *p1+*p2;
    printf("%d",x);
}
