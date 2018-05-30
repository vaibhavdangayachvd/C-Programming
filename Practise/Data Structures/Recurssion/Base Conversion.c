#include<stdio.h>
#include<conio.h>
void convert(int);
void main()
{
    int i;
    printf("Enter number\n");
    scanf("%d",&i);
    printf("Binary Equiv = ");
    convert(i);
    getch();
}
void convert(int i)
{
    if(i==0||i==1)
        printf("%d",i);
    else
    {
        convert(i/2);
        printf("%d",i%2);
    }
}
