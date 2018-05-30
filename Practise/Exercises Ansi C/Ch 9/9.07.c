//Prime Number
#include <stdio.h>
#include <conio.h>
int prime(int);
void main()
{
    int x;
    printf("Enter number to check if its prime or not : ");
    scanf("%d",&x);
    if(prime(x)==1)
        printf("Its prime number");
    else
        printf("Its not a prime number");
}
int prime(int a)
{
    int i,flag=1;
    for(i=2;i<=a/2;++i)
    {
        if(a%i==0)
        {
            flag=0;
            break;
        }
    }
    return(flag);
}
