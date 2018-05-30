/*Evaluating Series*/
#include <stdio.h>
#define LOOP 100
#define ACCURACY 0.0001
int main()
{
    int n;
    float x,term,sum;
     printf("Input value of x : ");
     scanf("%f",&x);
     sum = 0;
     for (term=1,n=1;n<=LOOP;++n)
     {
         sum += term;
         if(term<=ACCURACY)
            goto output;
         term*=x;
     }
     printf("Final value of N is not sufficient\n");
     printf("To achieve desired accuracy\n");
     goto end;
     output:
         printf("\nEXIT FROM LOOP\n");
         printf("SUM  = %f; No. of terms = %d",sum,n);
         end:
             ;
}
