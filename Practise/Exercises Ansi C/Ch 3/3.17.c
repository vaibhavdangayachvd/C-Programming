/*Sin and Cos*/
#include <stdio.h>
#include <math.h>
#define STEP 15
#define PIE 3.14
int main()
{
    int x=0;
    float sine,cosine,a,b;
    printf("x(degrees)   sin(x)      cos(x)\n\n");
    while (x <= 180)
    {
        a=(PIE/180)*x;
        sine=sin(a);
        b=(PIE/180)*x;
        cosine=cos(b);
        printf("%3d          %3.2f         %3.2f\n",x,sine,cosine);
        x += STEP;
    }
}
