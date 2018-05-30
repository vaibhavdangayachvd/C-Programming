/*Bill*/
#include <stdio.h>
#define MIN 100
int main()
{
    int units;
    char name[10];
    float charge;
    printf("Enter name and units consumed:");
    scanf("%s %d",name,&units);
    if (units <= 200)
        {
            charge = 0.8*units;
            if (charge<100)
                charge = 100;
        }
        else if (units<=300)
            charge = (0.8*200)+(0.9*(units-200));
        else
            charge = (0.8*200)+(0.9*(100))+(1*(units-300));

        printf("Name : %s\nCharges : %.2f",name,charge);
}
