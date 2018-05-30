#include <stdio.h>
#include <conio.h>
void scan(int *);
int check(int *,int *);
void print(int);
void hold(void);
void main()
{
    int a[4],b[4],p;
    scan(a);
    scan(b);
    p = check(a,b);
    print(p);
    hold();
}
void scan(int *p)
{
    int i;
    static int j=1;
    printf("Enter elements of array %d\n->",j);
    for(i=0;i<4;++i)
    {
        scanf("%d",p+i);
    }
    ++j;
    return;
}
int check(int *p,int *q)
{
    int i;
    for(i=0;i<4;++i)
    {
        if(*(p+i)!= *(q+i))
            return(0);
    }
    return(1);
}
void print(int p)
{
    printf("\n");
    if(p==0)
        printf("Both are not equal\n\n");
    else
        printf("Both are equal\n\n");
    return;
}
void hold (void)
{
    printf("Press Enter to continue...");
    getch();
}
