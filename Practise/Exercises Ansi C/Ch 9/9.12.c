#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void mul(int[][100],int[][100],int,int);
void main()
{
    int m1[100][100],m2[100][100],m,n,i,j;
    start:
    system("cls");
    printf("Enter the value of m and n : ");
    scanf("%d %d",&m,&n);
    printf("Enter the elements of first matrix\n->");
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Enter elements of second matrix\n->");
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            scanf("%d",&m2[i][j]);
        }
    }
    mul(m1,m2,m,n);
    goto start;
}
void mul(int m1[][100],int m2[][100],int m,int n)
{
    int row,col,i,sum,m3[100][100];
    for(row=1;row<=m;++row)
    {
        for(col=1;col<=m;++col)
        {
            sum=0;
            for(i=1;i<=n;++i)
            {
                sum+=m1[row][i]*m2[i][col];
            }
            m3[row][col]=sum;
        }
    }
    printf("Product of matrix :-\n");
    for(row=1;row<=m;++row)
    {
        for(col=1;col<=m;++col)
        {
            printf("%d ",m3[row][col]);
        }
        printf("\n");
    }
    printf("Do you want to try again? 0 - NO , 1 - Yes\n->");
    scanf("%d",&i);
    if(i==1)
        return;
    else
        exit(0);
}
