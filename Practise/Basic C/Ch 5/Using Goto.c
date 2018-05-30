/*Using GOTO*/
#include <stdio.h>
#include <math.h>
int main()
{
    int count;
    double x,y;
    count = 1;
    printf("Enter five real values in a line\n->");
    read:
        scanf("%lf",&x);
        printf("\n");
        if (x<0)
            printf("Value - %d is negative\n",count);
            else
            {
                y = sqrt(x);
                printf("%lf\t %lf\n",x,y);
            }
            count += 1;
            if (count <= 5)
                goto read;
            printf("End of Computation");
}
