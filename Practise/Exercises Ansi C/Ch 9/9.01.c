#include <stdio.h>
#include <conio.h>
int x = 5,y=10;
void ex();
void main()
{
    printf("%d %d\n",x,y);
    ex();
    printf("%d %d",x,y);
}
void ex()
{
    int t;
    t = x;
    x = y;
    y = t;
    return;
}
