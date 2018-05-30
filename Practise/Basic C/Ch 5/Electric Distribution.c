/*Electric Distribution*/
#include <stdio.h>
int main()
{
    int units,num;
    float charges;
    printf("Enter costumer number and units consumed:");
    scanf("%d %d",&num,&units);
    if (units<=200)
        charges = 0.5*units;
    else if (units <= 400)
        charges = 100 + 0.65*(units-200);
    else if (units <= 600)
        charges = 230 + 0.80*(units-400);
    else
        charges = 390 + 1.00*(units-600);

        printf("/n/nCostumer Number: %d Charges: %.2f\n",num,charges);
}
