#include <stdio.h>
#include <conio.h>
void scan(int *);
void print(int *);
void main()
{
    int a[10],*p;
    p = a;
    scan(p);
    p = &a[9];
    print(p);
}
void scan(int *p)
{
    int i;
    printf("Enter 10 elements\n->");
    for(i=0;i<10;++i&&++p)
    {
        scanf("%d",&*p);
    }
}
void print(int *p)
{
    int i;
    for(i=0;i<10;++i&&--p)
    {
        printf("%d\n",*p);
    }
}
