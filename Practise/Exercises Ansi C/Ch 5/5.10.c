/*Quadratic Equation*/
#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,d,x1,x2;
    printf("Enter values of a, b and c to find real roots\n->");
    scanf("%f %f %f",&a,&b,&c);
    d = sqrt(b*b - 4*a*c);
    if (a == 0 && b ==0)
        printf("No solution");
    else if ( a == 0)
        {
           x1 = -c/b;
           printf("Root = %.2f",x1);
        }
    else if ( pow(d,2) < 0)
        printf("No Real Roots");
    else
        {
           x1 = (-b)+(d/(2*a));
           x2 = (-b)-(d/(2*a));
           printf("Root 1 : %.2f\nRoot 2 : %.2f",x1,x2);
        }
}
