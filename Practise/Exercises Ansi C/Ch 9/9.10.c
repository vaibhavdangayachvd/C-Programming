#include <stdio.h>
#include <conio.h>
#include <math.h>
void area(int,int,int);
void peri(int,int,int);
void scan(int,int,int);
void test(void);
void main()
{
    int a,b,c;
    start:
    printf("Enter 3 sides of triangle\n->");
    scan(a,b,c);
    goto start;
}
void scan(int x,int y,int z)
{
    char c;
    scanf("%d %d %d",&x,&y,&z);
    printf("Enter Choice :-\n");
    printf("(p) = Perimeter\n(a) = Area\n->");
    scanf(" %c",&c);
    switch(c)
    {
    case 'p' :
    case 'P':
        peri(x,y,z);
        break;
    case 'a':
    case 'A':
        area(x,y,z);
        break;
    default:
        printf("Enter correct value\n");
        break;
    }
    test();
    return;
}
void area(int x,int y,int z)
{
    float area,s;
    s =(x+y+z)/2;
    area = sqrt((s-x)*(s-y)*(s-z));
    printf("Area = %.2f\n",area);
    return;
}
void peri(int x,int y,int z)
{
    printf("Perimeter  = %d\n",x+y+z);
}
void test(void)
{
    int x;
    printf("DO you want to try again? 0 = No, 1 = Yes : ");
    scanf("%d",&x);
    if(x==1)
        return;
    else
        exit(0);
}
