#include <stdio.h>
#include <conio.h>
void scan(int *);
void sort(int *,int);
void print(int *);
void main()
{
    int a[5],x,*p=a;
    scan(p);
    printf("Enter element to insert : ");
    scanf("%d",&x);
    p = &a[4];
    sort(p,x);
    p = a;
    print(p);
}
void scan(int *p)
{
    int i;
    printf("Enter elements of the array\n->");
    for(i=0;i<4;++i&&++p)
    {
        scanf("%d",&*p);
    }
    return;
}
void sort(int *p,int x)
{
    int i;
    for(i=4;;--i&&--p)
    {
        if(*p<x)
        {
            *(p+1)=x;
            break;
        }
        else
        {
            *(p+1)=*p;
        }
    }
    return;
}
void print(int *p)
{
    int i;
    for(i=0;i<5;++i&&++p)
    {
        printf("%d ",*p);
    }
    return;
}
