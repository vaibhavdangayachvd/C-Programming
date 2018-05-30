/*Interest Calculation*/
#include <stdio.h>
int main()
{
    int year,period;
    float amount,inrate,value;

    printf("Enter Amount, Interest Rate and Period\n\n->");
    scanf("%f %f %d",&amount,&inrate,&period);
    printf("\n");
    printf("Year   Amount\n\n");
    year = 1;
        while(year <= period)
     {
        value= amount + inrate*amount;
        printf("%2d   Rs%8.2f\n",year, value);
        amount = value;
        year= year + 1;
     }
}
