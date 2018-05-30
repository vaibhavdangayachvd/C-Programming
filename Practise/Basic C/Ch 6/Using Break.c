/*Using Break*/
#include <stdio.h>
int main()
{
    int m;
    float x,sum,average;
     printf("This program computes the average of a set of numbers\n");
     printf("Enter a negative number at the end\n\n");
     sum = 0;
     for (m=1;m<=1000;++m)
     {
         scanf("%f",&x);
         if(x<0)
            break;
         sum += x;
     }
     average = sum/(float)m-1;
     printf("\n");
     printf("Number of values = %d\n",m-1);
     printf("sum              = %f\n",sum);
     printf("Average          = %f\n",average);
}
