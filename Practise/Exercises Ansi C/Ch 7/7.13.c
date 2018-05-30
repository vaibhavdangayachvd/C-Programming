//Transpose of a matrix
#include <stdio.h>
#include <conio.h>
#define ROW 3
#define COL 2
void main()
{
    int matrix[ROW][COL],trans[COL][ROW],i,j,temp;
    if(ROW<COL)
        temp=COL;
    else
        temp=ROW;
    printf("Enter matrix row wise\n->");
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<temp;++i)
    {
        for(j=0;j<temp;++j)
        {
            trans[i][j]=matrix[j][i];
        }
    }
    printf("\n");
    for(i=0;i<COL;i++)
    {
        for(j=0;j<ROW;++j)
        {
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }
}
