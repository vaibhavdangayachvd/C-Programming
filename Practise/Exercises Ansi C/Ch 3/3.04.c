/*Perimeter and Area of Triangle*/
#include <stdio.h>
int main()
{
    float l,b,a,p;
    printf("Enter Length and Width\n->");
    scanf("%f %f",&l,&b);
    a = l*b;
    p = 2*(l+b);
    printf("Area = %3.2f\nPerimeter = %3.2f",a,p);
}
