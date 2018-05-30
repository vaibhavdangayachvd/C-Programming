#include <stdio.h>
#include <conio.h>
void main()
{
    int row,col,space,n,num;
    printf("Enter number of rows->");
    scanf("%d",&num);
    for(row=0;row<num;++row)
    {
        for(space=0;space<(num-row);space++);
        {
            printf(" ");
        }
        n=1;
        for(col=0;col<=row;++col)
        {
            printf(" %d",n);
            n=n*(row-col)/(col+1);
        }
        printf("\n");
    }
}
