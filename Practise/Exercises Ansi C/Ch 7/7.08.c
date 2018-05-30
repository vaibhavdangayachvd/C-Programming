#include <stdio.h>
#include <conio.h>
void main()
{
    int row;
    printf("Enter number of rows or coloumns\n->");
    scanf("%d",&row);
    int matrix[row][row],i,j;
    for(i=0;i<row;++i)
    {
        for(j=0;j<row;++j)
        {
            if(i+j==row-1)
                matrix[i][j]=0;
            else if(i+j<row-1)
                matrix[i][j]=1;
            else
                matrix[i][j]=-1;
        }
    }
    for(i=0;i<row;++i)
    {
        for(j=0;j<row;++j)
        {
            printf("%2d  ",matrix[i][j]);
        }
        printf("\n\n");
    }
}
