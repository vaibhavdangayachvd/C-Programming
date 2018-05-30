/*Purchase*/
#include <stdio.h>
#define MC1 0
#define MC2 .05
#define MC3 .075
#define MC4 .1
#define HI1 .05
#define HI2 .075
#define HI3 .1
#define HI4 .15
int main()
{
    float mill,item,amount,discount,net;
    int level;
    char c;
    start:
    printf("\nEnter amount of purchased Mill Cloth and Handloom Item\n\n->");
    scanf("%f %f",&mill,&item);
    amount = mill+item;
    if (amount == 0)
    {
     printf("Enter valid input\n");
     goto start;
    }
    else if (amount<=100)
        level = 1;
    else if (amount<=200)
        level = 2;
    else if (amount<=300)
        level = 3;
    else
        level = 4;

    switch(level)
{
case 1:
    discount = MC1*mill + HI1*item;
    break;
case 2:
    discount = MC2*mill + HI2*item;
    break;
case 3:
    discount = MC3*mill + HI3*item;
    break;
case 4:
    discount = MC4*mill + HI4*item;
    break;
}
    net = amount - discount;
    printf("\nGross Purchase  : %.2f\nLess : Discount : %6.2f\nNet Purchase    : %6.2f\n\n",amount,discount,net);
    printf("Do you want to try again Y or N:");
    print:
    scanf("%c",&c);
    if (c == 'Y' || c == 'y')
        goto start;
    else if (c == 'N' || c == 'n')
        goto stop;
    else
        goto print;
    stop :
        printf("END OF PROGRAM");
}
