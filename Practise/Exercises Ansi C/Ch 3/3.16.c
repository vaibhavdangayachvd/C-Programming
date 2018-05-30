/*Codes and Calls*/
#include <stdio.h>
int main()
{
    int x,y;
    float bill;
    printf("Enter Customer Code and Calls Made\n->");
    scanf("%d %d",&y,&x);
    bill = (250 + ((x-100)*1.25));
    if (x <= 100)
        printf("Bill = 250rs");
    else
        printf("Bill = %3.2frs",bill);
}
