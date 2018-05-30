#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int *p,*table;
    int size;
    printf("Enter the size of the table : ");
    scanf("%d",&size);
    printf("\n");
    if((table=(int*)malloc(size*sizeof(int)))==NULL)
    {
        printf("No Space Available\n");
        exit(1);
    }
    printf("Address of the first byte is %u\n",table);
    printf("Input Table Values\n->");
    for(p=table;p<table+size;++p)
    {
        scanf("%d",p);
    }
    printf("Table Data :- \n");
    for(p=table+size-1;p>=table;--p)
    {
        printf("%2d is stored at address %u\n",*p,p);
    }
}
