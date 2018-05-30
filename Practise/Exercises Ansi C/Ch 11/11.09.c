#include <stdio.h>
#include <conio.h>
void scan(int*);
void sort(int*);
void print(int*);
void hold(void);
void main()
{
    int a[4],*p=a;
    scan(p);
    sort(p);
    print(p);
    hold();
}
void scan(int *p)
{
    int i;
    printf("Enter 4 elements to reverse\n->");
    for(i=0;i<4;++i)
    {
        scanf("%d",p+i);
    }
    return;
}
void sort(int *p)
{
    int i,j,temp;
    for(i=0;i<3;++i)
    {
        for(j=0;j<3-i;++j)
        {
            temp = *(p+j);
            *(p+j) = *(p+j+1);
            *(p+j+1)= temp;
        }
    }
    return;
}
void print(int *p)
{
    int i;
    for(i=0;i<4;++i)
    {
        printf("%d ",*(p+i));
    }
    printf("\n");
    return;
}
void hold(void)
{
    printf("\nPress Enter to exit...");
    getch();
}
