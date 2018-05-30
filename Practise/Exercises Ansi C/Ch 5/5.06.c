/*Square Root Table*/
#include <stdio.h>
#include <math.h>
#define VSTEP 1
#define HSTEP 0.1
int main()
{
    float x=0,y=0,z;
    printf("\n\t\t\t\tSquare root table\n\n");
    printf("----------------------------------------------------------------------------\n");
    printf("Number  || ");
    while (x<=1)
    {
        printf(" %2.1f |",x);
        x += HSTEP;
    }
    printf("|");
    printf("\n----------------------------------------------------------------------------");
    printf("\n----------------------------------------------------------------------------\n\n");
    while(y<=9.0)
    {
        x = 0;
        printf("%2.1f     || ",y);
        while(x<=1)
        {
            z = sqrt(y+x);
            printf("%3.2f |",z);
            x += HSTEP;
        }
        printf("|");
        printf("\n");
        printf("----------------------------------------------------------------------------\n");
        y += VSTEP;
    }
    printf("----------------------------------------------------------------------------\n");
}
