/*Electric Circuit*/
#include <stdio.h>
#include <math.h>
#define STEP 0.01
int main()
{
    float r=.45,l=.02,c=0.01,f;
    while(c <= 0.1)
    {
        f = sqrt((1/(l*c)) - ((r*r)/(4*c*c)));
        printf("%3.2f\n",f);
        c += STEP;
    }
}
