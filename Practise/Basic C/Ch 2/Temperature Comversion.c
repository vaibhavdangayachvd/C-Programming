/*Temperature Conversation*/
#include <stdio.h>
#include <math.h>
/*DEfine*/
#define F_LOW 0
#define F_MAX 250
#define STEP 25
int main()
{
    typedef float REAL;
    REAL fahr, cels;
    fahr = F_LOW;
    printf("Fahrenheit  Celsius\n\n");
    /*Loop*/
    while(fahr <= F_MAX)
    {
        cels = (fahr - 32.0)/1.8;
        printf(" %5.1f %7.2f\n",fahr,cels);
        fahr = fahr + STEP;
    }
    /*Lood End*/
}
