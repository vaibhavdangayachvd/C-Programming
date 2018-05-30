/*Smallest Integer*/
#include <stdio.h>
#include <math.h>
int main()
{
    float x;
    int y,z;
    printf("Enter Number\n->");
    scanf("%f",&x);
    y = ceil(x);
    z = floor(x);
    printf("%d %3.2f %d",y,x,z);
}
