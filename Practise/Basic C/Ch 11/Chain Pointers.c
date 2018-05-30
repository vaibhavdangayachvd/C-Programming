#include <stdio.h>
#include <conio.h>
void main()
{
    int x=5,*p=&x,**q=&p;
    printf("%d",**q);
}
