/*Squares and Square root*/
#include <stdio.h>
#include <math.h>
#define STEP 10
int main()
{
    float sq,x=0;
    float rt;
    printf("Number    Root     Square\n\n");
    while(x <= 100)
    {
        rt=sqrt(x),sq=pow(x,2);
        printf("%3.0f      %5.2f     %5.0f\n",x,rt,sq);
        x += STEP;
    }
}
