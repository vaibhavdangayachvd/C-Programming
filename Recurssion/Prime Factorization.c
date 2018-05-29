#include<stdio.h>
#include<conio.h>
void prime(int);
void main()
{
    int i;
    printf("Enter number\n");
    scanf("%d",&i);
    printf("Prime factorization : ");
    prime(i);
    getch();
}
void prime(int num)
{
    int i=2;
    if(num==1)
        return;
    while(num%i!=0)
        ++i;
    printf("%d ",i);
    prime(num/i);
}
