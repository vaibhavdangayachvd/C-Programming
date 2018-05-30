/*Sum of series*/
#include <stdio.h>
#include <math.h>
int main()
{
    float n,sum,x;
    sum=0;
    printf("Input Number\n->");
    scanf("%f",&n);
    while (n>=1)
    {
        x = 1/n;
        sum = sum + x;
        n = n -1;
    }
    printf("Sum = %3.2f",sum);
}
