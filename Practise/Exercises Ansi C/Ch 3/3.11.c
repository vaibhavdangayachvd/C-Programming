/*Sum of Digits*/
#include <stdio.h>
int main()
{
    int x,x1,x21,x2,x31,x3,x4;
    printf("Enter 4 Digit Number\n->");
    scanf("%d",&x);
    x1=x%10;
    x21=x%100,x2=(x21-x1)/10;
    x31=x%1000,x3=(x31-x21)/100;
    x4=(x-x31)/1000;
    printf("Sum of digits of %d = %d\n",x,(x1+x2+x3+x4));
}
