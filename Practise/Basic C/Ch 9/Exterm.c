#include <stdio.h>
#include <conio.h>
void test();
void main()
{
    printf("Sum using Reurcssion \n");
    test();
}
void test(void)
{
    static int x=0,sum=1;
    if(x==5)
        return;
    else
    {
        ++x;
        printf("%d",x);
        test();
    }
}
