/*Tablular form*/
#include <stdio.h>
int main()
{
    //Declarations//
    int item,code[10],count;
    float price[10];
    char name[10][10];
    printf("Enter total number of items:");
    scanf("%d",&item);
    // Scanning Values//
    count=1;
    for(count = 1;count<=item;count++)
    {
        printf("\nEnter item name,code and price:");
        scanf("%s %d %f",name[count],&code[count],&price[count]);
    }
    // Printing
    printf("\nName\tCode\tPrice\n\n");
    count = 1;
    for(count=1;count<=item;count++)
    {
        printf("%s\t%d\t%.2f\n",name[count],code[count],price[count]);
    }
}
