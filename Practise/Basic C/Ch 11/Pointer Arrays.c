#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,a[2][2],*p;
    p = a[0];
    printf("Enter array elements\n->");
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            printf("%d\n",*(p+2*i+j);
        }
    }
}
