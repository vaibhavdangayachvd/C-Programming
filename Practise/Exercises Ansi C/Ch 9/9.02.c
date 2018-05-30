#include <stdio.h>
#include <conio.h>
void space(int);
void main()
{
    int x;
    printf("Enter number of space : ");
    scanf("%d",&x);
    printf("A");
    space(x);
    printf("B");
    space(2);
    printf("B");
}
void space(int a)
{
    int i;
    for(i=1;i<=a;++i)
    {
        printf(" ");
    }
    return;
}
