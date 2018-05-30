#include<stdio.h>
#include<conio.h>
int sum(int);
void seq(int);
void rev(int);
void main()
{
    int i;
    printf("Enter number\n");
    scanf("%d",&i);
    printf("Sum = %d\n",sum(i));
    printf("Seq = ");
    seq(i);
    printf("\nRev = ");
    rev(i);
    getch();
}
int sum(int i)
{
    if(i/10==0)
        return i;
    else
        return(i%10 + sum(i/10));
}
void rev(int i)
{
    if(i/10==0)
    {
        printf("%d ",i);
        return;
    }
    else
    {
        printf("%d ",i%10);
        rev(i/10);
    }
}

void seq(int i)
{
    if(i/10==0)
    {
        printf("%d ",i);
    }
    else
    {
        seq(i/10);
        printf("%d ",i%10);
    }
}
