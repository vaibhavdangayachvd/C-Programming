#include <stdio.h>
#include <conio.h>
int largest(int[][100],int,int);
void main()
{
    int a[100][100],m,n;
    printf("Enter order of matrix : ");
    scanf("%d %d",&m,&n);
    printf("Enter elements of matrix\n->");
    printf("Largest element is %d",largest(a,m,n));
}
int largest(int x[][100],int m,int n)
{
    int i,j,l;
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            scanf("%d",&x[i][j]);
            if(i==1&&j==1)
                l = x[i][j];
            else if(x[i][j]>l)
                l = x[i][j];
        }
    }
        return(l);
}
