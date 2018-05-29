#include<stdio.h>
#include<conio.h>
void main()
{
    int i,limit,ser,first,last,middle,a[20];
    printf("Enter limit\n->");
    scanf("%d",&limit);
    printf("Enter sorted elements of array\n->");
    for(i=0;i<limit;++i)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to search\n->");
    scanf("%d",&ser);
    first = a[0];
    last = a[limit-1];
    while(first<=last)
    {
        middle = (first + last)/2;
        if(a[middle]==ser)
        {
            printf("Element found at %d\n",middle+1);
            break;
        }
        else if(a[middle]<ser)
        {
            first=middle+1;
        }
        else
        {
            last=middle-1;
        }
    }
    if(first>last)
        printf("Element not found !!!\n");
    getch();
}
