#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int a[20][20],b[20][20],c[20][20],i,j,k,row1,col1,row2,col2,sum;;
    printf("Enter the order of matrix 1\n");
    scanf("%d %d",&row1,&col1);
    printf("Enter the order of matrix 2\n");
    scanf("%d %d",&row2,&col2);
    if(col1!=row2)
    {
        printf("You cant multiply these matrix\n");
        exit(1);
    }
    printf("Enter the elements of matrix 1 row wise\n");
    for(i=0;i<row1;++i)
    {
        for(j=0;j<col1;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of matrix 2 row wise\n");
    for(i=0;i<row2;++i)
    {
        for(j=0;j<col2;++j)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<row1;++i)
    {
        for(j=0;j<col2;++j)
        {
            sum=0;
            for(k=0;k<col1;++k)
            {
                sum=sum+a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    printf("Multiplication:\n");
    for(i=0;i<row1;++i)
    {
        for(j=0;j<col2;++j)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
