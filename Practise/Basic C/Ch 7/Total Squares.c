#include <stdio.h>
#include <conio.h>
void main()
{
    float num[10],total=0;
    int i;
    printf("Enter 10 values\n->");
    for(i=0;i<=9;++i)
    {
        scanf("%f",&num[i]);
        printf("x[%2d] = %6.2f\n",i+1,num[i]);
        total=total+num[i]*num[i];
    }
    printf("Total = %.2f",total);
}
