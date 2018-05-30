/*Value of X*/
#include <stdio.h>
int main()
{
    float a,b,c,d,m,n,x1,x2;
    printf("Enter values of a,b,c,d,m and n in one line\n->");
    scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&m,&n);
    if(a*d-c*b == 0)
        printf("Error : Denominator is zero");
    else
    {
        x1 = (m*d-b*n)/(a*d-c*b);
        x2 = (n*a-m*c)/(a*d-c*b);
        printf("x1 = %f\nx2 = %f",x1,x2);
    }
}
