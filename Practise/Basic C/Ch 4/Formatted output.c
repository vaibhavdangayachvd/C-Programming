/*Formatted Output*/
#include <stdio.h>
int main()
{
    float y = 98.7654;
    /*Printing*/
    printf("%7.4f\n",y);
    printf("%f\n",y);
    printf("%7.2f\n",y);
    printf("%-7.2f\n",y);
    printf("%07.2f\n",y);
    //Imp
    printf("%*.*f\n",7,2,y);
    //
    printf("%10.2e\n",y);
    printf("%12.4e\n",-y);
    printf("%-10.2e\n",y);
    printf("%e\n",y);
}

