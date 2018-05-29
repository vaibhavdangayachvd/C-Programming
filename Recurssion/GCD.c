#include<stdio.h>
#include<conio.h>
int gcd(int,int);
void main()
{
    int i,j;
    printf("Enter two numbers\n");
    scanf("%d %d",&i,&j);
    printf("GCD = %d",gcd(i,j));
    getch();
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}
