/*Errors*/
#include <stdio.h>
#include <math.h>
int main()
{
    float sum=0,n,term;
    int count;
    printf("Enter Value of N\n->");
    scanf("%f",&n);
    term = (1.0)/n;
    while (count <= n)
    {
        sum = sum + term;
        count = count + 1;
    }
    printf("Sum = %f\n", sum);
}
