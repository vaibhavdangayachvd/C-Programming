/*Intaractive Multiplication*/
#include <stdio.h>
int main()
{
    int x,y,y1,y2;
    printf("Enter 2 two-digit number:");
    scanf("%2d %2d",&x,&y);
    printf("\t\t%d\n\tX\t%d\n\t------------\n",x,y);
    y1 = y%10;
    y2 = (y-y1);
    printf("%d X %d is       %d\n",y1,x,y1*x);
    printf("%d X %d is     %d\n",y2,x,y2*x);
    printf("\t------------\n");
    printf("Add them       %d\n",y1*x+y2*x);
    printf("\t------------\n");
}
