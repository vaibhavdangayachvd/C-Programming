/*Plotting Function*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    float a,y1,y2,n;
    double x;
    a = .4;
    printf("                            Y--->                           \n");
    printf("       0----------------------------------------------------\n");
    //Loop Begin
    for(x=0;x<=5;x+=0.25)
    {
        y1= (double)(50*exp(-a*x)+0.5);
        y2= (double)(50*exp(-a*x*x/2)+0.5);
        //Plotting when Y1 = y2//
        if(y1==y2)
        {
            if (x==2.5)
                printf("X %.2lf |",x);
            else
                printf("  %.2lf |",x);
            for(i=1;i<y1;++i)
                printf(" ");
            printf("#\n");
            continue;
        }
        //Plotting when y1>y2//
        if(y1>y2)
        {
            if(x==2.5)
                printf("X %.2lf |",x);
            else
                printf("  %.2lf |",x);
            for(i=1;i<y2;++i)
                printf(" ");
            printf("*");
            for(i=1;i<y1-y2;++i)
                printf("-");
            printf("0\n");
            continue;
        }
        //Plotting when y1<y2//
        if(y1<y2)
        {
            if(x==2.5)
                printf("X %.2lf |",x);
            else printf("  %.2lf |",x);
            for(i=1;i<y1;++i)
                printf(" ");
            printf("0");
            for(i=1;i<y2-y1;++i)
                printf("-");
            printf("*\n");
            continue;
        }
    }
    printf("       |\n");
}
