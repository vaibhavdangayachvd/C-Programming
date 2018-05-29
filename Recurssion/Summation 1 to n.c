#include<stdio.h>
#include<conio.h>
int sum(int);
void main()
{
    int limit;
    printf("Enter limit\n");
    scanf("%d",&limit);
    printf("Sum = %d",sum(limit));
    getch();
}
int sum(int limit)
{
    if(limit==1)
        return 1;
    else
        return(limit+sum(limit-1));
}
