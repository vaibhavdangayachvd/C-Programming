/*Loan*/
#include <conio.h>
#include <stdio.h>
#define MAXLOAN 50000
int main()
{
    int loanx,loany,newloan,sumxy,sancloan;
    read:
    printf("Enter the values of previous two loans:");
    scanf("%d %d",&loanx,&loany);
    printf("Enter the value of new loan:");
    scanf("%d",&newloan);
    sumxy = loany + newloan;
    sancloan = (loanx > 0)||(loany > MAXLOAN)? 0 : ((sumxy > MAXLOAN)? (MAXLOAN - loany) : newloan);

    printf("\n\n");
    printf("Previous pending loans:\n%d %d\n",loanx,loany);
    printf("Loan Requested = %d\n",newloan);
    printf("Loan Sanctioned = %d\n\n",sancloan);
    goto read;
}
