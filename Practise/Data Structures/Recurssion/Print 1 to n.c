#include<stdio.h>
#include<conio.h>
void print(int);
void main()
{
    int i;
    printf("Enter the limit\n");
    scanf("%d",&i);
    print(i);
    getch();
}
void print(int n)
{
    if(n==0)
        return;
    else
    {
        print(n-1);
        printf("%d ",n);
    }
}
