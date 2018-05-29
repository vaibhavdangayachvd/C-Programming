#include<stdio.h>
#include<conio.h>
void main()
{
    int i,a[6],j;
    for(i=1;i<6;++i)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<3;++i)
    {
        for(j=i;j<6-1;++j)
        {
            a[j]=a[j+1];
        }
    }
    for(i=0;i<3;++i)
    {
        printf("%d ",a[i]);
    }
}
