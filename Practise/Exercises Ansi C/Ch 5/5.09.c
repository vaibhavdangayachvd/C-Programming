/*
Value of y
#include <stdio.h>
int main()
{
    int x,y;
    printf("Enter value of x:")
    scanf("%d",&x);
    if (x == 0)
        y = 0;
    if (x != 0)
    {
        if (x>0)
        y = 1;
        if (x<0)
        y = 0;
    }
    printf("Y = %d",y);
}
*/

/*
Else IF
#include <stdio.h>
int main()
{
    int x,y;
    printf("Enter value of x:");
    scanf("%d",&x);
    if (x==0)
        y = 0;
    else if (x>0)
        y = 1;
    else
        y = -1;
    printf("Y = %d",y);
}
*/

/*Contitional Operator*/
#include <stdio.h>
int main()
{
    int x,y;
    printf("Enter value of x:");
    scanf("%d",&x);
    y = x==0 ? 0:(x>0 ? 1 : -1);
    printf("Y = %d",y);
}
