//Selection Sort
#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,a[100],size,temp,max;
    printf("Enter size of array : ");
    scanf("%d",&size);
    printf("Enter elements of the array\n->");
    for(i=1;i<=size;++i)
    {
        scanf("%d",&a[i]);
    }
    //Sorting
    for(i=1;i<size;++i)
    {
        max = 1;
        for(j=1;j<=size-i;++j)
        {
            if(a[j+1]>a[max])
                max = j+1;
        }
        temp = a[max];
        a[max]=a[size-i+1];
        a[size-i+1]=temp;
    }
    printf("Sorted List : \n");
    for(i=1;i<=size;++i)
    {
        printf("%d ",a[i]);
    }
}
