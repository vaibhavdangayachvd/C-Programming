#include<stdio.h>
#include<conio.h>
int sum(int);
void main()
{
    int i;
    printf("Enter number\n");
    scanf("%d",&i);
    printf("= %d",sum(i));
    getch();
}
int sum(int i)
{
    int add;
    if(i==0)
        return 0;
    else
    {
        add = i+sum(i-1);
        printf("%d + ",i);
        return add;
    }
}
