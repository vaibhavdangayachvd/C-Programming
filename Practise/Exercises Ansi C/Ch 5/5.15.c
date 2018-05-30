/*
Trigo
#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    char y;
    printf("Enter value of Angle(in radian) and code letter:");
    scanf("%lf %c",&x,&y);
    if (y=='s'||y=='S')
        {
        x = sin(x);
        printf("sin(x) = %.2lf",x);
        }
    else if (y=='c'||y=='C')
        {
        x = cos(x);
        printf("cos(x) = %.2lf",x);
        }
    else if (y=='t'||y=='T')
        {
        x = tan(x);
        printf("tan(x) = %.2lf",x);
        }
        else
            printf("Input correct code");
}
*/

/*Switch*/
#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    char y;
    printf("Enter value of Angle(in radian) and code letter:");
    scanf("%lf %c",&x,&y);
    switch (y)
{
case 's':
case 'S':
    x = sin(x);
    printf("sin(x) = %.2lf",x);
    break;
case 'c':
case 'C':
    x = cos(x);
    printf("cos(x) = %.2lf",x);
    break;
case 't':
case 'T':
    x = tan(x);
    printf("tan(x) = %.2lf",x);
    break;
default:
    printf("Wrong input");
}
}
