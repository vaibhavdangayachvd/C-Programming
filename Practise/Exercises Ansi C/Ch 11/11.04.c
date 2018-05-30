#include <stdio.h>
#include <conio.h>
int *add(int *,int *,int *);
void scan(int *);
void print(int *);
void hold(void);
void main()
{
    int a[2][2],b[2][2],c[2][2],*p;
    scan(a);
    scan(b);
    p = add(a,b,c);
    print(p);
    hold();
}
void scan(int *p)
{
    int i,j;
    printf("Enter elements of the matrix\n->");
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            scanf("%d",&*(p+2*i+j));
        }
    }
    return;
}
int *add(int *a,int *b,int *c)
{
    int i,j;
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            *(c+2*i+j)=*(a+2*i+j)+*(b+2*i+j);
        }
    }
    return c;
}
void print(int *p)
{
    int i,j;
    printf("Sum :-\n");
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            printf("%d ",*(p+2*i+j));
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void hold(void)
{
    printf("Press Enter to continue...");
    getch();
}
