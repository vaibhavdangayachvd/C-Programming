#include <stdio.h>
#include <conio.h>
void main()
{
    int x=5,*i;
    i = x;
    printf("%d %u %u",*i,i,&x);
}
