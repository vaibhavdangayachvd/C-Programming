#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void add(int,int);
void sub(int,int);
void mul(int,int);
void did(int,int);
void scan(int,int);
void check(int,int);
void test(int);
void main()
{
    int a,b;
    start:
    scan(a,b);
    goto start;
}
void scan(int x ,int y)
{
    printf("Enter two numbers\n->");
    scanf("%d %d",&x,&y);
    printf("Enter Your Choice :-\n");
    printf("(a) Sum of Numbers\n(b) Difference of Numbers\n(c) Product of Numbers\n(d) Division of Numbers\n->");
    check(x,y);
    test(x);
    return;
}
void check(int x,int y)
{
    char c;
    scanf(" %c",&c);
    switch (c)
    {
    case 'a' :
        add(x,y);
        break;
    case 'b' :
        sub(x,y);
        break;
    case 'c' :
        mul(x,y);
        break;
    case 'd' :
        did(x,y);
        break;
    default:
        printf("You have entered wrong input !!\n");
        break;
    }
    return;
}
void add(int x,int y)
{
    x = x+y;
    printf("Sum = %d\n",x);
    return;
}
void sub(int x,int y)
{
    x = x-y;
    printf("Difference = %d\n",x);
    return;
}
void mul(int x,int y)
{
    x = x*y;
    printf("Product = %d\n",x);
    return;
}
void did(int x,int y)
{
    float z;
    z = x/y;
    printf("Quotient = %.2f\n",z);
    return;
}
void test(int x)
{
    printf("Do you want to try again? 0 - No , 1 - Yes : ");
    scanf("%d",&x);
    if(x==1)
        return;
    else
        exit(0);
}
