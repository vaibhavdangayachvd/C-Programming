/*Average of Numbers*/
#include <stdio.h>
#define N 10
int main()
{
    int count;
    float sum,average,number;
    sum = 0;
    count = 0;
    while( count < N )
    {
        scanf("%f",&number);
        sum = sum + number;
        count = count + 1;
    }
    average = sum/N;
    printf("N = %d Sum = %f\n",N,sum);
    printf("Average = %f",average);
}
