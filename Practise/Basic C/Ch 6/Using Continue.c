/*Using Continue*/
#include <stdio.h>
#include <math.h>
int main()
{
    int count,negative;
    double n,sq;

    printf("Enter 9999 to STOP\n");
    count = 0;
    negative = 0;
    while(count<=100)
    {
        printf("Enter a number : ");
        scanf("%lf",&n);
        if(n == 9999)
            break;
        if (n < 0)
        {
            printf("Number is negative\n\n");
            negative++;
            continue;
        }
        sq = sqrt(n);
        printf("Number = %lf\nSquare Root = %lf\n\n",n,sq);
        count++;
    }
    printf("Number of items done = %d\n\n",count);
    printf("Negative Items = %d\n",negative);
    printf("END OF DATA");
}
