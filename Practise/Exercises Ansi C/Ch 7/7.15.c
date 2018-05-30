#include <stdio.h>
#include <conio.h>
#define ROW 2
#define COL 3
void main()
{
    int mat1[ROW][COL],mat2[ROW][COL],sum[ROW][COL],diff[ROW][COL],i,j;
    printf("Enter elements of first matrix row wise\n->");
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter elements of second matrix row wise\n->");
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            sum[i][j]=mat1[i][j]+mat2[i][j];
            diff[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    //Printing
    printf("A+B :-\n\n");
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            printf("%2d ",sum[i][j]);
        }
        printf("\n");
    }
    printf("\nA-B -:\n\n");
    for(i=0;i<ROW;++i)
    {
        for(j=0;j<COL;++j)
        {
            printf("%2d ",diff[i][j]);
        }
        printf("\n");
    }
}
