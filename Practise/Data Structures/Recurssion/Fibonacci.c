#include<stdio.h>
#include<conio.h>
int feb(int);
void main()
{
    int i,limit;
    printf("Limit of febonacci\n");
    scanf("%d",&limit);
    for(i=1;i<=limit;++i)
        printf("%d ",feb(i));
    getch();
}
int feb(int i)
{
    if (i==0 || i==1)
        return 1;
    return (feb(i-1)+feb(i-2));
}
