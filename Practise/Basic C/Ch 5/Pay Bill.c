/*Pay Bill*/
#include <stdio.h>
#define CA1 1000
#define CA2 750
#define CA3 500
#define CA4 250
#define EA1 500
#define EA2 200
#define EA3 100
#define EA4 0
int main()
{
    int lvl,num;
    float gross,basic,rent,perks,net,tax;

    input:

    printf("\nInput level, job number, and basic pay\n");
    printf("Enter 0 (zero) for level to END\n\n");
    scanf("%d",&lvl);
    if (lvl == 0) goto stop;
    scanf("%d %f",&num,&basic);
    switch (lvl)
    {
    case 1:
        perks = CA1+EA1;
        break;
    case 2:
        perks = CA2+EA2;
        break;
    case 3:
        perks = CA3+EA3;
        break;
    case 4:
        perks = CA4+EA4;
        break;
    default:
        printf("Error in level code\n");
        goto stop;
    }
    rent = 0.25*basic;
    gross = basic + rent + perks;
    if(gross <= 2000)
        tax = 0;
    else if (gross <= 4000)
        tax = 0.03*gross;
    else if (gross <= 5000)
        tax = 0.05*gross;
    else
        tax = 0.08*gross;
    net = gross-tax;
    printf("%d %d %.2f",lvl,num,net);
    goto input;
    stop: printf("\n\nEND OF PROGRAM");
}
