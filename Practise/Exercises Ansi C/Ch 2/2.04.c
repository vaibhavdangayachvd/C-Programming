/*division*/
#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    printf("Enter First Number\n->");
    scanf("%f",&a);
    printf("Enter Second Number\n->");
    scanf("%f",&b);
    c = a/b;
    printf("%3.2f / %3.2f = %3.2f",a,b,c);
}
