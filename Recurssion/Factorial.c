#include<stdio.h>
#include<conio.h>
int facto(int);
void main()
{
    int num;
    printf("Enter num\n");
    scanf("%d",&num);
    printf("Factorial is %d",facto(num));
    getch();
}
int facto(int num)
{
    if(num==1)
        return 1;
    else
        return(num*facto(num-1));
}
