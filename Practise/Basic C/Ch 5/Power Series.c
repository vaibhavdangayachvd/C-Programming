/*Power Series*/
#include <stdio.h>
#define ACCURACY .0001
int main()
{
    int n,count;
    float x,term,sum;
    printf("Enter value of x:");
    scanf("%f",&x);
    n = term = sum = count = 1;
    while(n <=100)
    {
        term = term*x/n;
        sum = sum+term;
        count = count + 1;
        if(term < ACCURACY)
            n = 999;
        else
            n+=1;
    }
    printf("Terms = %d Sum = %3.2f\n",count,sum);
}
