#include<stdio.h>
#include<conio.h>
void main()
{
    int i,limit,ser,a[20];
    printf("Enter limit\n->");
    scanf("%d",&limit);
    printf("Enter elements of array\n->");
    for(i=0;i<limit;++i)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to search\n->");
    scanf("%d",&ser);
    for(i=0;i<limit;++i)
    {
        if(a[i]==ser)
        {
            printf("Element found at %d\n",i+1);
            break;
        }
    }
    if(i==limit)
        printf("Element not found\n");
    getch();
}
