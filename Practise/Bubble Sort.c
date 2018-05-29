#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j,limit,a[20],temp;
    printf("Enter limit\n->");
    scanf("%d",&limit);
    printf("Enter elements to sort\n->");
    for(i=0;i<limit;++i)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<limit-1;++i)
    {
        for(j=0;j<limit-1-i;++j)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted List : ");
    for(i=0;i<limit;++i)
    {
        printf("%d ",a[i]);
    }
    getch();
}
