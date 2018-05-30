/*Inventory Report*/
#include <stdio.h>
int main()
{
    int x=1,y,quantity[5];
    char code[5][5];
    float rate[5],value,total=0;
    printf("Enter number of items\n->");
    scanf("%d",&y);
    while(x <= y)
    {
        printf("Enter code, quantity, and rate:");
        scanf("%s %d %f",code[x],&quantity[x],&rate[x]);
        x++;
    }
    printf("\nINVENTORY REPORT\n");
    printf("------------------------------------\n");
    printf("Code\tQuantity\tRate\tValue\n");
    printf("-------------------------------------\n");
    x = 1;
    while(x<=y)
    {
        value=quantity[x]*rate[x];
        printf("%s\t%d\t%5.2f\t%7.2f\n",code[x],quantity[x],rate[x],value);
        total += value;
        x++;
    }
    printf("------------------------------------------\n");
    printf("\t\tTotal Value = %8.2f\n",total);
    printf("-------------------------------------------\n");
}
